# Ultrasonic Radar System

An Arduino-based radar system that detects nearby objects using an HC-SR04 ultrasonic sensor and visualizes them in real time using Processing 4.

## Features

- Real-time object detection
- Radar-style visualization
- Distance measurement
- OLED display output
- Audible buzzer alerts
- Servo-based scanning

## Components Used

| Component | Quantity |
|------------|----------|
| Arduino Uno | 1 |
| HC-SR04 Ultrasonic Sensor | 1 |
| Servo Motor | 1 |
| 0.96" I2C OLED Display | 1 |
| Piezo Buzzer | 1 |
| Breadboard | 1 |
| Jumper Wires | Several |

## Software

- Arduino IDE
- Processing 4

## Working Principle

The servo motor rotates the ultrasonic sensor from side to side. The HC-SR04 measures the distance to nearby objects and sends the data to the Arduino. The information is displayed on the OLED screen and transmitted to Processing 4, where a radar-style graphical interface visualizes the detected objects. The buzzer activates when an object is detected within a specified range.

## Project Setup

1. Connect all components according to the circuit diagram.
2. Upload the Arduino sketch.
3. Open the Processing code.
4. Select the correct COM port.
5. Run the Processing sketch.
6. Observe real-time radar visualization.

## Circuit Diagram

Add your circuit image here.

## Demonstration

Add screenshots and videos here.

## Future Improvements

- Longer-range sensors
- Wireless communication
- Object tracking
- Data logging

## Author

Md Fahim Shahriar
