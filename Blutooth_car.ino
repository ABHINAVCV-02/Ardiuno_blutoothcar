#include <AFMotor.h>
#include <SoftwareSerial.h>

// Define Bluetooth module pins
#define RX_PIN 2
#define TX_PIN 3

// Create a SoftwareSerial object to communicate with Bluetooth module
SoftwareSerial bluetooth(RX_PIN, TX_PIN); // RX, TX

// Create motor objects
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);
  
  // Initialize communication with Bluetooth module
  bluetooth.begin(9600);
}

void loop() {
  if (bluetooth.available() > 0) {
    char command = bluetooth.read();
    executeCommand(command);
  }
}

void executeCommand(char command) {
  switch (command) {
    case 'F':
      moveForward();
      break;
    case 'B':
      moveBackward();
      break;
    case 'L':
      turnLeft();
      break;
    case 'R':
      turnRight();
      break;
    case 'S':
      stopMoving();
      break;
    default:
      break;
  }
}

void moveForward() {
  motor1.setSpeed(255);
  motor1.run(FORWARD);
  motor2.setSpeed(255);
  motor2.run(FORWARD);
  motor3.setSpeed(255);
  motor3.run(FORWARD);
  motor4.setSpeed(
