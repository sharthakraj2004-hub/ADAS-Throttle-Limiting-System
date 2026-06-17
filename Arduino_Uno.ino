#include <Servo.h>

Servo throttleServo;

// Ultrasonic Sensor
const int trigPin = 9;
const int echoPin = 10;

// Potentiometer
const int potPin = A0;

// LEDs
const int led1 = 2;
const int led2 = 3;
const int led3 = 4;
const int led4 = 5;

// Servo
const int servoPin = 13;

long duration;
float distance;

int potValue;
int angle;

void setup()
{
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  throttleServo.attach(servoPin);

  Serial.println("=================================");
  Serial.println("THROTTLE BY WIRE + ADAS SYSTEM");
  Serial.println("=================================");
}

void loop()
{
  // Read Potentiometer
  potValue = analogRead(potPin);

  // Convert to Servo Angle
  int requestedAngle = map(potValue, 0, 1023, 0, 180);

  // Trigger Ultrasonic Sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, 30000);

  if(duration == 0)
  {
    Serial.println("No Echo Detected");
    delay(100);
    return;
  }

  distance = duration * 0.034 / 2.0;

  // Turn OFF all LEDs
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);

  // Default = Full Driver Control
  angle = requestedAngle;

  // ==========================
  // ADAS Distance Logic
  // ==========================

  if(distance > 30)
  {
    digitalWrite(led1, HIGH);

    angle = requestedAngle;

    Serial.println("SAFE DISTANCE - FULL THROTTLE");
  }

  else if(distance > 20)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);

    angle = requestedAngle / 2;

    Serial.println("CAUTION - THROTTLE LIMITED TO 50%");
  }

  else if(distance > 10)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);

    angle = requestedAngle / 3;

    Serial.println("WARNING - THROTTLE LIMITED TO 33%");
  }

  else
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);

    angle = requestedAngle / 4;

    Serial.println("EMERGENCY! THROTTLE LIMITED TO 25%");
  }

  // Safety Limits
  angle = constrain(angle, 0, 180);

  // Move Servo
  throttleServo.write(angle);

  // Serial Monitor Output
  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.print(" cm");

  Serial.print(" | Pot Value = ");
  Serial.print(potValue);

  Serial.print(" | Requested Angle = ");
  Serial.print(requestedAngle);

  Serial.print(" | Actual Servo Angle = ");
  Serial.println(angle);

  delay(100);
}
