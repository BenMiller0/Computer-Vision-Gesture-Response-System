#include <Servo.h>
    
const int trigPin = 12;
const int echoPin = 13;
float duration, distance;


Servo myservo;  // create Servo object to control a servo

int potpin = A0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin
// int distanceLevel;


void setup() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    Serial.begin(9600);
    myservo.attach(9);  // attaches the servo on pin 9 to the Servo object
}

void loop() {
    digitalWrite(trigPin,LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration*.0343)/2;
    Serial.print("Distance: ");
    Serial.println(distance);
    delay(100);

    if(distance <= 30){
        val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
        val = map(val, 0, 1023, 0, 180);     // scale it for use with the servo (value between 0 and 180)
        myservo.write(val);                  // sets the servo position according to the scaled value
        delay(15);                           // waits for the servo to get there
    }
        
}