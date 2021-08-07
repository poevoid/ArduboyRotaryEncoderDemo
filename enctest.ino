#include <Arduboy2.h>

#include <Encoder.h>

// Change these two numbers to the pins connected to your encoder.
//   Best Performance: both pins have interrupt capability
//   Good Performance: only the first pin has interrupt capability
//   Low Performance:  neither pin has interrupt capability
Encoder myEnc(3, 0);
//   avoid using pins with LEDs attached

Arduboy2 arduboy;
int counter = 0;
int oldPosition = -999;
void setup() {
  // put your setup code here, to run once:
  arduboy.begin();
  pinMode (3,INPUT_PULLUP);
  pinMode (0,INPUT_PULLUP);
  arduboy.clear();
  arduboy.setFrameRate(15);
  
}
void loop() {
  // put your main code here, to run repeatedly:
  if (!arduboy.nextFrame()) return;
  arduboy.clear();
  int newPosition = myEnc.read()/4;
  
  int difference = (newPosition - oldPosition);
   if (difference < 0) {
    //clockwise
    counter++;
   } else if (difference >0){
    //anticlockwise
    counter--;
   } else {
    //no change
   }
  arduboy.setCursor(0,0);
  arduboy.print("Encoder val: \n");
  arduboy.print(counter);
  oldPosition = newPosition;
  arduboy.display();
}
