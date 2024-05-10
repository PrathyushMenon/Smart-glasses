# Smart Glasses

This Arduino project utilizes ultrasonic sensors to control vibration motors based on proximity readings. The system adjusts the frequency of scans or waves dynamically depending on the distance of detected objects.

## Overview

The system consists of ultrasonic sensors mounted on the left and right sides, and four motors for controlling movement. When an object is detected within a certain range (less than 1.5 meters), the frequency of scans or waves is increased, leading to more frequent adjustments in motor control. Conversely, when no objects are detected within the specified range, the frequency decreases, reducing the frequency of scans or waves and conserving energy.

## Features

- Utilizes ultrasonic sensors for distance measurement.
- Dynamically adjusts the frequency of scans or waves based on object proximity.
- Controls four motors to respond to detected objects.
- Adjustable short and long delay periods for customization.

## Setup and Configuration

### Hardware Requirements:

- Arduino board
- Ultrasonic sensors (4)
- Vibration Motors (4)
- Connecting wires
- Bread-board (if required)

### Installation:

1. Connect the ultrasonic sensors to the Arduino board according to the pin configurations defined in the code.
2. Connect the motors to the Arduino board using appropriate motor driver if required.
3. Upload the provided Arduino sketch to your Arduino board.

### Usage:

1. Ensure all connections are properly made.
2. Power on the Arduino board.
3. The system will start measuring distances using the ultrasonic sensors and adjusting motor control accordingly.

## Customization

- Adjust the `shortDelay` and `longDelay` variables in the code to change the delay periods for short and long distance readings respectively.
- Modify the mapping of distance to vibration intensity in the `calculateIntensity` function to suit your application's requirements.
