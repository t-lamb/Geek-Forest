//these are libraries!
//they include special code that lets our Gemma talk to our NeoPixels
#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

//where our mic is located
int micPin = A1;

//where our NeoPixels are located
int pixelPin = 1;

//how many NeoPixels we have
int numberPixels = 1;

//name our NeoPixels pixels
//create a NeoPixel object by giving it information about itself
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(numberPixels, pixelPin, NEO_GRB + NEO_KHZ800);

//how often our microcontroller checks for volume
int sampleWindow = 50;
int delayval = 50;

void setup() {
  // Neopixel code specifically for Gemma
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);

  // the microphone is our input
  pinMode(micPin, INPUT);

  // tell the NeoPixels to start
  pixels.begin();

}

void loop() {

  // This code averages readings from mic, 
  // so they will be more accurate
  unsigned long startMillis = millis();
  int amplitude;
  int prevMicReading = analogRead(micPin);
  int maxReading = 0;
  int minReading = 1024;
  int sampleCount = 0;
  unsigned long totalDiff = 0;

  // take sample of readings
  while (millis() - startMillis < sampleWindow) {
    int newReading = analogRead(micPin);
    int difference = abs(prevMicReading - newReading);
    totalDiff += difference;
    prevMicReading = newReading;
    sampleCount++;
  }
  
  // get averages from sample
  float averageVolume = totalDiff / sampleCount;

  // based on averages, set color of Neopixel
  if (averageVolume > 30) {
    pixels.setPixelColor(0, pixels.Color(200, 0, 0)); //red
    pixels.show(); // updates pixel color
    delay(delayval); // wait before changing color again
  } else if (averageVolume > 20) {
    pixels.setPixelColor(0, pixels.Color(150, 150, 0)); //yellow
    pixels.show();
    delay(delayval);
  } else if (averageVolume > 10) {
    pixels.setPixelColor(0, pixels.Color(50, 150, 0)); //green
    pixels.show();
    delay(delayval);
  } else {
    pixels.setPixelColor(0, pixels.Color(0, 0, 0)); //off
    pixels.show();
    delay(delayval);
  }
  
}
