/******************************************************************************
  MicroOLED_Hello.ino
  SFE_MicroOLED Hello World Demo
  Joel Bartlett @ SparkFun Electronics
  Original Creation Date: January 20, 2015
  
  This sketch shows you how to draw a 64x48 pixel Bitmap image on the MicroOLED.
  
  Hardware Connections:
    We'll be using the SPI interface on the MicroOLED, though it
    also supports I2C (and a really messy parallel). If you want
    to swap in I2C, read through the comments to find out how.
    
    MicroOLED ------------- Arduino
      GND ------------------- GND
      VDD ------------------- 3.3V (VCC)
    D1/MOSI ----------------- D11 (don't change)
    D0/SCK ------------------ D13 (don't change)
      D2
      D/C ------------------- D8 (can be any digital pin)
      RST ------------------- D9 (can be any digital pin)
      CS  ------------------- D10 (can be any digital pin)
    
  Development environment specifics:
  	IDE: Arduino 1.0.5
  	Hardware Platform: MicroOLED Breakout
                           Arduino Pro 3.3V/8MHz
  
  Note: The display on the MicroOLED is a 1.8V-3.3V device only.
  Don't try to connect a 5V Arduino directly to it! Use level
  shifters in between the data signals if you have to resort to
  a 5V board.
  
  This code is beerware; if you see me (or any other SparkFun 
  employee) at the local, and you've found our code helpful, 
  please buy us a round!
  
  Distributed as-is; no warranty is given.
*******************************************************************************/
#include <Wire.h>  // Include Wire if you're using I2C
#include <SPI.h>  // Include SPI if you're using SPI
#include <SFE_MicroOLED.h>  // Include the SFE_MicroOLED library

//////////////////////////
// MicroOLED Definition //
//////////////////////////
#define PIN_RESET 9  // Connect RST to pin 9 (req. for SPI and I2C)
#define PIN_DC    8  // Connect DC to pin 8 (required for SPI)
#define PIN_CS    10 // Connect CS to pin 10 (required for SPI)
#define DC_JUMPER 0
// Also connect pin 13 to SCK and pin 11 to MOSI

//////////////////////////////////
// MicroOLED Object Declaration //
//////////////////////////////////
// Declare a MicroOLED object. The parameters include:
// 1 - Reset pin: Any digital pin
// 2 - D/C pin: Any digital pin (SPI mode only)
// 3 - CS pin: Any digital pin (SPI mode only, 10 recommended)
MicroOLED oled(PIN_RESET, PIN_DC, PIN_CS);
//MicroOLED oled(PIN_RESET, DC_JUMPER); // Example I2C declaration

// I2C is great, but will result in a much slower update rate. The
// slower framerate may be a worthwhile tradeoff, if you need more
// pins, though.

//------------------------------------------------------------------------------
// File generated by LCD Assistant
// http://en.radzio.dxp.pl/bitmap_converter/
//------------------------------------------------------------------------------
//This is the array that holds the Bitmap image. The easiest way to convert a bmp
//to an array is to use the LCD Assistant linked above. 
uint8_t bender [] = {
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0xBF, 0xDF, 0x5F, 0x5F, 0x5F, 0x5F,
0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F,
0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F,
0x5F, 0xDF, 0xBF, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0xF9, 0xFE, 0x07, 0x01, 0x00, 0x00, 0xF8, 0xFE, 0xFF,
0xFF, 0xFF, 0x1F, 0x1F, 0x1F, 0xFF, 0xFF, 0xFE, 0xFC, 0xF8, 0xF0, 0xE0, 0x00, 0x00, 0x00, 0x00,
0xE0, 0xF0, 0xF8, 0xFC, 0xFE, 0xFF, 0xFF, 0x1F, 0x1F, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xF8,
0x00, 0x00, 0x01, 0x07, 0xFE, 0xF9, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xF9, 0xE7, 0xDC, 0xB0, 0xA0, 0x40, 0x41, 0x47, 0x4F,
0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x4F, 0x47, 0x43, 0x40, 0x40, 0x40, 0x40,
0x43, 0x47, 0x4F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x4F, 0x47, 0x43, 0x40,
0x40, 0xA0, 0xB0, 0xDE, 0xE7, 0xF9, 0xFE, 0x1F, 0x0F, 0x07, 0x73, 0x79, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F,
0xBF, 0x5F, 0xEF, 0x0F, 0xEF, 0xEF, 0xDF, 0xDF, 0x1F, 0xDF, 0xDF, 0xDF, 0xDF, 0x1F, 0xDF, 0xDF,
0xDF, 0xDF, 0xDF, 0x1F, 0xDF, 0xDF, 0xDF, 0xEF, 0x0F, 0xEF, 0xDF, 0xBF, 0x7F, 0xFF, 0xFF, 0xFF,
0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0xFF, 0xFF, 0xFF, 0xBE, 0x9C, 0xC0, 0xE0, 0xF0, 0xF9, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC0,
0xB7, 0x6F, 0xEE, 0x00, 0xDE, 0xDE, 0xDE, 0xDD, 0x00, 0xDD, 0xDD, 0xDD, 0xDD, 0x00, 0xDD, 0xDD,
0xDD, 0xC5, 0xC1, 0x00, 0xC9, 0xC5, 0xC1, 0x01, 0xC8, 0xC4, 0x42, 0x80, 0xC0, 0xE8, 0xE4, 0xE2,
0xE0, 0xE0, 0xEF, 0xEF, 0xE6, 0xF0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFE, 0xFE, 0xFD, 0xFD, 0xFD, 0xFB, 0xF8, 0xFB, 0xFB, 0xFB, 0xFB, 0xF8, 0xFB, 0xFB,
0xFB, 0xFB, 0xFB, 0xF8, 0xFB, 0xFD, 0xFD, 0xFC, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
};


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
  delay(1000);//pause for the splash screen
  //Note: You can change the spalsh screen by editing the array founf in the library source code
  
  oled.clear(PAGE);//clear the screen before we draw our image
  oled.drawBitmap(bender);//call the drawBitmap function and pass it the array from above
  oled.display();//display the imgae 
}

void loop()
{
}
