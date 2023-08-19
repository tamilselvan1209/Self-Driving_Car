char t;
int Speed;
const int pwmPin = 5;
#define LEFT A2
#define RIGHT A3
int targetDutyCycle = Speed;
int dutyCycle = 0;
void setup() {
  Serial.begin(9600);
  pinMode(RIGHT, OUTPUT);
  pinMode(LEFT, OUTPUT);
  //analogWrite(pwmPin, 0);
}

void accl() {
  if (dutyCycle < Speed) {
    if (dutyCycle >= Speed - 5) {
      dutyCycle = Speed;
    } else {
      dutyCycle++;
    }
    analogWrite(pwmPin, dutyCycle);
    delay(5);
  }
}
void decl() {
  if (dutyCycle <= Speed) {
    if (dutyCycle < Speed + 5) {
      dutyCycle = 0;
    } else {
      dutyCycle--;
    }
    analogWrite(pwmPin, dutyCycle);
    delay(5);
  }
}
void loop() {
  if (Serial.available()) {
    t = Serial.read();
    Serial.println(t);
    {
      switch (t) {

        case '0':
          Speed = 0;
          break;

        case '1':
          Speed = 65;
          break;

        case '2':
          Speed = 79;
          break;

        case '3':
          Speed = 94;
          break;

        case '4':
          Speed = 108;
          break;

        case '5':
          Speed = 123;
          break;

        case '6':
          Speed = 137;
          break;

        case '7':
          Speed = 152;
          break;

        case '8':
          Speed = 166;
          break;

        case '9':
          Speed = 181;
          break;

        case 'q':
          Speed = 195;
          break;

        case 'F':  //Forward
          accl();
          break;

          /*case 'B':  //Back
          accl();
          break;*/

        case 'L':  //Left
          digitalWrite(LEFT, HIGH);
          digitalWrite(RIGHT, LOW);
          break;

        case 'R':  //Right
          digitalWrite(RIGHT, HIGH);
          digitalWrite(LEFT, LOW);
          break;

        case 'G':  //Forward Left
          accl();
          digitalWrite(LEFT, HIGH);
          digitalWrite(RIGHT, LOW);
          break;

        case 'I':  //Forward Right
          accl();
          digitalWrite(RIGHT, HIGH);
          digitalWrite(LEFT, LOW);
          break;

          /* case'H' : //Rear Left
           FLMTR.setSpeed(-Speed);
           FRMTR.setSpeed(0);
           RLMTR.setSpeed(0);
           RRMTR.setSpeed(-Speed);
           break;

          case'J' : //Rear Right
           FLMTR.setSpeed(0);
           FRMTR.setSpeed(-Speed);
           RLMTR.setSpeed(-Speed);
           RRMTR.setSpeed(0);
           break;

          case'U' : //Spin Left
           FLMTR.setSpeed(-Speed);
           FRMTR.setSpeed(Speed);
           RLMTR.setSpeed(-Speed);
           RRMTR.setSpeed(Speed);
           break;

          case'W' : //Spin Right
           FLMTR.setSpeed(Speed);
           FRMTR.setSpeed(-Speed);
           RLMTR.setSpeed(Speed);
           RRMTR.setSpeed(-Speed);
           break;

          case'X' : //Yaw Left
           FLMTR.setSpeed(Speed);
           FRMTR.setSpeed(-Speed);
           RLMTR.setSpeed(0);
           RRMTR.setSpeed(0);
           break;

          case'V' : //Yaw Right
           FLMTR.setSpeed(-Speed);
           FRMTR.setSpeed(Speed);
           RLMTR.setSpeed(0);
           RRMTR.setSpeed(0);
           break;*/
        case 'S':
          decl();
          break;
      }
    }
  }
}
