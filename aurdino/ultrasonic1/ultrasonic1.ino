#include <Servo.h>

const int trigPin = 2;
const int echoPin = 4;
const int servoPin = 6;

Servo myServo;

long duration;
int distance;
int angle = 0;
int direction = 1;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myServo.attach(servoPin);
  Serial.begin(9600);
}

void loop() {
  // Trigger ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo time and convert to distance
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  distance = constrain(distance, 5, 100); // Cap max to avoid noise

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < 100) {
    // Fast gitter motion
    myServo.write(angle);
    angle += 1 * direction; // Quick jump

    if (angle >= 180 || angle <= 0) {
      direction *= -1;
    }

    delay(10); // Gitter speed
  }
}
