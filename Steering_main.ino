#include <MobaTools.h>
#include <NewPing.h>
#define TRIGGER_PIN A0
#define ECHO_PIN A1
#define LEFT A2
#define RIGHT A3
#define MAX_DISTANCE 200
#define DIRPIN 2
#define STEPPIN 3
const int STEPS_REVOLUTION = 800;
MoToStepper SMTR(STEPS_REVOLUTION, STEPDIR);
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
int distance;
int cas;
void setup()
{
  SMTR.attach( STEPPIN, DIRPIN);
  SMTR.setSpeed(500);
  SMTR.setRampLen(100);
  Serial.begin(115200); // Starts the serial communication
  pinMode(RIGHT, INPUT);
  pinMode(LEFT, INPUT);
}
void ultra()
{
  delay(50);
  unsigned int uS = sonar.ping();
  distance = uS / US_ROUNDTRIP_CM ;
  Serial.println(distance);
}
void loop()
{

  int right = digitalRead(RIGHT);
  int left = digitalRead(LEFT);
  ultra();

  if (right == LOW && left == LOW )
  {
    cas = 1;
  }
  if (right == HIGH && left == LOW)
  {
    cas = 2;
  }

  if (left == HIGH && right == LOW)
  {
    cas = 3;
  }
   if (left == HIGH && right == HIGH)
  {
    cas = 1;
  }
  switch (cas)
  {
    case 1 : // Auto centering
      {
        if (distance == 8 || distance < 2 || distance > 14 )
        {
          SMTR.rotate(0);
        }
        if (distance < 8)
        {
          SMTR.rotate(-1);
        }

        if (distance > 8)
        {
          SMTR.rotate(1);
        }
      }
       break;
       
       case 2 : // left turn
       SMTR.rotate(-1);
       break;
       
       case 3 : // right turn
       SMTR.rotate(1);
       break;
  }
}
