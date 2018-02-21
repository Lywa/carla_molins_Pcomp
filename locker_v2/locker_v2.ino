/*
  Button

  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2.

  The circuit:
  - LED attached from pin 13 to ground
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  created 2005
  by DojoDave <http://www.0j0.org>
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Button
*/

// constants won't change. They're used here to set pin numbers:
const int buttonPinGreen = 4;     // the number of the pushbutton pin
const int buttonPinRed = 3; 
const int buttonPinBlue = 2; 
const int buttonPinYellow = 1; 
const int ledRed =  8;      // the number of the LED pin
const int ledGreen =  9;      // the number of the LED pin

// variables will change:
int buttonStateGreen = 0;         // variable for reading the pushbutton status
int buttonStateRed = 0; 
int buttonStateBlue = 0; 
int buttonStateYellow = 0; 
int buttonStateGreen2 = 1;         // variable for reading the pushbutton status
int buttonStateRed2 = 1; 
int buttonStateBlue2 = 1; 
int buttonStateYellow2 = 1; 

int counter=0;

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);

  // initialize the pushbutton pin as an input:
  pinMode(buttonPinGreen, INPUT);
  pinMode(buttonPinRed, INPUT);
  pinMode(buttonPinYellow, INPUT);
  pinMode(buttonPinBlue, INPUT);

  Serial.begin(9600);

}

void loop() {

  buttonStateGreen = digitalRead(buttonPinGreen);
  buttonStateRed = digitalRead(buttonPinRed);
  buttonStateYellow = digitalRead(buttonPinYellow);
  buttonStateBlue = digitalRead(buttonPinBlue);
  
  

  
  checkCombination();

}

 // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
void checkCombination(){


    if (buttonStateRed == HIGH && counter==0) {
    counter=1;
   
    
   // buttonStateRed2==LOW;
    Serial.println(counter);

    }
    // turn LED on
    /*/if ((buttonStateYellow == HIGH || buttonStateGreen == HIGH || buttonStateBlue== HIGH) && counter==0) {

     counter=0;
    Serial.println(counter);
  
    
   

    }*/
    if ((buttonStateYellow == LOW || buttonStateGreen == LOW || buttonStateBlue== LOW|| buttonStateRed== LOW) && counter==1) {

    counter=1;
    Serial.println(counter);
    
    }


   

    if(buttonStateBlue==HIGH && counter==1){
      
      counter=2;
      Serial.println(counter);
      
     }/*if ((buttonStateYellow == HIGH || buttonStateGreen == HIGH || buttonStateRed== HIGH) && counter==1) {

     counter=0;
      Serial.println(counter);
    
    }*/

    if ((buttonStateYellow == LOW || buttonStateGreen == LOW || buttonStateBlue== LOW|| buttonStateRed== LOW) && counter==2) {

    counter=2;
    Serial.println(counter);
    
    }

   

    if (buttonStateYellow==HIGH && counter==2){
      
      counter=3;
      Serial.println(counter);
      
    }/*if ((buttonStateRed == HIGH || buttonStateGreen == HIGH || buttonStateBlue== HIGH) && counter==2) {

    counter=0;
      Serial.println(counter);
    
    }*/

    
    if ((buttonStateYellow == LOW || buttonStateGreen == LOW || buttonStateBlue== LOW|| buttonStateRed== LOW) && counter==3) {

    counter=3;
    Serial.println(counter);
    
    }

  

     if (buttonStateGreen==HIGH && counter==3){
      
      counter=4;
      Serial.println(counter);
      
     }/*if ((buttonStateRed == HIGH || buttonStateBlue == HIGH || buttonStateYellow== HIGH) && counter==3) {

     counter=0;
      Serial.println(counter);


     
     }*/ if ((buttonStateYellow == LOW || buttonStateGreen == LOW || buttonStateBlue== LOW|| buttonStateRed== LOW) && counter==4) {

    counter=4;
    Serial.println(counter);
    
   

     } if (counter==4){
      
      digitalWrite(ledGreen, HIGH);
      digitalWrite(ledRed, LOW);

      delay(1000);
      digitalWrite(ledGreen, LOW);
      digitalWrite(ledRed, LOW);
      delay(1000); 
      digitalWrite(ledGreen, HIGH);
      digitalWrite(ledRed, LOW);
      delay(1000);
      
      digitalWrite(ledGreen, LOW);
      digitalWrite(ledRed, HIGH);
      counter=0;
      
   
      }

      if (counter<4){
      
      digitalWrite(ledGreen, LOW);
      digitalWrite(ledRed, HIGH);
   
      }

      
    
 }


      
  


