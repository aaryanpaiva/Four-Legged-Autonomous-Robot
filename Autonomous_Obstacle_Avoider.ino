#include <VarSpeedServo.h>

VarSpeedServo b1;
VarSpeedServo b2;
VarSpeedServo b3;
VarSpeedServo b4;
VarSpeedServo l1;
VarSpeedServo l2;
VarSpeedServo l3;
VarSpeedServo l4;
VarSpeedServo head_servo;

int d1;
int d2;
int d3;

int trigPin = A4;
int echoPin = A3;
long duration, cm, inches;


void setup()
{
  Serial.begin(9600);
  b1.attach(3);
  l1.attach(2);
  b2.attach(4);
  l2.attach(5);
  b3.attach(7);
  l3.attach(6);
  b4.attach(8);
  l4.attach(9);
  head_servo.attach(10);
  stand();
  delay(1000);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  stand ();

  delay(1000);

}

void loop()
{
  head_servo.write(0, 100);
  delay(1000);
  ultrasonic_read();
  d1 = cm;

  head_servo.write(90, 100);
  delay(1000);
  ultrasonic_read();
  d2 = cm;

  head_servo.write(180, 100);
  delay(1000);
  ultrasonic_read();
  d3 = cm;

  if (d1 > 10 && d2 > 10 && d3 > 10) //No Obstacle
  {
    if (d1 > d2 && d1 > d3)
    {
      right_turn();
      right_turn();
    }
    else if (d2 > d3 && d2 > d1)
    {
      walk();
      walk();
    }
    else
    {
      left_turn();
      left_turn();
    }

  }
  else
  {
    stand();
  }
}


void ultrasonic_read()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  duration = pulseIn(echoPin, HIGH);

  cm = (duration / 29 / 2);

}
void stand()
{
  b1.write(90, 100);
  b2.write(90, 100);
  b3.write(90, 100);
  b4.write(90, 100);

  l1.write(60, 100);
  l2.write(60, 100);
  l3.write(60, 100);
  l4.write(60, 100);
}

void walk()
{
  l1.write(90, 100);
  l3.write(90, 100);
  delay(500);

  b1.write(140, 100);
  b3.write(40, 100);
  delay(500);

  l1.write(60, 100);
  l3.write(60, 100);
  delay(500);

  b1.write(90, 100);
  b3.write(90, 100);
  l2.write(90, 100);
  l4.write(90, 100);
  delay(500);

  b2.write(140, 100);
  b4.write(40, 100);
  delay(500);

  l2.write(60, 100);
  l4.write(60, 100);
  delay(500);

  b2.write(90, 100);
  b4.write(90, 100);

}

void left_turn()
{
  l1.write(90, 100);
  l3.write(90, 100);
  delay(500);

  b1.write(40, 100);
  b3.write(40, 100);
  delay(500);

  l1.write(60, 100);
  l3.write(60, 100);
  delay(500);

  b1.write(90, 100);
  b3.write(90, 100);
  l2.write(90, 100);
  l4.write(90, 100);
  delay(500);

  b2.write(40, 100);
  b4.write(40, 100);
  delay(500);

  l2.write(60, 100);
  l4.write(60, 100);
  delay(500);

  b2.write(90, 100);
  b4.write(90, 100);

}

void right_turn()
{
  l1.write(90, 100);
  l3.write(90, 100);
  delay(500);

  b1.write(140, 100);
  b3.write(140, 100);
  delay(500);

  l1.write(60, 100);
  l3.write(60, 100);
  delay(500);

  b1.write(90, 100);
  b3.write(90, 100);
  l2.write(90, 100);
  l4.write(90, 100);
  delay(500);

  b2.write(140, 100);
  b4.write(140, 100);
  delay(500);

  l2.write(60, 100);
  l4.write(60, 100);
  delay(500);

  b2.write(90, 100);
  b4.write(90, 100);

}

