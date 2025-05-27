#include <Servo.h>

const int trigPin = 2;
const int echoPin = 4;
const int servoPin = 6;

Servo myServo;

long duration;
int distance;
int angle = 0;
int direction = 1;  // 1 for increasing angle, -1 for decreasing

void setup() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    myServo.attach(servoPin);
    Serial.begin(9600);
}

void loop() {
    // Send ultrasonic pulse
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Read echo pulse duration
    duration = pulseIn(echoPin, HIGH);

    // Calculate distance in cm
    distance = duration * 0.034 / 2;

    // Constrain the distance to prevent weird values
    distance = constrain(distance, 5, 50);

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    if(distance < 50){
        // Map distance to delay
    int speedDelay = map(distance, 5, 50, 10, 200); // Closer to sensor = delay becomes 10ms; Farther away = delay up to 200ms

    // Update angle
    myServo.write(angle);
    angle += 5 * direction; // Increase or decrease angle by 5 degrees

    // Reverse direction
    if (angle >= 180 || angle <= 0) {
        direction *= -1; // Reverse direction
    }

    delay(speedDelay);
    }
}