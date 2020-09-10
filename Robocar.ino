

// SysState
int SysState = 0;

// Motors
#define LeftF 3 // SG
#define LeftB 5 // BB
#define RightF 6 // G
#define RightB 11 // YY

// Servo
#include <Servo.h>
Servo servo;
int leftPos = 115;
int centerPos = 75;
int rightPos = 35;
int readLeft = 0;
int readCenter = 0;
int readRight = 0;

// Sensor
#include <Wire.h>
#include <VL53L1X.h>
VL53L1X sensor;


void setup() {
  // Motors
  pinMode (LeftF, OUTPUT);
  pinMode (LeftB, OUTPUT);
  pinMode (RightF, OUTPUT);
  pinMode (RightB, OUTPUT);

  // Servo
  servo.attach(9);

  // Sensor
  Serial.begin(115200);
  Wire.begin();
  Wire.setClock(400000);
  sensor.setTimeout(500);
  if (!sensor.init()){
    Serial.println("Failed to detect and initialize sensor!");
    while (1);
  }
  sensor.setDistanceMode(VL53L1X::Long);
  sensor.setMeasurementTimingBudget(50000);
  sensor.startContinuous(50);
}


void loop() {
  GatewayStatemachine();
  delay(5);
  switch (SysState) {
    case 0: // Standby
      Standby();
      delay(5);
      break;
    case 1: // Following a wall
      Follow_Wall();
      delay(5);
      break;
    case 2: // Bouncing around a room
      Bounce();
      delay(5);
      break;
    case 3: // Manual control through gateway?
      servo.write(centerPos);
      GatewayStatemachine();
      delay(5);
      break;
  }
}