/*void checkCombination(){


  buttonStateGreen = digitalRead(buttonPinGreen);
  buttonStateRed = digitalRead(buttonPinRed);
  buttonStateYellow = digitalRead(buttonPinYellow);
  buttonStateBlue = digitalRead(buttonPinBlue);
  buttonStateGreen2 = digitalRead(buttonPinGreen);
  buttonStateRed2 = digitalRead(buttonPinRed);
  buttonStateYellow2 = digitalRead(buttonPinYellow);
  buttonStateBlue2 = digitalRead(buttonPinBlue);
  
    // read the state of the pushbutton value:

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
     if (buttonStateRed == HIGH && buttonStateRed2==LOW) {
  
       counter++;
       buttonStateRed2== HIGH;
       delay(1000);
   
     }else if(buttonStateRed==LOW && buttonStateRed2==HIGH){

        if(buttonStateBlue==HIGH && buttonStateBlue2==LOW){
          
          counter++;
          buttonStateBlue2=HIGH;
          
        }else{
          counter=0;
        }

       

  
  }else{
    
    counter=0;

  }

  if (counter<2){

    digitalWrite(ledGreen, LOW);
    digitalWrite(ledRed, HIGH);
   
  }if(counter==2){

    digitalWrite(ledGreen, HIGH);
    digitalWrite(ledRed, LOW);
    
    }
  

  
}*

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
 /* if (buttonStateRed == HIGH) {
    counter++;
    Serial.println(counter);
    // turn LED on:
    delay(1000);
       if(buttonStateBlue == HIGH){
        counter++;
        Serial.println(counter);
          delay(1000);
          if(buttonStateYellow == HIGH){
          Serial.println(counter);
            delay(1000);

              if(buttonStateGreen==HIGH){
              counter++;
                 delay(1000);
              Serial.println(counter);
       
                
                }else{
                counter=0;
                delay(1000);
                }
              
            
           }else{
            
           counter=0;
               delay(1000);
          
           }
          
        
      }else{
         counter=0;
            delay(1000);
            
        }
        
   
  } else {
    counter=0;
     Serial.println(counter);
     
     delay(1000);
  }
  
  delay(1000);
  if (counter<=4){

    digitalWrite(ledGreen, LOW);
    digitalWrite(ledRed, HIGH);
    
   }if(counter==4){
    digitalWrite(ledGreen, HIGH);
    digitalWrite(ledRed, LOW);
    
    }

  delay(1000);
  
  }*/

  /*if (buttonStateRed == HIGH && counter==0) {
    counter=1;
   
    
   // buttonStateRed2==LOW;
    Serial.println(counter);
    // turn LED on
        if ((buttonStateYellow == HIGH || buttonStateGreen == HIGH || buttonStateBlue== HIGH) && counter==0) {

     counter=0;
    Serial.println(counter);
  
    }
   

    }if ((buttonStateYellow == LOW || buttonStateGreen == LOW || buttonStateBlue== LOW|| buttonStateRed== LOW) && counter==1) {

    counter=1;
    Serial.println(counter);
    
    }


    if(buttonStateBlue==HIGH && counter==1){
      
      counter=2;
      Serial.println(counter);
      
     }if ((buttonStateYellow == HIGH || buttonStateGreen == HIGH || buttonStateRed== HIGH) && counter==1) {

     counter=0;
      Serial.println(counter);
    
    }

    if ((buttonStateYellow == LOW || buttonStateGreen == LOW || buttonStateBlue== LOW|| buttonStateRed== LOW) && counter==2) {

    counter=2;
    Serial.println(counter);
    
    }

    if (buttonStateYellow==HIGH && counter==2){
      
      counter=3;
      Serial.println(counter);
      
    }if ((buttonStateRed == HIGH || buttonStateGreen == HIGH || buttonStateBlue== HIGH) && counter==2) {

    counter=0;
      Serial.println(counter);
    
    }

    
    if ((buttonStateYellow == LOW || buttonStateGreen == LOW || buttonStateBlue== LOW|| buttonStateRed== LOW) && counter==3) {

    counter=3;
    Serial.println(counter);
    
    }


     if (buttonStateGreen==HIGH && counter==3){
      
      counter=4;
      Serial.println(counter);
      
     }if ((buttonStateRed == HIGH || buttonStateBlue == HIGH || buttonStateYellow== HIGH) && counter==3) {

     counter=0;
      Serial.println(counter);


     
     } if ((buttonStateYellow == LOW || buttonStateGreen == LOW || buttonStateBlue== LOW|| buttonStateRed== LOW) && counter==4) {

    counter=4;
    Serial.println(counter);
    
   

     } if (counter==4){
      
      digitalWrite(ledGreen, HIGH);
      digitalWrite(ledRed, LOW);
   
      }

      if (counter<4){
      
      digitalWrite(ledGreen, LOW);
      digitalWrite(ledRed, HIGH);
   
      }

      
    
 }*/



