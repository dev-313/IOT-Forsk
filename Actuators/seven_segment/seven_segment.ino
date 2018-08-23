/*
          -----   -----   -----   -----
         |     | |     | |     | |     |
         |_____| |_____| |_____| |_____|
         |     | |     | |     | |     |
         |     | |     | |     | |     |
          -----   -----   -----   -----
*/


 
#define DISPLAY_BRIGHTNESS  500     // set the brigthness of the led to half

int D1 = 11; //PWM Display pin 1
int D2 = 10; //PWM Display pin 2
int D3 = 9; //PWM Display pin 6
int D4 = 6; //PWM Display pin 8

int A = 12; //Display pin 14
int B = 3; //Display pin 16
int C = 4; //Display pin 13
int D = 5; //Display pin 3
int E = 2; //Display pin 5 
int F = 7; //Display pin 11
int G = 8; //Display pin 15

void setup() {                
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);

  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  
  pinMode(13, OUTPUT);
}

void loop() {
  // millis will return milli second since the program wil execute and at every call it will increase by one milli second ie. it will only return 1000,2000,3000
  // display number method is used to display number on 7 segment display

  displayNumber(millis()/1000); // for more info go to this link https://www.arduino.cc/en/Reference/Millis

}


void displayNumber(int toDisplay) {


  long beginTime = millis(); // variable to store the milli second 

  for(int digit = 4 ; digit > 0 ; digit--) // at starting the 4th digit will be high and after every position change the remaning digit will goes high in order 4-3-2-1 
  {

    //Turn on a digit for a short amount of time
    switch(digit) {
    case 1:
      digitalWrite(D1, HIGH);
      break;
    case 2:
      digitalWrite(D2, HIGH);
      break;
    case 3:
      digitalWrite(D3, HIGH);
      break;
    case 4:
      digitalWrite(D4, HIGH);
      break;
    }

    //Turn on the right segments for this digit
    lightNumber(toDisplay % 10); // printing the digits  on the right segment 
    toDisplay /= 10;    // Setting the value for the next digit

    delayMicroseconds(DISPLAY_BRIGHTNESS); //Display this digit for a fraction of a second (between 1us and 5000us, 500 is pretty good)

    //Turn off all segments
    lightNumber(10);  // calling the lightNumber function and passing 10 in the parameter will turn off all the segment as we have designed  case 10 in lightNumber function

    //Turn off all digits
    digitalWrite(D1, LOW);
    digitalWrite(D2, LOW);
    digitalWrite(D3, LOW);
    digitalWrite(D4, LOW);
  }

  while( (millis() - beginTime) < 10) ; //Wait for 20ms to pass before we paint the display again
}

//Given a number, turns on those segments
//If number == 10, then turn off number


void lightNumber(int numberToDisplay) // creating 0 to 10 number in 10 cases each case is holding 1 number 
{
  switch (numberToDisplay)
{
  case 0: // case for 0 number  
    digitalWrite (A,  LOW);    //     -----
    digitalWrite(B,  LOW);   //      |     |
     digitalWrite(C,  LOW);    //    |     |
     digitalWrite(D,  LOW);  //      |     | 
    digitalWrite(E,  LOW);   //      |     |
    digitalWrite(F,  LOW);  //        -----
    digitalWrite(G, HIGH);  //              
      break;                              
                                
  case 1: // case for 1 number 
    digitalWrite(A, HIGH);       //        |
    digitalWrite(B,  LOW);    //           |
    digitalWrite(C,  LOW);     //          |
     digitalWrite(D, HIGH); //             |
    digitalWrite(E, HIGH);  //
    digitalWrite(F, HIGH);   //
    digitalWrite(G, HIGH);
    break;

  case 2: // case for 2 number 
    digitalWrite(A,  LOW); //        -----
    digitalWrite(B,  LOW);//              |
    digitalWrite(C, HIGH);//              |
    digitalWrite(D,  LOW);//         -----
    digitalWrite(E,  LOW);//        |
    digitalWrite(F, HIGH);//        |
    digitalWrite(G,  LOW);//         -----
    break;

  case 3:   // case for 3 number
    digitalWrite(A,  LOW);//         -----
    digitalWrite(B,  LOW);//              |
    digitalWrite(C,  LOW);//              |
    digitalWrite(D,  LOW);//         -----
    digitalWrite(E, HIGH);//              |
    digitalWrite(F, HIGH);//              |
    digitalWrite(G,  LOW);//         -----
    break;

  case 4:     // case for 4 number
    digitalWrite(A, HIGH);//       |     |    
    digitalWrite(B,  LOW);//       |     |
    digitalWrite(C,  LOW);//        -----
    digitalWrite(D, HIGH);//             |
    digitalWrite(E, HIGH);//             |
    digitalWrite(F,  LOW);//
    digitalWrite(G,  LOW);//
    break;

  case 5: // case for 5 number 
    digitalWrite(A,  LOW);//          -----
    digitalWrite(B, HIGH);//         |
    digitalWrite(C,  LOW);//         |
    digitalWrite(D,  LOW);//          -----
    digitalWrite(E, HIGH);//               |
    digitalWrite(F,  LOW);//               |
    digitalWrite(G,  LOW);//          -----
    break;

  case 6:    // case for 6 number 
    digitalWrite(A,  LOW);//        |
    digitalWrite(B, HIGH);//        |
    digitalWrite(C,  LOW);//         -----
    digitalWrite(D,  LOW);//        |     | 
    digitalWrite(E,  LOW);//        |     |
    digitalWrite(F,  LOW);//         -----
    digitalWrite(G,  LOW);//
    break;

  case 7:     // case for 7 number
    digitalWrite(A,  LOW);//        -----
    digitalWrite(B,  LOW);//             |
    digitalWrite(C,  LOW);//             |
    digitalWrite(D, HIGH);//             |
    digitalWrite(E, HIGH);//             |
    digitalWrite(F, HIGH);//
    digitalWrite(G, HIGH);//
    break;

  case 8:      // case for 8 number
    digitalWrite(A,  LOW);//            -----
    digitalWrite(B,  LOW);//           |     |
    digitalWrite(C,  LOW);//           |     |
    digitalWrite(D,  LOW);//            -----
    digitalWrite(E,  LOW);//           |     |
    digitalWrite(F,  LOW);//           |     |
    digitalWrite(G,  LOW);//            -----
    break;

  case 9:     //case for 9 number 
    digitalWrite(A,  LOW);//           -----
    digitalWrite(B,  LOW);//          |     |
    digitalWrite(C,  LOW);//          |     |
    digitalWrite(D,  LOW);//           -----
    digitalWrite(E, HIGH);//                |
    digitalWrite(F,  LOW);///               |
    digitalWrite(G,  LOW);//
    break;

  case 10: // case for 10 number
    digitalWrite(A, HIGH);//
    digitalWrite(B, HIGH);//
    digitalWrite(C, HIGH);//
    digitalWrite(D, HIGH);//
    digitalWrite(E, HIGH);///
    digitalWrite(F, HIGH);//
    digitalWrite(G, HIGH);//
    break;
  }
}

