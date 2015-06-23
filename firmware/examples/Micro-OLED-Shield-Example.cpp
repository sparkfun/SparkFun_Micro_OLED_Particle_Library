/******************************************************************************
  Micro-OLED-Shield-Example.ino
  SparkFun Micro OLED Library Hello World Example
  Jim Lindblom @ SparkFun Electronics
  Original Creation Date: June 22, 2015

  This sketch prints a friendly, recognizable logo on the OLED Shield.
  
  Hardware Connections:
	This sketch was written specifically for the Photon Micro OLED Shield,
	which does all the wiring for you. If you have a Micro OLED breakout,
	use the following hardware setup:

    MicroOLED ------------- Photon
      GND ------------------- GND
      VDD ------------------- 3.3V (VCC)
    D1/MOSI ----------------- A5 (don't change)
    D0/SCK ------------------ A3 (don't change)
      D2
      D/C ------------------- D4 (can be any digital pin)
      RST ------------------- D7 (can be any digital pin)
      CS  ------------------- A2 (can be any digital pin)

  Development environment specifics:
  	IDE: Particle Build
  	Hardware Platform: Particle Photon
                       SparkFun Photon Micro OLED Shield

  This code is beerware; if you see me (or any other SparkFun
  employee) at the local, and you've found our code helpful,
  please buy us a round!

  Distributed as-is; no warranty is given.
*******************************************************************************/
#include "SparkFunMicroOLED/SparkFunMicroOLED.h"  // Include the SFE_MicroOLED library
#include "math.h"

//////////////////////////////////
// MicroOLED Object Declaration //
//////////////////////////////////
// Declare a MicroOLED object. The parameters include:
// 1 - Mode: Should be either MODE_SPI or MODE_I2C
// 2 - Reset pin: Any digital pin (D7 on Micro OLED Shield)
// 3 - D/C pin: Any digital pin (SPI mode only) (D3 on Micro OLED Shield)
// 4 - CS pin: Any digital pin (SPI mode only, 10 recommended) (A2 on Micro OLED Shield)
MicroOLED oled(MODE_SPI, D7, D3, A2);

void setup()
{
  // These three lines of code are all you need to initialize the
  // OLED and print the splash screen.

  // Before you can start using the OLED, call begin() to init
  // all of the pins and configure the OLED.
  oled.begin();
  // clear(ALL) will clear out the OLED's graphic memory.
  // clear(PAGE) will clear the Arduino's display buffer.
  oled.clear(ALL);  // Clear the display's memory (gets rid of artifacts)
  // To actually draw anything on the display, you must call the
  // display() function.
  oled.display();
}

void loop()
{
}
