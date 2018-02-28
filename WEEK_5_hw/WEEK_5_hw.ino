const int analogInPin = A0;
int sensorValue = 0;
const int LedPin = 11;
const int trigPin = 13; //naming a constant value / giving a variable name / #define acts as a find and replace
const int echoPin = 12;

void setup() {
  Serial.begin(9600);
  pinMode(LedPin, OUTPUT);
  pinMode(trigPin, OUTPUT); //trigPin is sending out the signal
  pinMode(echoPin, INPUT); //echoPin is retrieving information, therefore it is INPUT
  
}

void loop() {
    
   // read the sensor value from the analog input pin
  sensorValue = analogRead(analogInPin);
  // write the sensor value to serial
  Serial.println(sensorValue);
  // wait 2 milliseconds before the next loop
  delay(2);

  long duration, distance;
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1; //Time it took for the echo to be received and divided in half then divided by the speed of sound
  
  Serial.print(distance);
  Serial.println(" cm");
  delay(500); //delay half a second before repeating the loop

  if( distance < 20 && sensorValue<700){

    digitalWrite(LedPin, HIGH);
    
    
   }else{

      digitalWrite(LedPin, LOW);
    
    }
}

