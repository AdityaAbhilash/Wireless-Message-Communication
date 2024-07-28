//this is master

#include <SoftwareSerial.h>

SoftwareSerial BTSerial(8, 9);

 int state = 0;
 const int ledPin = 4;
const int buttonPin = 2;
int buttonState = 1;

void setup() 
{
  BTSerial.begin(9600);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin, HIGH);
}

void loop()
{
 if(BTSerial.available() > 0)
 { 
    // Checks whether data is comming from the serial port
    state = BTSerial.read(); // Reads the data from the serial port
 }
 // Controlling the LED
 buttonState = digitalRead(buttonPin);
 if (buttonState == LOW)
 {
  BTSerial.write('1');
 }
 else
 {
  BTSerial.write('0');
 }
 
 if (state == '1') 
 {
  digitalWrite(ledPin, HIGH); // LED ON
  state = 0;
 }
 else if (state == '0') 
 {
  digitalWrite(ledPin, LOW); // LED ON
  state = 0;
 }
}
