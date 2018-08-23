/*
DIGITAL ACTUATOR CHECK FOR PIEZO BUZZER

Connect the - of the PIEZO  to GND on the Arduino
Connect the +  of the PIEZO  to Digital Pin 12 on the Arduino 
*/

int speakerPin= 12; 	

int numTones = 10;
int tones[] = {261, 277, 294, 311, 330, 349, 370, 392, 415, 440};
//            mid C  C#   D    D#   E    F    F#   G    G#   A


/*
This function is called only once in lifetime
Will be called again when the RED RESET button is pressed on the Arduino
*/
void setup()
{
  for (int i = 0; i < numTones; i++)
  {
    tone(speakerPin, tones[i]);
    delay(500);
  }
  noTone(speakerPin);
}

/*
This function is called in a loop again and again by Arduino infinitely 
untill the RED RESET button is not pressed
*/
void loop()
{
 
} 


