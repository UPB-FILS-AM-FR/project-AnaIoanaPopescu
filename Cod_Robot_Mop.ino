#include <Arduino.h>

// Senzor frontal
#define trigPin1 A1
#define echoPin1 A2

// Senzor lateral
#define trigPin2 3
#define echoPin2 2
#define releuPin 7  // Sau alt pin digital liber


// Motoare (prin L293N)
const int ENA = 5;
const int ENB = 6;
const int IN1 = 9;
const int IN2 = 8;
const int IN3 = 10;
const int IN4 = 11;

int motor_speed = 200;
long duration1, duration2;
int distance1, distance2;

int readDistance1();
int readDistance2();
void moveForward();
void moveBackward();
void stopMotors();

void setup() {
  Serial.begin(9600);

  // Senzor 1
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);

  // Senzor 2
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  // Motoare
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(releuPin, OUTPUT);
  digitalWrite(releuPin, HIGH); // Releu inactiv la pornire (activ LOW)


  stopMotors();
}

void loop() {
  distance1 = readDistance1();  // Față
  distance2 = readDistance2();  // Lateral

  Serial.print("Fata: ");
  Serial.print(distance1);
  Serial.print(" cm | Lateral: ");
  Serial.print(distance2);
  Serial.println(" cm");

  if (distance1 <= 20 || distance2 <= 20) {
    digitalWrite(releuPin, LOW);  // Releu activat = bec verde aprins
    moveBackward();
    delay(2000);
    stopMotors();
    digitalWrite(releuPin, HIGH); // Releu oprit
  } else {
    digitalWrite(releuPin, HIGH); // Asigură-te că e oprit în mod normal
    moveForward();
  }

  delay(300);
}

int readDistance1() {
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);

  duration1 = pulseIn(echoPin1, HIGH);
  int dist_cm = duration1 * 0.034 / 2;
  if (dist_cm == 0) return 250;
  return dist_cm;
}

int readDistance2() {
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);

  duration2 = pulseIn(echoPin2, HIGH);
  int dist_cm = duration2 * 0.034 / 2;
  if (dist_cm == 0) return 250;
  return dist_cm;
}

// Funcții motoare
void moveForward() {
  analogWrite(ENA, motor_speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENB, motor_speed);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}


void moveBackward() {
  analogWrite(ENA, motor_speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENB, motor_speed);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}


void stopMotors() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
