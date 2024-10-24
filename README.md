# ParkingAssistantSystem
The Parking Assistant System helps drivers park their vehicles safely by providing real-time feedback about the distance between the car and obstacles. The system uses an ultrasonic sensor to measure the distance to nearby objects and provides feedback via LEDs and a buzzer. The system can help drivers avoid collisions while parking.

Components Used
Arduino (e.g., Arduino Uno)
HC-SR04 Ultrasonic Sensor: Measures the distance to obstacles.
3 LEDs:
Green LED: Indicates a safe distance.
Yellow LED: Warns the driver when the car is getting close to an obstacle.
Red LED: Signals the driver to stop immediately.
Buzzer: Provides an audible warning when the car is too close to an obstacle.
LCD Display (optional): Displays the real-time distance from the obstacle.

How It Works
The ultrasonic sensor continuously measures the distance to nearby objects.
Based on the measured distance, the system turns on the corresponding LED:
Green for a safe distance,
Yellow for a warning zone,
Red for a danger zone.
If the car gets too close to the obstacle (less than 30 cm), the buzzer sounds to alert the driver.
