For The Following Embedded project COMPONENTS USED:-


ARDUINO UNO:Acting as a main controller
Connections:-
| Device            | Pin     | Arduino |
| ----------------- | ------- | ------- |
| Proximity HC-SR04 | TRIG    | D2      |
| Proximity HC-SR04 | ECHO    | D3      |
| Level HC-SR04     | TRIG    | D4      |
| Level HC-SR04     | ECHO    | D5      |
| Servo             | Signal  | D6      |
| Green LED         | Anode   | D7      |
| Yellow LED        | Anode   | D8      |
| Red LED           | Anode   | D9      |
| Buzzer            | +       | D10     |
| All LEDs          | Cathode | GND     |
| Sensors           | VCC     | 5V      |
| Sensors           | GND     | GND     |
| Servo             | VCC     | 5V*     |
| Servo             | GND     | GND     |



ULTRA SENSOR:-Two HC-SR04 Sensors are used 
1.As a proximity sensor (senses the person at a a distance)

2.Second work as lever sensor(senes the level of Dustbin)

connection:-
 Device            | Pin     | Arduino |
| ----------------- | ------- | ------- |
| Proximity HC-SR04 | TRIG    | D2      |
| Level HC-SR04     | TRIG    | D4      |
| Level HC-SR04     | ECHO    | D5      |
| Proximity HC-SR04 | ECHO    | D3      |
| Sensors           | VCC     | 5V      |
| Sensors           | GND     | GND     |

The Arduino generates a short pulse on TRIG.

The sensor emits ultrasonic waves.

The wave reflects from an object.

ECHO stays HIGH for a duration proportional to the travel time.
Distance(cm) = EchoTime(µs) / 58


SERVO MOTOR:-
connections:-
Device            | Pin     | Arduino |
| ----------------- | ------- | ------- |
| Servo             | Signal  | D6      | 
| Servo             | VCC     | 5V*     |
| Servo             | GND     | GND     |

BUZZER:-Used as alarm for indicating that the bin current position
connections:-
Device            | Pin     | Arduino |
| Buzzer            | +       | D10     |
 

LEDS:-They are used as Indicators ,for indicating the bin's  cuurent status
connections:-
Device            | Pin     | Arduino |
| Green LED         | Anode   | D7      |
| Yellow LED        | Anode   | D8      |
| Red LED           | Anode   | D9      |
| All LEDs          | Cathode | GND     |


