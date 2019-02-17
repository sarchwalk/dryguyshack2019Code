/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo theBlock;  // create servo object to control a servo
// twelve servo objects can be created on most boards
boolean spinMe = false;
boolean opened = false;
int posBlock = 0;    // variable to store the servo position
//pin assignments
int fan = 8;
int servo = 9;
int inputLed = 7;

void setup() {
  theBlock.attach(servo);  // attaches the servo on pin servo to the servo object
  pinMode(fan, OUTPUT); //output that controls fan on pin fan
  pinMode(inputLed, INPUT);  //Input to controls all on pin inputLed
}

void loop() {
  getInput();
  saltTheEarth();
}
void saltTheEarth(){
  if(spinMe){
    digitalWrite(fan,HIGH);
  }
  else{
    digitalWrite(fan,LOW);
  }
  delay(1000);
}
void getInput(){
  if(digitalRead(inputLed) == HIGH && opened == false){
    openBlock();
  }
  else if(digitalRead(inputLed) == LOW && opened == true){
        digitalWrite(fan,LOW);
    closeBlock();
  }
}

void openBlock(){
    for (posBlock = 0; posBlock <= 20; posBlock += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    theBlock.write(posBlock);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
    delay(1000);
    opened = true;
    spinMe = true;
}
void closeBlock(){
  spinMe = false;
  for (posBlock = 20; posBlock >= 0; posBlock -= 1) { // goes from 180 degrees to 0 degrees
   theBlock.write(posBlock);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  delay(1000);
  opened = false;
}
