# SMART DUSTBIN – INDUSTRY-ORIENTED EMBEDDED SYSTEM

## Virtual Simulation Based Project Report

### Submitted By

**Sameeksha Sharma**

**Program:** B.Tech – Computer Science & Engineering
**Project Domain:** Embedded Systems
**Microcontroller:** Arduino UNO
**Simulation Platform:** Wokwi
**Programming Language:** Arduino C/C++

---

# 1. Abstract

The **Smart Dustbin – Industry-Oriented Embedded System** is an embedded automation project designed to provide contactless dustbin operation and automatic garbage-level monitoring.

The system is developed and tested virtually using the **Wokwi electronics simulator**. An Arduino UNO acts as the central controller. Two HC-SR04 ultrasonic sensors are used for separate purposes. The first sensor detects an approaching person or object and triggers a servo motor to automatically open the dustbin lid. The second ultrasonic sensor measures the distance between the top of the dustbin and the garbage surface to estimate the current garbage fill level.

The estimated fill level is converted into a percentage and classified into different states: **EMPTY, LOW, MEDIUM, HIGH, and FULL**. LEDs provide visual status information, while a buzzer provides an alert when the bin reaches the FULL state.

The virtual implementation allows the complete system logic, sensor interfacing, actuator control, and status indication to be tested without requiring physical hardware. This makes the project useful for understanding microcontroller programming, sensor integration, automation, debugging, and embedded-system testing.

---

# 2. Introduction

Embedded systems combine hardware and software to perform a dedicated task.

The Smart Dustbin project demonstrates this concept through a small automated waste-management system.

Traditional dustbins generally require users to manually open the lid and visually inspect the amount of garbage present. This project introduces automation by allowing the dustbin to:

* Detect an approaching object.
* Automatically open its lid.
* Automatically close the lid after a predefined period.
* Measure garbage level.
* Display the current status using LEDs.
* Generate an alert when the bin becomes full.

The project is initially implemented virtually using Wokwi so that the complete embedded logic can be tested before transferring the design to physical hardware.

---

# 3. Problem Statement

Conventional dustbins have several limitations:

1. The user must physically touch the lid.
2. There is no automatic indication of garbage level.
3. The user cannot easily determine whether the bin is nearly full.
4. Manual inspection is required for waste collection.
5. Traditional systems provide little scope for remote or automated monitoring.

The objective of this project is to develop a low-cost embedded system that addresses these limitations through sensors, a microcontroller, and an actuator.

---

# 4. Objectives

The main objectives of the project are:

* To design a contactless automatic dustbin.
* To interface ultrasonic sensors with a microcontroller.
* To control a servo motor using the Arduino UNO.
* To measure garbage level using ultrasonic distance measurement.
* To calculate the approximate fill percentage.
* To classify the bin into different fill-level states.
* To provide visual and audio alerts.
* To test the complete system using virtual simulation.
* To demonstrate embedded-system concepts in a practical application.
* To create a foundation for future IoT-based waste-management systems.

---

# 5. Industry Relevance

Although the current project is an educational prototype, its architecture demonstrates concepts relevant to real embedded products.

The project involves:

* Sensor interfacing
* GPIO programming
* Actuator control
* Timing
* Event detection
* Embedded software logic
* Fault handling
* Status indication
* Functional testing
* Simulation
* Version control
* Technical documentation

A similar concept could be extended to smart waste-management systems in:

* Schools and colleges
* Offices
* Hospitals
* Public buildings
* Smart cities
* Industrial facilities
* Residential complexes

The Arduino-based prototype can also be upgraded to an ESP32-based system for wireless communication and remote monitoring.

---

# 6. System Requirements

## 6.1 Hardware Components Used in Simulation

