//This code read a color permanently and output the read color on digital pins 3 and 4 
 
// Include the Bricktronics Button and ColorSensor libraries
#include <BricktronicsColor.h>
 
 
// This example can be run in three different ways. Pick one, and un-comment
// the code lines corresponding to your chosen method. Comment-out the lines
// for the other methods that you aren't using.
 
// 1. With a Bricktronics Shield - Include these lines and be sure to
// call BricktronicsShield::begin() in the setup() function below.
// You also need to install the Adafruit MCP23017 library:
//  https://github.com/adafruit/Adafruit-MCP23017-Arduino-Library
// Select the sensor port for the ColorSensor (SENSOR_3 or SENSOR_4) in their constructors below.
// connect only pins 3-4 for the color sensor.
//
// Config 1 - arduino:avr:uno
//#include <Wire.h>
//#include <Adafruit_MCP23017.h>
#include <BricktronicsShield.h>
BricktronicsColor c(BricktronicsShield::SENSOR_3);
// Config end
 
// 2. With a Bricktronics Megashield - Include these lines but do not
// call BricktronicsShield::begin() in the setup() function below.
// Select the sensor ports for the button (SENSOR_1 through SENSOR_4)
// and color sensor (SENSOR_1 through SENSOR_4) in their constructors below.
// If your chosen port has jumpers, connect pins 2-3 and 4-5 for the button,
// and connect only pins 3-4 for the color sensor.
//
// Config 2 - arduino:avr:mega:cpu=atmega2560
//#include <BricktronicsMegashield.h>
//BricktronicsButton b(BricktronicsMegashield::SENSOR_1);
//BricktronicsColor c(BricktronicsMegashield::SENSOR_3);
// Config end
 
// 3. With two Bricktronics Breakout boards - No additional includes needed, just
// update the pin assignments in the button and color sensor constructors below.
//
// For the color sensor, connect these pins on the Bricktronics Breakout board:
//  Pin 1 - Unused
//  Pin 2 - Connect to Ground
//  Pin 3 - Connect to Ground
//  Pin 4 - Connect to 5V
//  Pin 5 - Connect to any digital pin
//  Pin 6 - Connect to any analog input pin
//
// The BricktronicsColor() arguments are: clockPin, dataPin
// clockPin is where the breakout board's pin 5 is connected
// dataPin is where the breakout board's pin 6 is connected
//    This must be an analog pin.

const int ledPinYellow = 3;
const int ledPinBlue = 4;

//time beetween two different color measures
const int period = 500; //milliseconds

 
void setup() 
{
  // Be sure to set your serial console to 115200 baud
  Serial.begin(115200);
 
  // Only call this if you are using a Bricktronics Shield,
  // otherwise leave it commented-out.
  // Config 1 - arduino:avr:uno
  BricktronicsShield::begin();
  // Config end
 
  // Initialize the button and color sensor connections
  c.begin();
}
 
 
void loop()
{
  
  int readColor = c.getColor();

  //Serial.println("ok");
  //c.printColor(readColor);
  
  if (readColor == COLOR_YELLOW) digitalWrite(ledPinYellow, HIGH);
  else digitalWrite(ledPinYellow, LOW);

  if (readColor == COLOR_BLUE) digitalWrite(ledPinBlue, HIGH);
  else digitalWrite(ledPinBlue, LOW);
 
  //we wait a little bit here
  delay(period);
}
