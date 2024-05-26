// Define pins for Ultrasonic Sensor
#define trigPin 9
#define echoPin 10

// Define pins for IR Sensor
#define irSensorPin 2

// Define pin for Buzzer
#define buzzerPin 3

// Define distance threshold for a full bin (in centimeters)
#define distanceThreshold 10

// Variables to store the sensor readings
long duration;
int distance;

void setup() {
  // Initialize the Serial Monitor
  Serial.begin(9600);

  // Set pin modes for Ultrasonic Sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Set pin mode for IR Sensor
  pinMode(irSensorPin, INPUT);

  // Set pin mode for Buzzer
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Read distance from Ultrasonic Sensor
  distance = readUltrasonicDistance();

  // Print distance to the Serial Monitor (for debugging)
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Check if the bin is full
  if (distance <= distanceThreshold) {
    // If the bin is full, activate the buzzer
    digitalWrite(buzzerPin, HIGH);
  } else {
    // Otherwise, deactivate the buzzer
    digitalWrite(buzzerPin, LOW);
  }

  // Small delay before the next loop
  delay(500);
}

int readUltrasonicDistance() {
  // Send a 10us pulse to trigger the Ultrasonic Sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the duration of the echo pulse
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in cm
  distance = duration * 0.034 / 2;

  return distance;
}
