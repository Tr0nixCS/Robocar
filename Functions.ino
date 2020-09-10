

void Follow_Wall() {
  servo.write(rightPos); //Setting sensor in a 45deg angle to the right side.
  
  if (sensor.read() >= 760) {
    Right();
  }
  else if (sensor.read() <= 740) {
    Left();
  }
  else {
    Forwards();
  }
}

void Bounce() {
  servo.write(centerPos);
  
  // Temporary Function
  Forwards();
  delay(500);
  Backwards();
  delay(500);

  /*
  if (sensor.read() > 400){
    Forwards();
  }
  else if (sensor.read() <= 400){
    Stop();
    delay(1000);
    int readCenter = sensor.read()
    
    servo.write(left);
    delay(1000);
    int readLeft = sensor.read()
    
    servo.write(right);
    delay(1000);
    int readRight = sensor.read()
  }
    if (readLeft < readCenter and readRight < readCenter) { // Corner
      RotRight();
      // Delay
    }
    if else (readRight > readLeft) { // Turn Right
      // Calculations
      // Function
      // Delay
    }
    if else (readLeft > readRight) { // Turn Left
      // Calculations
      // Function
      // Delay
    }
  */
}

void Standby() {
  Stop();
  servo.write(centerPos);
}
