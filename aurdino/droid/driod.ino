#include <Servo.h>

const int ENA = 5; // Enable pin for motor driver
const int IN1 = 6; // Motor direction control pin 1
const int IN2 = 7; // Motor direction control pin 2

int speed = 150; // range from 0 (stop) to 255 (max speed)
Servo myservo;

void setup(){           
  pinMode(IN1, OUTPUT);   
  pinMode(IN2, OUTPUT); 
  pinMode(ENA, OUTPUT);
  myservo.attach(10, 500, 2400); // Adjusts the min/max range for smoother turning (pin 10)
}

void loop(){
  // --- Move in Circle ---
  forward(speed, 1);
  left(speed, 1, 45); // Turn left for 1 second
}

// Distance in feet
int distance_to_time(int distance) {
  // If car moves at 6 inch per second
  // therefore 0.5 ft per second
  int seconds = distance/0.5; //assumed
  return seconds*1000;
}

// 45 <= angle < 90
void left(int speed, int distance, int angle) {
  myservo.write(angle); // Turn wheels to the left
  forward(speed, distance);
  myservo.write(90); // Re-center the wheels
  stop();
}

// 90 < angle <= 135
void right(int speed, int distance, int angle) {
  myservo.write(angle); // Turn wheels to the right
  forward(speed, distance);
  myservo.write(90); // Re-center the wheels
  stop();
}

void forward(int speed, int distance){
  digitalWrite(IN1, HIGH); // Forward rotation high
  digitalWrite(IN2, LOW);
  analogWrite(ENA, speed);
  int time = distance_to_time(distance);
  delay(time);
}

// Distance in feet
void back(int speed, int distance){
  digitalWrite(IN1, LOW); 
  digitalWrite(IN2, HIGH); // Backward rotation high
  analogWrite(ENA, speed);
  int time = distance_to_time(distance);
  delay(time);
}

void stop(){
  digitalWrite(IN1, LOW); 
  digitalWrite(IN2, LOW);
}