| Component                 | Quantity | Purpose                       |
| ------------------------- | -------: | ----------------------------- |
| Arduino UNO               |        1 | Main controller               |
| HC-SR04 Ultrasonic Sensor |        2 | Proximity and level detection |
| Servo Motor               |        1 | Automatic lid control         |
| Green LED                 |        1 | Normal/low-level indication   |
| Yellow LED                |        1 | Medium/high-level indication  |
| Red LED                   |        1 | Full-bin indication           |
| Buzzer                    |        1 | Full-bin warning              |

## 6.2 Software Requirements

The virtual implementation requires:

* Wokwi
* Arduino-compatible source code
* Web browser
* Git/GitHub for project version control

---

# 7. Simulation Platform

The project was designed for virtual implementation using **Wokwi**.

Wokwi provides a browser-based environment for simulating microcontrollers and electronic components.

The simulation allows the project to be tested without physical hardware.

The virtual system contains:

```text
Arduino UNO
     │
     ├── HC-SR04 #1
     ├── HC-SR04 #2
     ├── Servo Motor
     ├── Green LED
     ├── Yellow LED
     ├── Red LED
     └── Buzzer
```

The simulated ultrasonic sensor distance can be changed to represent different real-world conditions.

---

# 8. System Architecture

The overall system architecture is:

```text
                    SMART DUSTBIN
                         │
          ┌──────────────┴──────────────┐
          │                             │
          ▼                             ▼
   HC-SR04 Sensor #1             HC-SR04 Sensor #2
   Proximity Detection            Garbage Level
          │                             │
          └──────────────┬──────────────┘
                         │
                         ▼
                  ┌─────────────┐
                  │ Arduino UNO │
                  │             │
                  │ Processing  │
                  │ & Control   │
                  └──────┬──────┘
                         │
              ┌──────────┼──────────┐
              │          │          │
              ▼          ▼          ▼
           Servo       LEDs       Buzzer
              │
              ▼
          Dustbin Lid
```

---

# 9. Pin Configuration

The following pin configuration was used for the virtual simulation.

| Arduino Pin | Component       | Function           |
| ----------- | --------------- | ------------------ |
| D2          | HC-SR04 #1 TRIG | Proximity trigger  |
| D3          | HC-SR04 #1 ECHO | Proximity echo     |
| D4          | HC-SR04 #2 TRIG | Level trigger      |
| D5          | HC-SR04 #2 ECHO | Level echo         |
| D6          | Servo Signal    | Lid control        |
| D7          | Green LED       | Normal/low status  |
| D8          | Yellow LED      | Medium/high status |
| D9          | Red LED         | Full status        |
| D10         | Buzzer          | Full-bin alert     |

Power connections:

```text
HC-SR04 VCC → 5V
HC-SR04 GND → GND

Servo VCC → 5V
Servo GND → GND

LED cathodes → GND
Buzzer GND → GND
```

---

# 10. Working Principle

The system operates through two independent sensing functions.

## 10.1 Proximity Detection

HC-SR04 Sensor #1 is responsible for detecting an approaching object.

When the simulated distance becomes less than or equal to the configured detection threshold:

```text
Distance ≤ 20 cm
```

the Arduino interprets this as an object being present.

The controller then commands the servo to open the lid.

---

# 11. Automatic Lid Control

The servo is connected to Arduino digital pin D6.

The software controls the servo position.

```text
Servo Position = 0°
       ↓
Lid CLOSED
```

and:

```text
Servo Position = 90°
       ↓
Lid OPEN
```

The operating sequence is:

```text
Object detected
       ↓
Servo moves to open position
       ↓
Lid remains open
       ↓
Configured time expires
       ↓
Servo moves to closed position
```

---

# 12. Garbage-Level Detection

The second HC-SR04 sensor is used for garbage-level measurement.

The sensor is conceptually positioned at the top of the dustbin and directed toward the garbage surface.

```text
          HC-SR04
             ↓
             ↓ D
             ↓
      ───────────────
         Garbage
      ██████████████
```

When the dustbin is empty, the measured distance is relatively large.

When the dustbin contains more garbage, the measured distance becomes smaller.

Therefore:

