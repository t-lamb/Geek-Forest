//these are libraries!
//they include special code that lets our Gemma talk to our NeoPixels
#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

//where our NeoPixels are located
int pixelPin = 1;

//how many NeoPixels we have
int numberPixels = 1;

//name our NeoPixels pixels
//create a NeoPixel object by giving it information about itself
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(numberPixels, pixelPin, NEO_GRB + NEO_KHZ800);

void setup() {
  //tell the NeoPixels to start
  pixels.begin();
  
  //set them to a color (Red,Green,Blue) 
  //numbers can be 0 to 255
  //what color will this be?
  pixels.setPixelColor(0, pixels.Color(0, 150, 150));
  
  //show that color
  pixels.show();
}

void loop() {
  
}
