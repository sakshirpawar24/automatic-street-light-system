
// Automatic Street Light System Using Arduino
// Sample implementation based on the project synopsis

const int LDR_PIN = A0;
const int IR_PIN = 2;
const int LIGHT_PIN = 9;

// Adjust this threshold after testing your LDR circuit
const int DARK_THRESHOLD = 500;

// Many IR modules give LOW when motion/object is detected.
// Change to HIGH if your module works the opposite way.
const int MOTION_DETECTED = LOW;

void setup() {
  pinMode(IR_PIN, INPUT);
  pinMode(LIGHT_PIN, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int lightValue = analogRead(LDR_PIN);
  int irValue = digitalRead(IR_PIN);

  bool isDark = lightValue < DARK_THRESHOLD;
  bool motionDetected = (irValue == MOTION_DETECTED);

  if (isDark && motionDetected) {
    digitalWrite(LIGHT_PIN, HIGH);
    Serial.println("Street Light: ON");
  } else {
    digitalWrite(LIGHT_PIN, LOW);
    Serial.println("Street Light: OFF");
  }

  Serial.print("LDR Value: ");
  Serial.println(lightValue);

  delay(500);
}