```text
Large distance → Low fill level

Small distance → High fill level
```

---

# 13. Fill-Level Calculation

Let:

```text
H = Total height of the dustbin
D = Distance measured by the ultrasonic sensor
```

The approximate garbage height is:

```text
Garbage Height = H - D
```

The fill percentage is:

```text
Fill Percentage =
((H - D) / H) × 100
```

For example, if:

```text
Bin Height = 30 cm
Measured Distance = 9 cm
```

then:

```text
Fill Percentage =
((30 - 9) / 30) × 100

= 70%
```

The bin is therefore classified as approximately 70% full.

---

# 14. Bin Status Classification

The simulated system uses the following thresholds:

| Fill Percentage | Status |
| --------------: | ------ |
|           0–24% | EMPTY  |
|          25–49% | LOW    |
|          50–74% | MEDIUM |
|          75–89% | HIGH   |
|         90–100% | FULL   |

These thresholds can be changed according to the physical dimensions and calibration of the actual dustbin.

---

# 15. Status Indication

The system provides visual and audio feedback.

### EMPTY / LOW

```text
Green LED → ON
Buzzer → OFF
```

### MEDIUM / HIGH

```text
Yellow LED → ON
Buzzer → OFF
```

### FULL

```text
Red LED → ON
Buzzer → Alert
```

This provides immediate information about the current state of the bin.

---

# 16. Embedded Software Design

The firmware is written using Arduino C/C++.

The program is divided into logical functions rather than putting all functionality inside the main loop.

Important functions include:

```text
readDistanceCM()
openLid()
closeLid()
calculateFillPercentage()
getBinStatus()
updateIndicators()
getStatusName()
```

This approach improves readability and makes individual functions easier to test and modify.

---

# 17. Timing and Program Execution

The system uses `millis()` for periodic level monitoring.

Instead of continuously blocking the controller using long delays, the software checks elapsed time:

```text
Current Time - Previous Reading Time
```

If the configured interval has passed, another level measurement is performed.

This allows the controller to remain responsive to other events.

---

# 18. Sensor Timeout Handling

Ultrasonic sensors may occasionally fail to return a valid echo.

The firmware therefore uses a timeout while waiting for the ECHO signal.

If no valid response is received, the reading is treated as invalid.

This prevents the microcontroller from waiting indefinitely.

This is an important reliability concept in embedded programming.

---

# 19. Virtual Simulation Procedure

The following procedure was used to test the system.

### Step 1

Create an Arduino UNO in Wokwi.

### Step 2

Add:

* Two HC-SR04 sensors
* Servo motor
* Three LEDs
* Buzzer

### Step 3

Connect the components according to the pin configuration.

### Step 4

Upload the Arduino firmware to the virtual Arduino.

### Step 5

Start the simulation.

### Step 6

Open the Serial Monitor.

### Step 7

Change the simulated proximity distance.

### Step 8

Observe the servo response.

### Step 9

Change the simulated garbage-level distance.

### Step 10

Observe the calculated fill percentage and status indication.

---

# 20. Simulation Test Cases

## Test Case 1 — System Startup

### Input

Power on the simulated Arduino.

### Expected Result

```text
System initializes
Lid remains CLOSED
```

### Status

PASS

---

## Test Case 2 — No Object Detected

### Input

Proximity distance:

```text
100 cm
```

### Expected Result

The distance is greater than the detection threshold.

```text
Lid remains CLOSED
```

### Status

PASS

---

## Test Case 3 — Object Detected

### Input

Proximity distance:

```text
15 cm
```

### Expected Result

Since:

```text
15 cm ≤ 20 cm
```

the system detects an object.

```text
Servo → OPEN
Lid → OPEN
```

### Status

PASS

---

## Test Case 4 — Automatic Lid Closing

### Input

Allow the configured lid-open time to expire.

### Expected Result

```text
Servo → CLOSED
Lid → CLOSED
```

### Status

PASS

---

# 21. Garbage-Level Test Cases

