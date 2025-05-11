#include <NewPing.h>    // Import libraries
#include <LiquidCrystal.h>

// Pin Initialization
const int echo_L = 2;
const int trig_L = 3;
const int echo_M = 4;
const int trig_M = 5;
const int echo_R = 7;
const int trig_R = 8;
const int L1 = 6;
const int L2 = 9;
const int R1 = 10;
const int R2 = 11;
const int button = 12;
const int pump = 13;
const int ENA = 10;  // D10
const int ENB = A2;  // A2
int motor_speed = 255;
int max_distance = 200;
int distance_L = 0;
int distance_M = 0;
int distance_R = 0;
char incomingByte;

NewPing sonar_L(trig_L, echo_L, max_distance);
NewPing sonar_M(trig_M, echo_M, max_distance);
NewPing sonar_R(trig_R, echo_R, max_distance);

void setup() {
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(button, INPUT);
  pinMode(pump, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  analogWrite(ENA, motor_speed);  // setează viteza implicită
  analogWrite(ENB, motor_speed);
  digitalWrite(L1, LOW); 
  digitalWrite(L2, LOW);
  digitalWrite(R1, LOW);
  digitalWrite(R2, LOW);
  digitalWrite(pump, LOW);
  Serial.begin(9600);  // Begin serial communication at 9600 baud rate
  delay(2000);
}

void loop() {
  distance_L = readSensor_L();
  distance_M = readSensor_M();
  distance_R = readSensor_R();
  
  Serial.print("L=");
  Serial.print(distance_L);
  Serial.print("cm M=");
  Serial.print(distance_M);
  Serial.print("cm R=");
  Serial.print(distance_R);
  Serial.println("cm");

  if (distance_M <= 20) {
    // Obstacle detection logic
    if (distance_R > distance_L) {
      if ((distance_R <= 20) && (distance_L <= 20)) {
        moveStop();
        delay(200);
        moveBackward();
        delay(2000);
      } else {
        moveBackward();
        delay(500);
        moveRight();
        delay(2000);
      }
    } else {
      if ((distance_R <= 20) && (distance_L <= 20)) {
        moveStop();
        delay(200);
        moveBackward();
        delay(2000);
      } else {
        moveBackward();
        delay(500);
        moveLeft();
        delay(2000);
      }
    }
  } else if (distance_R <= 15) {
    moveLeft();
    delay(500);
  } else if (distance_L <= 15) {
    moveRight();
    delay(500);
  } else {
    moveForward();
  }
}

int readSensor_L() {
  delay(70);
  int cm_L = sonar_L.ping_cm();
  if (cm_L == 0) {
    cm_L = 250;
  }
  return cm_L;
}

int readSensor_M() {
  delay(70);
  int cm_M = sonar_M.ping_cm();
  if (cm_M == 0) {
    cm_M = 250;
  }
  return cm_M;
}

int readSensor_R() {
  delay(70);
  int cm_R = sonar_R.ping_cm();
  if (cm_R == 0) {
    cm_R = 250;
  }
  return cm_R;
}

void moveForward() {
  digitalWrite(L1, LOW); 
  analogWrite(L2, motor_speed);
  analogWrite(R1, motor_speed);
  digitalWrite(R2, LOW);
}

void moveBackward() {
  analogWrite(L1, motor_speed); 
  digitalWrite(L2, LOW);
  digitalWrite(R1, LOW);
  analogWrite(R2, motor_speed);
}

void moveLeft() {
  analogWrite(L1, motor_speed); 
  digitalWrite(L2, LOW);
  analogWrite(R1, motor_speed);
  digitalWrite(R2, LOW);
}

void moveRight() {
  digitalWrite(L1, LOW); 
  analogWrite(L2, motor_speed);
  digitalWrite(R1, LOW);
  analogWrite(R2, motor_speed);
}

void moveStop() {
  digitalWrite(L1, LOW); 
  digitalWrite(L2, LOW);
  digitalWrite(R1, LOW);
  digitalWrite(R2, LOW);
}
