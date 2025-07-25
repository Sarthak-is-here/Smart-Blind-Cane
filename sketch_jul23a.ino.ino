// Pin definitions
#define TRIG_PIN_1 13
#define ECHO_PIN_1 12
#define TRIG_PIN_2 10
#define ECHO_PIN_2 9
#define BUZZER_PIN 7

void setup() {
  Serial.begin(9600);

  pinMode(TRIG_PIN_1, OUTPUT);
  pinMode(ECHO_PIN_1, INPUT);
  pinMode(TRIG_PIN_2, OUTPUT);
  pinMode(ECHO_PIN_2, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

long getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH, 30000); // Timeout 30ms
  if (duration == 0) return -1;
  return duration * 0.034 / 2;
}

void beepBuzzer(int pattern) {
  if (pattern == 0) {
    digitalWrite(BUZZER_PIN, LOW);  // Off
  } else if (pattern == 1) {
    digitalWrite(BUZZER_PIN, HIGH);
    delay(300);
    digitalWrite(BUZZER_PIN, LOW);
    delay(300);
  } else if (pattern == 2) {
    digitalWrite(BUZZER_PIN, HIGH);
    delay(100);
    digitalWrite(BUZZER_PIN, LOW);
    delay(100);
  } else if (pattern == 3) {
    digitalWrite(BUZZER_PIN, HIGH); // Continuous
  }
}

void loop() {
  long distance1 = getDistance(TRIG_PIN_1, ECHO_PIN_1);
  delay(50);
  long distance2 = getDistance(TRIG_PIN_2, ECHO_PIN_2);

  Serial.print("Sensor 1: ");
  Serial.print((distance1 == -1) ? "Out of range" : String(distance1) + " cm");
  Serial.print("\tSensor 2: ");
  Serial.println((distance2 == -1) ? "Out of range" : String(distance2) + " cm");

  long nearest = -1;
  if (distance1 != -1 && distance2 != -1) {
    nearest = min(distance1, distance2);
  } else if (distance1 != -1) {
    nearest = distance1;
  } else if (distance2 != -1) {
    nearest = distance2;
  }

  if (nearest == -1 || nearest > 50) {
    beepBuzzer(0);  // Off
    delay(100);
  } else if (nearest > 20) {
    beepBuzzer(1);  // Slow beep
  } else if (nearest > 10) {
    beepBuzzer(2);  // Fast beep
  } else {
    beepBuzzer(3);  // Continuous
  }

  delay(50);
}
