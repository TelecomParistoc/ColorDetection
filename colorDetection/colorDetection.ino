#include <Wire.h>

// Bricktronics Example: ColorButtonBricktronicsShield
// http://www.wayneandlayne.com/bricktronics
//
// When the button is pressed, a single reading from the color sensor is taken
// and converted into a color name and printed over the Serial Console.
//
// Hardware used:
// * Wayne and Layne Bricktronics Shield
//   https://store.wayneandlayne.com/products/bricktronics-shield-kit.html
// * LEGO NXT Pushbutton Sensor
// * LEGO NXT Color Sensor
//
// Software libraries used:
// * Wayne and Layne BricktronicsShield library
//   https://github.com/wayneandlayne/BricktronicsShield
// * Wayne and Layne BricktronicsButton library
//   https://github.com/wayneandlayne/BricktronicsButton
// * Wayne and Layne BricktronicsColor library
//   https://github.com/wayneandlayne/BricktronicsColor
//
// Written in 2016 by Matthew Beckler and Adam Wolf for Wayne and Layne, LLC
// To the extent possible under law, the author(s) have dedicated all
//   copyright and related and neighboring rights to this software to the
//   public domain worldwide. This software is distributed without any warranty.
// You should have received a copy of the CC0 Public Domain Dedication along
//   with this software. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.


// Include the Bricktronics libraries
#include <BricktronicsShield.h>
#include <BricktronicsColor.h>


// Select the sensor ports for the Button (SENSOR_1 through SENSOR_4)
// and ColorSensor (SENSOR_3 or SENSOR_4) in their constructors below.
// If your chosen port has jumpers (ports 3 and 4), connect pins 2-3 and
// 4-5 for the button, and connect only pins 3-4 for the color sensor.
BricktronicsColor c(BricktronicsShield::SENSOR_3);


/* ============================================= CONSTANTES ================================ */

//make sure nothing is connected to motor port 2 ! (otherwise there is a conflict with the pins below) 
int RED_PIN = 3;
int GREEN_PIN = 4;


void setup()
{
  // Be sure to set your serial console to 115200 baud
  Serial.begin(115200);

  // Initialize the Bricktronics Shield
  BricktronicsShield::begin();

  // Initialize the button and color sensor connections
  c.begin();
}


void loop()
{
  // this delay is mandatory ! we don't really know why... 
  delay(300);
  
  int readColor = c.getColor();
  c.printColor(readColor);
  Serial.println();
  
  if (readColor == COLOR_RED) {
    digitalWrite(RED_PIN, HIGH);
    digitalWrite(GREEN_PIN, LOW);
  }
  // there is sometimes a confusion between YELLOW and GREEN
  // but never between RED and YELLOW
  else if (readColor == COLOR_YELLOW || readColor == COLOR_GREEN) {
    digitalWrite(RED_PIN, LOW);
    digitalWrite(GREEN_PIN, HIGH);
  }
  else {
    digitalWrite(RED_PIN, LOW);
    digitalWrite(GREEN_PIN, LOW);
  }

  delay(300);
}

