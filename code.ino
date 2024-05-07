// Define pins for left sensors
const int trigPinLeft1 = 9;
const int echoPinLeft1 = 10;
const int trigPinLeft2 = 11;
const int echoPinLeft2 = 12;

// Define pins for right sensors
const int trigPinRight1 = 4;
const int echoPinRight1 = 5;
const int trigPinRight2 = 6;
const int echoPinRight2 = 7;

// Define pins for motors
const int motorLeft1Pin = 3;
const int motorLeft2Pin = 4;
const int motorRight1Pin = 5;
const int motorRight2Pin = 6;

// Define vibration intensity limits
const int minIntensity = 50; // Minimum vibration intensity
const int maxIntensity = 255; // Maximum vibration intensity

// Variables for left sensors
long durationLeft1;
float distance_cmLeft1;
long durationLeft2;
float distance_cmLeft2;

// Variables for right sensors
long durationRight1;
float distance_cmRight1;
long durationRight2;
float distance_cmRight2;

void setup() {
  // Set up sensor pins
  pinMode(trigPinLeft1, OUTPUT);
  pinMode(echoPinLeft1, INPUT);
  pinMode(trigPinLeft2, OUTPUT);
  pinMode(echoPinLeft2, INPUT);
  pinMode(trigPinRight1, OUTPUT);
  pinMode(echoPinRight1, INPUT);
  pinMode(trigPinRight2, OUTPUT);
  pinMode(echoPinRight2, INPUT);

  // Set up motor pins
  pinMode(motorLeft1Pin, OUTPUT);
  pinMode(motorLeft2Pin, OUTPUT);
  pinMode(motorRight1Pin, OUTPUT);
  pinMode(motorRight2Pin, OUTPUT);

  Serial.begin(9600); // Start serial communication
}

void loop() {
  // Measure distances from all sensors
  measureDistances();

  // Control motors based on proximity readings
  controlMotors();

  // Delay for stability
  delay(100); // Adjust as necessary
}

void measureDistances() {
  // Measure distance from left sensors
  measureDistance(trigPinLeft1, echoPinLeft1, durationLeft1, distance_cmLeft1);
  measureDistance(trigPinLeft2, echoPinLeft2, durationLeft2, distance_cmLeft2);

  // Measure distance from right sensors
  measureDistance(trigPinRight1, echoPinRight1, durationRight1, distance_cmRight1);
  measureDistance(trigPinRight2, echoPinRight2, durationRight2, distance_cmRight2);
}

void controlMotors() {
  // Calculate vibration intensity for each motor
  int left1Intensity = calculateIntensity(distance_cmLeft1);
  int left2Intensity = calculateIntensity(distance_cmLeft2);
  int right1Intensity = calculateIntensity(distance_cmRight1);
  int right2Intensity = calculateIntensity(distance_cmRight2);

  // Control left motors
  analogWrite(motorLeft1Pin, left1Intensity);
  analogWrite(motorLeft2Pin, left2Intensity);

  // Control right motors
  analogWrite(motorRight1Pin, right1Intensity);
  analogWrite(motorRight2Pin, right2Intensity);
}

int calculateIntensity(float dist) {
  if (dist < 150) { // If distance is less than 1.5 meters
    // Map distance to vibration intensity (linear mapping)
    int intensity = map(dist, 0, 150, maxIntensity, minIntensity);
    return intensity;
  } else {
    return 0; // No vibration if distance is greater than 1.5 meters
  }
}

void measureDistance(int trigPin, int echoPin, long &duration, float &distance_cm) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance_cm = duration * 0.0343 / 2;
}
