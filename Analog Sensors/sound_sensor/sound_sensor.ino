/****************************************
Example Sound Level Sketch for the 
Microphone Amplifier
****************************************/

// Sample window width in mS (50 mS = 20Hz)
const int sampleWindow = 50; 
unsigned int sample;

int soundPin = A0;
double soundValue;

void setup() 
{
   pinMode(soundPin, INPUT);
   Serial.begin(9600);
}

void loop()
{
  soundValue = readSoundValue(soundPin) ;
  Serial.print("Raw Sensor Value = ");
  Serial.println(soundValue);
  delay(1000);
}

double readSoundValue(int soundPin) 
{
   unsigned long startMillis= millis();  // Start of sample window
   unsigned int peakToPeak = 0;   // peak-to-peak level

   unsigned int signalMax = 0;
   unsigned int signalMin = 1024;

   // collect data for 50 mS
   while (millis() - startMillis < sampleWindow)
   {
      sample = analogRead(soundPin);
      if (sample < 1024)  // toss out spurious readings
      {
         if (sample > signalMax)
         {
            signalMax = sample;  // save just the max levels
         }
         else if (sample < signalMin)
         {
            signalMin = sample;  // save just the min levels
         }
      }
   }
   peakToPeak = signalMax - signalMin;  // max - min = peak-peak amplitude
   double volts = (peakToPeak * 5.0) / 1024;  // convert to volts

  return volts;
}