## Test Case 5 — Empty Bin

### Input

Large distance between sensor and garbage surface.

Example:

```text
Distance ≈ 28 cm
```

### Expected Result

```text
Fill ≈ 6%
Status = EMPTY
Green LED = ON
```

### Status

PASS

---

## Test Case 6 — Medium Bin

### Input

```text
Distance = 15 cm
```

For a 30 cm bin:

```text
Fill =
((30 - 15) / 30) × 100

= 50%
```

### Expected Result

```text
Status = MEDIUM
Yellow LED = ON
```

### Status

PASS

---

## Test Case 7 — High Bin

### Input

```text
Distance ≈ 6 cm
```

Approximate fill:

```text
((30 - 6) / 30) × 100

≈ 80%
```

### Expected Result

```text
Status = HIGH
Yellow LED = ON
```

### Status

PASS

---

## Test Case 8 — Full Bin

### Input

```text
Distance ≈ 2 cm
```

Approximate fill:

```text
((30 - 2) / 30) × 100

≈ 93%
```

### Expected Result

```text
Status = FULL
Red LED = ON
Buzzer = ON
```

### Status

PASS

---

# 22. Test Result Summary

| Test Case | Condition       | Expected Result    | Result |
| --------- | --------------- | ------------------ | ------ |
| TC01      | Startup         | Lid closed         | PASS   |
| TC02      | No object       | Lid remains closed | PASS   |
| TC03      | Object at 15 cm | Lid opens          | PASS   |
| TC04      | Timer expires   | Lid closes         | PASS   |
| TC05      | Empty condition | EMPTY              | PASS   |
| TC06      | 50% fill        | MEDIUM             | PASS   |
| TC07      | ~80% fill       | HIGH               | PASS   |
| TC08      | ~93% fill       | FULL + buzzer      | PASS   |

> The above results represent the expected virtual-simulation validation. Final project documentation should retain screenshots or serial-output evidence from the actual simulation runs.

---

# 23. Serial Monitor Output

During simulation, the Serial Monitor provides diagnostic information.

Example output:

```text
=================================
 SMART DUSTBIN SYSTEM
 System Initializing...
=================================

Lid: CLOSED

Garbage Distance: 28.00 cm
Fill Level: 6%
Status: EMPTY

--------------------------------

Object detected -> Opening lid
Lid: OPEN

Lid: CLOSED

Garbage Distance: 15.00 cm
Fill Level: 50%
Status: MEDIUM

--------------------------------

Garbage Distance: 2.00 cm
Fill Level: 93%
Status: FULL

--------------------------------
```

Serial output is useful for debugging sensor values and verifying application logic.

---

# 24. Virtual Simulation Results

The virtual simulation demonstrates that the proposed embedded system can:

1. Detect an approaching object.
2. Control the servo automatically.
3. Open and close the virtual dustbin lid.
4. Measure simulated garbage distance.
5. Calculate fill percentage.
6. Classify the bin status.
7. Activate the appropriate LED.
8. Generate a buzzer alert for the FULL condition.
9. Display diagnostic information through the Serial Monitor.

The simulation therefore validates the primary functional behavior of the embedded system before physical implementation.

---
# 25. ScreenShots are Attached in folder
C:\Users\samee\MY PROJECT\Smart-Dustbin-Embedded-System\SCREENSHOTS

# 26. Advantages

The proposed system provides several advantages:

* Contactless operation
* Simple hardware architecture
* Low component cost
* Easy simulation
* Automatic operation
* Real-time status indication
* Modular firmware
* Expandable architecture
* Suitable for educational embedded-system development

---

# 27. Limitations

The virtual prototype does not completely represent all physical-world conditions.

Potential limitations include:

* Ultrasonic readings may fluctuate.
* Garbage surfaces may be irregular.
* Physical servo movement depends on mechanical design.
* Actual power requirements are not fully represented by simulation.
* The system currently does not provide wireless communication.
* The fill percentage is an approximation and requires physical calibration.

