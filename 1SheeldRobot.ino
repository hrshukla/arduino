/*

Gamepad Shield Example

This example shows an application on 1Sheeld's gamepad shield.

OPTIONAL:
To reduce the library compiled size and limit its memory usage, you
can specify which shields you want to include in your sketch by
defining CUSTOM_SETTINGS and the shields respective INCLUDE_ define.

*/

int ledPin = 13;
#define CUSTOM_SETTINGS
/* Use the game pad */
#define INCLUDE_GAMEPAD_SHIELD

/* Include 1Sheeld library. */
#include <OneSheeld.h>


// Motor objects, motor number on the motor shield board
int motor_left[] = {2,3};
int motor_right[] = {7,8};

/*AF_DCMotor motorLeft(1);
AF_DCMotor motorRight(2);*/

void setup()
{
  /* Start communication. */
  OneSheeld.begin();

  // The LED just works as an indicator that the 1Sheeld is working fine
  pinMode(ledPin, OUTPUT);
  for(int i = 0; i < 2; i++){
    pinMode(motor_left[i], OUTPUT);
    pinMode(motor_right[i], OUTPUT);
  }
 /* motorLeft.setSpeed(100);
  motorRight.setSpeed(100);*/
}

void loop()
{
  /* Always check the status of gamepad buttons. */
  if (GamePad.isDownPressed())
  {
    drive_backward();
    digitalWrite(ledPin, HIGH);
  }
  else if (GamePad.isUpPressed())
  {
    drive_forward();
    digitalWrite(ledPin, HIGH);
  }
  else if (GamePad.isLeftPressed())
  {
    turn_left();
    digitalWrite(ledPin, HIGH);
  }
  else if (GamePad.isRightPressed())
  {
    turn_right();
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    motor_stop();
    digitalWrite(ledPin, LOW);
  }
}

void drive_forward() {
  digitalWrite(motor_left[0], HIGH); 
  digitalWrite(motor_left[1], LOW); 
  
  digitalWrite(motor_right[0], HIGH); 
  digitalWrite(motor_right[1], LOW); 
}

void drive_backward() {
  digitalWrite(motor_left[0], LOW); 
  digitalWrite(motor_left[1], HIGH); 
  
  digitalWrite(motor_right[0], LOW); 
  digitalWrite(motor_right[1], HIGH); 
}

void turn_left() {
  digitalWrite(motor_left[0], LOW); 
  digitalWrite(motor_left[1], HIGH); 
  
  digitalWrite(motor_right[0], HIGH); 
  digitalWrite(motor_right[1], LOW);
}

void turn_right() {
  digitalWrite(motor_left[0], HIGH); 
  digitalWrite(motor_left[1], LOW); 
  
  digitalWrite(motor_right[0], LOW); 
  digitalWrite(motor_right[1], HIGH); 
}

void motor_stop(){
  digitalWrite(motor_left[0], LOW); 
  digitalWrite(motor_left[1], LOW); 
  
  digitalWrite(motor_right[0], LOW); 
  digitalWrite(motor_right[1], LOW);
}
