const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

const int joyX = A0;
const int joyY = A1;
const int joyBtn = 2; // The click button on the stick

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(joyBtn, INPUT_PULLUP); // Use internal resistor for the button
}

void loop() {
  // 1. Map X-axis to Red
  int xVal = analogRead(joyX);
  int r = map(xVal, 0, 1023, 0, 255); // map function explained in the theory part
  
  // 2. Map Y-axis to Green
  int yVal = analogRead(joyY);
  int g = map(yVal, 0, 1023, 0, 255); // map function explained in the theory part

  // 3. Use the button to toggle Blue (Simple On/Off for now)
  int b = 0;
  if (digitalRead(joyBtn) == LOW) { // Button is pressed
    b = 255; 
  }

  // 4. Output the mixed color
  analogWrite(redPin, r);
  analogWrite(greenPin, g);
  analogWrite(bluePin, b);

  delay(10);
}