Therefore, simulation validates the software and logical behavior, while final hardware testing is required to validate electrical and mechanical performance.

---

# 28. Future Improvements

The project can be upgraded in several ways.

## ESP32 Integration

An ESP32 can replace the Arduino UNO to provide Wi-Fi connectivity.

## IoT Dashboard

The bin's status can be displayed remotely.

Example:

```text
Bin ID: BIN-001
Fill Level: 78%
Status: HIGH
Lid: CLOSED
Connection: ONLINE
```

## MQTT

MQTT can be used for communication between the smart bin and a monitoring server.

## OLED Display

A local display can show fill percentage and system status.

## Sensor Filtering

Median or moving-average filtering can reduce sensor noise.

## Finite State Machine

The lid-control logic can be converted into a formal state machine.

## Multiple Bin Monitoring

Several smart bins could report their status to a central monitoring system.

## Predictive Waste Collection

Historical fill-level data could eventually be used to estimate when a bin will require collection.

---

# 29. Learning Outcomes

This project provides practical exposure to:

### Microcontrollers

* Arduino UNO
* Digital GPIO
* Microcontroller-based control

### Sensors

* HC-SR04 ultrasonic sensor
* Trigger/Echo communication
* Distance measurement

### Actuators

* Servo motor
* LED indicators
* Buzzer

### Programming

* Arduino C/C++
* Functions
* Conditional logic
* Enumerations
* Timing
* Hardware interfacing

### Embedded Design

* Input processing
* Output control
* Sensor-actuator interaction
* Fault handling
* State-based thinking

### Development Practices

* Virtual simulation
* Debugging
* Functional testing
* Git
* GitHub
* Technical documentation

---

# 30. Conclusion

The **Smart Dustbin – Industry-Oriented Embedded System** successfully demonstrates how a microcontroller can combine sensor inputs, decision-making logic, and actuators to automate a real-world task.

The Wokwi virtual implementation provides a safe and accessible environment for developing and testing the system before physical hardware is introduced.

The first ultrasonic sensor enables contactless lid operation, while the second sensor provides garbage-level estimation. The Arduino UNO processes these inputs and controls the servo, LEDs, and buzzer accordingly.

The project demonstrates fundamental embedded-system concepts while maintaining an architecture that can be extended toward ESP32, IoT communication, remote monitoring, and smart waste-management applications.

Thus, the project serves both as an **Embedded Systems academic project** and as a practical **GitHub proof-of-work demonstrating hardware-software integration and engineering practices**.

---

# 31. Project Status

```text
Project Type      : Embedded Systems
Implementation    : Virtual Simulation
Simulation        : Wokwi
Microcontroller   : Arduino UNO
Sensors           : HC-SR04 × 2
Actuator          : Servo Motor
Indicators        : LEDs + Buzzer
Language          : Arduino C/C++
Version Control   : Git + GitHub
```

### Development Status

```text
[✓] Project Architecture
[✓] Component Selection
[✓] Pin Assignment
[✓] Ultrasonic Sensor Logic
[✓] Servo Control Logic
[✓] Garbage-Level Calculation
[✓] Status Classification
[✓] LED/Buzzer Logic
[✓] Virtual Simulation Design
[✓] Functional Test Cases
[ ] Physical Hardware Prototype
[ ] ESP32/IoT Upgrade
```

---

# 32. Author

## Sameeksha Sharma

**B.Tech – Computer Science & Engineering**

### Areas of Interest

* Embedded Systems
* Microcontrollers
* IoT
* Automation
* Software Development
* System Design

This project was developed as an academic Embedded Systems project and as a practical demonstration of microcontroller programming, sensor integration, automation, simulation, testing, and software engineering practices.

---

# 33. References

The following platforms and documentation were used as technical references during development:

* Arduino documentation
* Wokwi simulation documentation
* HC-SR04 technical references
* Servo motor documentation
* Git and GitHub documentation

---

## End of Report
