#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Servo.h>

// LEDs
#define LED1 4
#define LED2 5
#define LED3 6
#define LED4 7

// IR sensor
#define IR 8

// Ultrasonic
#define trig 9
#define echo 10

// Servo
Servo myservo;

// LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

float distance;

bool gateOpen = false;


// ---------------- LED ON ----------------
void ledsON()
{
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, HIGH);
}


// ---------------- LED OFF ----------------
void ledsOFF()
{
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
}


// ---------------- ULTRASONIC ----------------
float ultra()
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);

  digitalWrite(trig, LOW);

  long duration = pulseIn(echo, HIGH);

  float d = 0.0343 * duration / 2;

  Serial.print("Distance = ");
  Serial.print(d);
  Serial.println(" cm");

  return d;
}


// ---------------- SETUP ----------------
void setup()
{
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);

  pinMode(IR, INPUT);

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  Serial.begin(9600);

  myservo.attach(11);

  // Initially gate closed
  myservo.write(0);

  ledsOFF();

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("WELCOME TO");

  lcd.setCursor(0, 1);
  lcd.print("SMART PARKING");
}


// ---------------- LOOP ----------------
void loop()
{
  int value = digitalRead(IR);


  // -------- IR DETECTS CAR --------
  if (value == LOW && gateOpen == false)
  {
    Serial.println("CAR DETECTED BY IR");

    // LEDs ON
    ledsON();

    // Open gate
    myservo.write(90);

    gateOpen = true;

    delay(500);
  }


  // -------- ULTRASONIC CHECK --------
  if (gateOpen == true)
  {
    distance = ultra();

    // Object detected by ultrasonic
    if (distance > 0 && distance < 10)
    {
      Serial.println("CAR DETECTED BY ULTRASONIC");
      Serial.println("GATE CLOSED");

      // Close gate
      myservo.write(0);

      // LEDs OFF
      ledsOFF();

      gateOpen = false;

      delay(1000);
    }
  }

  delay(100);
}