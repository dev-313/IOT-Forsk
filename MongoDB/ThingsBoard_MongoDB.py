import json
import urllib2
from datetime import datetime
from pymongo import MongoClient
import paho.mqtt.client as mqtt


# Name of the MQTT Broker
Broker = "demo.thingsboard.io"

# Receive messages on this topic
#sub_topic = "v1/devices/me/attributes/response/+"
sub_topic = "v1/devices/me/telemetry"

# Access Token of Thingsboard for Authentication
Acces_token = "eBX25oxdBI1Ren1Zllu3"

# Creating Object for MongoDB Instance
mongo_client = MongoClient('localhost', 27017)

# Initializing Database (ThingsBoard) and creating its object
my_db = mongo_client.ThingsBoard
my_db.drop_collection("Data")  # Deleting any Previous Collection(Data)

# Credentials for SMS service
sms_ph_number = "7976759710"    # Number to send SMS alert to

# range for Temperature 
temp_uppr_limit = 40
temp_lowr_limit = 5


############## Data To MongoDB Section ##############

def data_to_mongo(data):
    try:    
        # Insert JSON data to collection (Data) in ThingsBoard Database
        my_db.Data.insert_one(data)
        return "Data Added to MongoDB"
    
    except Exception as e:
        return "ERROR :",str(e)  # Returns Error if any
    

############## SMS Section ##############

def sms(number,temp): 

    # Alert Message to be sent
    message = "SMS ALERT Room Temperature is {0}C".format(temp)
    message = "+".join(message.split(' '))

    # Adding number and message to SMS url.(P.S. rest all the attributes remains same as per service provider)
    url ='http://sms.dataoxytech.com/index.php/smsapi/httpapi/?uname=sylvester007&password=forskmnit&sender=FORSKT&receiver={0}&route=TA&msgtype=1&sms={1}'.format(number,message)

    try:
        send_sms = urllib2.urlopen(url)  # Hitting the SMS url
    except Exception as e:
        return "Error:",str(e)
    return send_sms.read() # Returns SMS Response


############## MQTT section ##################

# The callback for when the client receives a CONNACK response from the server.
def on_connect(client, userdata, rc, *extra_params):
    
    print('Connected with result code '+str(rc))
    
    client.publish('v1/devices/me/attributes/request/1', "{}", 1)
    
    # Subscribing in on_connect() means that if we lose the connection and
    # reconnect then subscriptions will be renewed.
    client.subscribe(sub_topic)


# The callback for when a PUBLISH message is received from the server.
def on_message(client, userdata, msg):
    
    print("Message received on topic "+msg.topic+" with QoS "+str(msg.qos)+" and payload "+msg.payload)
    
    # Getting Data from the msg Payload
    user = json.loads(msg.payload)
    user_data = user["client"]
    
    # Adding Timestamp Field in the user data
    user_data["Timestamp"] = datetime.now()
    
    print data_to_mongo(user_data)   # Adding Data to MongoDB
    
    # Geting Temperature and checking if it is in the Safe Zone
    temp = float(user_data["temperature"])
    
    if not(temp_lowr_limit < temp < temp_uppr_limit):
        print sms(sms_ph_number, temp)   # Send SMS if Temp not in safe zone
    else:
        print "Temperature and Humidity are under control"


################## MQTT Registeration section ##################
        
mqttclient = mqtt.Client()

# Assign event callbacks
mqttclient.on_connect = on_connect
mqttclient.on_message = on_message

# Connect
mqttclient.username_pw_set(Acces_token)
mqttclient.connect(Broker, 1883,1)

# Loops MQTT Client
mqttclient.loop_forever()
