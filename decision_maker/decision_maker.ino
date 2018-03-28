// Include the Servo library 
#include <Servo.h> 
// Declare the Servo pin 
int servoPin = 9; 
const int buttonPinRed = 10; 
int buttonStateRed = 0; 
 
// Create a servo object 
Servo Servo1; 
void setup() { 
   // We need to attach the servo to the used pin number 
   Servo1.attach(servoPin); 

   pinMode(buttonPinRed, INPUT);
   Serial.begin(9600);

}
void loop(){ 
 
  buttonStateRed = digitalRead(buttonPinRed);
   
    if (buttonStateRed == HIGH) {
       Servo1.write (180);
       delay(1000);
       int randNumber = random(1,4);
       Serial.println(randNumber); 

          if (randNumber == 1){
              yes(); 
          }if (randNumber == 2){
              maybe();
          }if (randNumber == 3){
              no();
          }
    }
}


void yes(){

   Servo1.write(0); 
   delay(1000); 
  
  }

 void maybe(){
   Servo1.write(45); 
   delay(1000); 
  }

  void no(){
    
   Servo1.write(90); 
   delay(1000);
  }

