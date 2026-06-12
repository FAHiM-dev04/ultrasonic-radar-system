#include <Servo.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

const int trigPin = 10;
const int echoPin = 11;
const int buzzerPin = 8;
const int servoPin = 12;

const int obstacleDistance = 40; // cm

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define OLED_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

long duration;
int distance;

Servo myServo;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

  Serial.begin(9600);
  myServo.attach(servoPin);

  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS)) {
    while (true); // stop if OLED is not found
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Radar Starting...");
  display.display();
  delay(1000);
}

void loop() {
  for (int i = 15; i <= 165; i++) {
    scanAndDisplay(i);
  }

  for (int i = 165; i > 15; i--) {
    scanAndDisplay(i);
  }
}

void scanAndDisplay(int angle) {
  myServo.write(angle);
  delay(30);

  distance = calculateDistance();

  checkBuzzer(distance);
  showOnOLED(angle, distance);

  Serial.print(angle);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
}

int calculateDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, 30000);

  if (duration == 0) {
    return 999;
  }

  distance = duration * 0.034 / 2;
  return distance;
}

void checkBuzzer(int distance) {
  if (distance > 0 && distance <= obstacleDistance) {
    tone(buzzerPin, 1000);
  } else {
    noTone(buzzerPin);
  }
}

void showOnOLED(int angle, int distance) {
  display.clearDisplay();

  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Ultrasonic Radar");

  display.setTextSize(2);
  display.setCursor(0, 18);
  display.print("A:");
  display.print(angle);
  display.println(" deg");

  display.setCursor(0, 42);
  display.print("D:");

  if (distance >= 999) {
    display.print("---");
  } else {
    display.print(distance);
  }

  display.println(" cm");

  display.display();
}