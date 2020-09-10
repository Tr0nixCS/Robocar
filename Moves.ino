

void Forwards() {
  analogWrite (LeftF, 255);
  analogWrite (LeftB, LOW);
  analogWrite (RightF, 255);
  analogWrite (RightB, LOW);
}

void Backwards() {
  analogWrite (LeftF, LOW);
  analogWrite (LeftB, 200);
  analogWrite (RightF, LOW);
  analogWrite (RightB, 200);
}

void Left() {
  analogWrite (LeftF, LOW);
  analogWrite (LeftB, LOW);
  analogWrite (RightF, 200);
  analogWrite (RightB, LOW);
}

void Right() {
  analogWrite (LeftF, 200);
  analogWrite (LeftB, LOW);
  analogWrite (RightF, LOW);
  analogWrite (RightB, LOW);
}

void RotLeft() {
  analogWrite (LeftF, LOW);
  analogWrite (LeftB, 200);
  analogWrite (RightF, 200);
  analogWrite (RightB, LOW);
}

void RotRight() {
  analogWrite (LeftF, 200);
  analogWrite (LeftB, LOW);
  analogWrite (RightF, LOW);
  analogWrite (RightB, 200);
}

void Stop() {
  analogWrite (LeftF, LOW);
  analogWrite (LeftB, LOW);
  analogWrite (RightF, LOW);
  analogWrite (RightB, LOW);
}
