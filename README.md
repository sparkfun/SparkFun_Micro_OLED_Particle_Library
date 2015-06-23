## SparkFun Photon Micro OLED Shield Library

Firmware library SparkFun's Photon Micro OLED Shield.

About
-------------------

This is a firmware library for [SparkFun's Photon Micro OLED Shield](https://www.sparkfun.com/products/13628).

[![Photon Micro OLED Shield](https://cdn.sparkfun.com//assets/parts/1/1/0/1/5/13628-01.jpg)](https://www.sparkfun.com/products/13628).

With a bit of extra setup, it'll also work with the [Micro OELD Breakout](https://www.sparkfun.com/products/13003).

You can use this library to draw pixels, lines, circles, squares, and text on the micro OLED's 64x48 display.

Repository Contents
-------------------

* **/firmware** - Source files for the library (.cpp, .h).
* **/firmware/examples** - Example sketches for the library (.cpp). Run these from the Particle IDE. 
* **spark.json** - General library properties for the Particel library manager. 

Example Usage
-------------------

Include the library, declare a MicroOLED object, and set the display up with these snippets of code:

	#include "SparkFunMicroOLED.h"  // Include the SFE_MicroOLED library
	...
	//////////////////////////
	// MicroOLED Definition //
	//////////////////////////
	#define PIN_RESET D7  // Connect RST to pin 7 (req. for SPI and I2C)
	#define PIN_DC    D3  // Connect DC to pin 3 (required for SPI)
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
	...
	void setup()
	{
		oled.begin(); // Initialize the OLED
		oled.clear(ALL); // Clear the OLED's internal display buffer
		oled.display(); // Display whatever is in the firmware display buffer (SparkFun logo by default)
	}

Check out the example files in the [examples directory](https://github.com/sparkfun/SparkFun_Photon_Micro_OLED_Shield_Library/tree/master/firmware/examples) for more guidance.

### Recommended Components

* [Particle Photon](https://www.sparkfun.com/products/13345)
* [SparkFun Photon Micro OLED Shield](https://www.sparkfun.com/products/13628)

License Information
-------------------

This product is _**open source**_! 

Please review the LICENSE.md file for license information. 

If you have any questions or concerns on licensing, please contact techsupport@sparkfun.com.

Distributed as-is; no warranty is given.

- Your friends at SparkFun.