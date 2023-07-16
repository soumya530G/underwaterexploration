#include <Wire.h>
#include <Servo.h>
#include <SoftwareSerial.h>
Servo servo1;
Servo servo2;
int in1 = 8;
int in2 = 9;
int in3 = 10;
int in4 = 11;
int l1=6;
int l2=7;
int bluetoothTx = 13; // bluetooth tx to 13 pin
int bluetoothRx = 12; // bluetooth rx to 12 pin


SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);


void setup() {
  Wire.begin();
  Serial.begin(9600);


  //Setup Bluetooth serial connection to android
  bluetooth.begin(9600);


  servo1.attach(5); // attach servo1 to pin 5
  servo2.attach(4); // attach servo2 to pin 4
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(l1,INPUT);
  pinMode(l2,INPUT);
  delay(1000);
}
void loop()
{  
  if(bluetooth.available() > 0){
     int command = bluetooth.read();
     Serial.println(command);
    switch (command) {
      case 49:  // Dive function
        Dive();
        break;
      case 50:  // Float function
        Surface();
        break;
      case 51:  // Start function
        Left();
        break;
      case 52:  // Stop function
        Stop();
        break;
      case 53:  // Right function
        Right();
        break;
    }
  }
}
void Stop()
{
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW); //Setting signal to LOW
  digitalWrite(in3,LOW); // for motors to stop
  digitalWrite(in4,LOW);
}
void Left() {
  // Control servo motor position
  servo1.write(135); //positioning servos for controlling
  servo2.write(135);  //for controlling fins position
}
void Right() {
  // Control servo motor position
   servo1.write(45); //positioning servos for controlling
   servo2.write(45); //for controlling fins position
}
void Dive()
{
  // Control servo motor position
  servo1.write(45); //positioning servos for controlling
  servo2.write(135); //for controlling fins position
  // Control DC motor direction
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH); //CCW for extension
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
// stop motors if respective limit switch is actuated
  if (digitalRead(l1)==HIGH){
      digitalWrite(in1,LOW); //Setting signal to LOW for
      digitalWrite(in2,LOW); // motor 1 to stop
  }
  if (digitalRead(l2)==HIGH){
      digitalWrite(in3,LOW); //Setting signal to LOW for
      digitalWrite(in4,LOW); // motor 2 to stop
  }
}
void Surface(){
  // Control servo motor position
  servo1.write(135);
  servo2.write(45);
  // Control DC motor direction
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW); //CW for retraction
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
// stop motors if respective limit switch is actuated
  if (digitalRead(l1)==HIGH){
      digitalWrite(in1,LOW);
      digitalWrite(in2,LOW);
  }
  if (digitalRead(l2)==HIGH)
  {    digitalWrite(in3,LOW);
      digitalWrite(in4,LOW);
  }
}
