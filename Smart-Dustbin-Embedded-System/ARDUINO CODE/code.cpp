
#include <Servo.h>

// ---------------- PIN DEFINITIONS ----------------

// Proximity sensor
const uint8_t PROX_TRIG_PIN = 2;
const uint8_t PROX_ECHO_PIN = 3;

// Garbage level sensor
const uint8_t LEVEL_TRIG_PIN = 4;
const uint8_t LEVEL_ECHO_PIN = 5;

// Servo
const uint8_t SERVO_PIN = 6;

// Status LEDs
const uint8_t GREEN_LED = 7;
const uint8_t YELLOW_LED = 8;
const uint8_t RED_LED = 9;

// Buzzer
const uint8_t BUZZER_PIN = 10;


// ---------------- CONFIGURATION ----------------

const float BIN_HEIGHT_CM = 30.0;

const float HAND_DETECTION_DISTANCE_CM = 20.0;

const int SERVO_CLOSED_ANGLE = 0;
const int SERVO_OPEN_ANGLE = 90;

const unsigned long LID_OPEN_TIME = 3000;

const unsigned long SENSOR_INTERVAL = 500;


// ---------------- OBJECTS ----------------

Servo lidServo;


// ---------------- STATE VARIABLES ----------------

unsigned long lastSensorRead = 0;

bool lidOpen = false;

enum BinStatus
{
  BIN_EMPTY,
  BIN_LOW,
  BIN_MEDIUM,
  BIN_HIGH,
  BIN_FULL
};


// ---------------- FUNCTION DECLARATIONS ----------------

float readDistanceCM(uint8_t trigPin, uint8_t echoPin);

void openLid();

void closeLid();

int calculateFillPercentage(float distance);

BinStatus getBinStatus(int fillPercentage);

void updateIndicators(BinStatus status);

const char* getStatusName(BinStatus status);


// ---------------- SETUP ----------------

void setup()
{
  Serial.begin(9600);

  pinMode(PROX_TRIG_PIN, OUTPUT);
  pinMode(PROX_ECHO_PIN, INPUT);

  pinMode(LEVEL_TRIG_PIN, OUTPUT);
  pinMode(LEVEL_ECHO_PIN, INPUT);

  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  pinMode(BUZZER_PIN, OUTPUT);

  lidServo.attach(SERVO_PIN);

  closeLid();

  Serial.println("=================================");
  Serial.println(" SMART DUSTBIN SYSTEM");
  Serial.println(" System Initializing...");
  Serial.println("=================================");

  delay(1000);
}


// ---------------- MAIN LOOP ----------------

void loop()
{
  // -------------------------------------------
  // 1. PERSON / HAND DETECTION
  // -------------------------------------------

  float proximityDistance =10,
      readDistanceCM(PROX_TRIG_PIN, PROX_ECHO_PIN);

  if (proximityDistance > 0 &&
      proximityDistance <= HAND_DETECTION_DISTANCE_CM)
  {
    if (!lidOpen)
    {
      Serial.println("Object detected -> Opening lid");

      openLid();

      delay(LID_OPEN_TIME);

      closeLid();
    }
   
  }
   else 
   {
         Serial.println("No movement");
         delay(1000);
   }


  // -------------------------------------------
  // 2. GARBAGE LEVEL MONITORING
  // -------------------------------------------

  if (millis() - lastSensorRead >= SENSOR_INTERVAL)
  {
    lastSensorRead = millis();

    float garbageDistance =20,
        readDistanceCM(LEVEL_TRIG_PIN, LEVEL_ECHO_PIN);

    if (garbageDistance > 0 &&
        garbageDistance <= BIN_HEIGHT_CM)
    {
      int fillPercentage =
          calculateFillPercentage(garbageDistance);

      BinStatus status =
          getBinStatus(fillPercentage);

      Serial.print("Garbage Distance: ");
      Serial.print(garbageDistance);
      Serial.println(" cm");

      Serial.print("Fill Level: ");
      Serial.print(fillPercentage);
      Serial.println("%");

      Serial.print("Status: ");
      Serial.println(getStatusName(status));

      updateIndicators(status);

      Serial.println("--------------------------------");
    }
  }
}


// ---------------- DISTANCE FUNCTION ----------------

float readDistanceCM(uint8_t trigPin, uint8_t echoPin)
{
  digitalWrite(trigPin, BIN_LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, BIN_HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, BIN_LOW);

  unsigned long duration =
      pulseIn(echoPin, BIN_HIGH, 30000);

  if (duration == 0)
  {
    return -1;
  }

  float distance = duration / 58.0;

  return distance;
}


// ---------------- SERVO FUNCTIONS ----------------

void openLid()
{
  lidServo.write(SERVO_OPEN_ANGLE);

  lidOpen = true;

  Serial.println("Lid: OPEN");
}


void closeLid()
{
  lidServo.write(SERVO_CLOSED_ANGLE);

  lidOpen = false;

  Serial.println("Lid: CLOSED");
}


// ---------------- FILL CALCULATION ----------------

int calculateFillPercentage(float distance)
{
  float fillLevel =
      ((BIN_HEIGHT_CM - distance) / BIN_HEIGHT_CM) * 100.0;

  if (fillLevel < 0)
  {
    fillLevel = 0;
  }

  if (fillLevel > 100)
  {
    fillLevel = 100;
  }

  return (int)fillLevel;
}


// ---------------- STATUS CLASSIFICATION ----------------

BinStatus getBinStatus(int fillPercentage)
{
  if (fillPercentage < 25)
  {
    return BIN_EMPTY;
  }

  if (fillPercentage < 50)
  {
    return BIN_LOW;
  }

  if (fillPercentage < 75)
  {
    return BIN_MEDIUM;
  }

  if (fillPercentage < 90)
  {
    return BIN_HIGH;
  }

  return BIN_FULL;
}


// ---------------- INDICATORS ----------------

void updateIndicators(BinStatus status)
{
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(RED_LED, LOW);

  noTone(BUZZER_PIN);

  switch (status)
  {
    case BIN_EMPTY:
    case BIN_LOW:
      digitalWrite(GREEN_LED, HIGH);
      

      break;

    case BIN_MEDIUM:
      digitalWrite(YELLOW_LED, HIGH);
      

      break;

    case BIN_HIGH:
      digitalWrite(YELLOW_LED, HIGH);
      

      break;

    case BIN_FULL:
      digitalWrite(RED_LED, HIGH);

      tone(BUZZER_PIN, 2000);
      delay(150);
      noTone(BUZZER_PIN);

      break;
  }
}


// ---------------- STATUS NAME ----------------

const char* getStatusName(BinStatus status)
{
  switch (status)
  {
    case BIN_EMPTY:
      return "EMPTY";

    case BIN_LOW:
      return "LOW";

    case BIN_MEDIUM:
      return "MEDIUM";

    case BIN_HIGH:
      return "HIGH";

    case BIN_FULL:
      return "FULL";
  }

  return "UNKNOWN";
}
