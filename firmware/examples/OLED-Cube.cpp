/******************************************************************************
  MicroOLED_Hello.ino
  SFE_MicroOLED Hello World Demo
  Jim Lindblom @ SparkFun Electronics
  Original Creation Date: June 22, 2015

  This sketch draws a 3-D cube on the SparkFun Photon Micro OLED shield. 
  It'll rotate as fast as it can.

  Hardware Connections:
    We'll be using the SPI interface on the MicroOLED, though it
    also supports I2C (and a really messy parallel). If you want
    to swap in I2C, read through the comments to find out how.
	
	(The Shield already does this for you, but a SparkFun Micro OLED will
	also work with this library.)

    MicroOLED ------------- Photon
      GND ------------------- GND
      VDD ------------------- 3.3V (VCC)
    D1/MOSI ----------------- A5 (don't change)
    D0/SCK ------------------ A3 (don't change)
      D2
      D/C ------------------- D6 (can be any digital pin)
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
#include "SparkFunMicroOLED/SparkFunMicroOLED.h"  // Include Micro OLED library
#include "math.h"

//////////////////////////
// MicroOLED Definition //
//////////////////////////
#define PIN_RESET D7  // Connect RST to pin 7 (req. for SPI and I2C)
#define PIN_DC    D6  // Connect DC to pin 6 (required for SPI)
#define PIN_CS    A2 // Connect CS to pin A2 (required for SPI)

//////////////////////////////////
// MicroOLED Object Declaration //
//////////////////////////////////
// Declare a MicroOLED object. The parameters include:
// 1 - Mode: Should be either MODE_SPI or MODE_I2C
// 2 - Reset pin: Any digital pin
// 3 - D/C pin: Any digital pin (SPI mode only)
// 4 - CS pin: Any digital pin (SPI mode only, 10 recommended)
MicroOLED oled(MODE_SPI, PIN_RESET, PIN_DC, PIN_CS);
//MicroOLED uOLED(MODE_I2C, PIN_RESET); // Example I2C declaration

// I2C is great, but will result in a much slower update rate. The
// slower framerate may be a worthwhile tradeoff, if you need more
// pins, though.

////////////////////
// Cube Variables //
////////////////////
#define SHAPE_SIZE 600
#define ROTATION_SPEED 0 // ms delay between cube draws

int SCREEN_WIDTH = oled.getLCDWidth();
int SCREEN_HEIGHT = oled.getLCDHeight();

float d = 3;
float px[] = { -d,  d,  d, -d, -d,  d,  d, -d };
float py[] = { -d, -d,  d,  d, -d, -d,  d,  d };
float pz[] = { -d, -d, -d, -d,  d,  d,  d,  d };

float p2x[] = {0,0,0,0,0,0,0,0};
float p2y[] = {0,0,0,0,0,0,0,0};

float r[] = {0,0,0};


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
}

void loop()
{
	drawCube();
	delay(ROTATION_SPEED);
}

void drawCube()
{
  r[0]=r[0]+M_PI/180.0; // Add a degree
	r[1]=r[1]+M_PI/180.0; // Add a degree
	r[2]=r[2]+M_PI/180.0; // Add a degree
	if (r[0] >= 360.0*M_PI/180.0) r[0] = 0;
	if (r[1] >= 360.0*M_PI/180.0) r[1] = 0;
	if (r[2] >= 360.0*M_PI/180.0) r[2] = 0;

	for (int i=0;i<8;i++)
	{
		float px2 = px[i];
		float py2 = cos(r[0])*py[i] - sin(r[0])*pz[i];
		float pz2 = sin(r[0])*py[i] + cos(r[0])*pz[i];

		float px3 = cos(r[1])*px2 + sin(r[1])*pz2;
		float py3 = py2;
		float pz3 = -sin(r[1])*px2 + cos(r[1])*pz2;

		float ax = cos(r[2])*px3 - sin(r[2])*py3;
		float ay = sin(r[2])*px3 + cos(r[2])*py3;
		float az = pz3-150;

		p2x[i] = SCREEN_WIDTH/2+ax*SHAPE_SIZE/az;
		p2y[i] = SCREEN_HEIGHT/2+ay*SHAPE_SIZE/az;
	}

	oled.clear(PAGE);
	for (int i=0;i<3;i++)
	{
		oled.line(p2x[i],p2y[i],p2x[i+1],p2y[i+1]);
		oled.line(p2x[i+4],p2y[i+4],p2x[i+5],p2y[i+5]);
		oled.line(p2x[i],p2y[i],p2x[i+4],p2y[i+4]);
	}
	oled.line(p2x[3],p2y[3],p2x[0],p2y[0]);
	oled.line(p2x[7],p2y[7],p2x[4],p2y[4]);
	oled.line(p2x[3],p2y[3],p2x[7],p2y[7]);
	oled.display();
}
