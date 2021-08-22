#include <Rotary.h>
#include "Keyboard.h"

// use this option for OSX.
// Comment it out if using Windows or Linux:
// char ctrlKey = KEY_LEFT_GUI;
// use this option for Windows and Linux.
// leave commented out if using OSX:
char ctrlKey = KEY_LEFT_CTRL;

Rotary r = Rotary(2, 3);

const int KEY_Z = 122;
const int KEY_Y = 121;

void undo() {
  Keyboard.write(KEY_Z);
}

void redo() {
  Keyboard.write(KEY_Y);
}

void setup() {
  Serial.begin(9600);
  r.begin(true);
}

void loop() {
  unsigned char result = r.process();
  if (result) {
    Keyboard.press(ctrlKey);
    result == DIR_CW ? undo() : redo();
    Keyboard.release(ctrlKey);
  }
}
