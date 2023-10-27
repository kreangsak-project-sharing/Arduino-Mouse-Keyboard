#include <Keyboard.h>
#include <Mouse.h>
#include <MouseTo.h>

char instring[40]; // Room for 36 characters plus terminating null
int spos = 0; // Location in the array
int val1 = 0;
int val2 = 0;
int val3 = 0;
int val4 = 0;
int val5 = 0;

void setup() {
  Serial.begin(128000);
  Keyboard.begin();
  Mouse.begin();
  MouseTo.setScreenResolution(2560, 1440);
  MouseTo.setCorrectionFactor(.4745);
  Mouse.init(2560, 1440); //for MouseASB
}

void loop() {
  if (Serial.available()) {
    char *bita, *bitb, *bitc, *bitd, *bite;
    int c = Serial.read();
    switch (c) {
      case '\r': break; // ignore
      case '\n':
        spos = 0;
        bita = strtok(instring, " ");
        bitb = strtok(NULL, " ");
        bitc = strtok(NULL, " ");
        bitd = strtok(NULL, " ");
        bite = strtok(NULL, " ");
        if (bita && bitb && bitc && bitd && bite) {
          val1 = atoi(bita);
          val2 = atoi(bitb);
          val3 = atoi(bitc);
          val4 = atoi(bitd);
          val5 = atoi(bite);
        }

        if (val1 == 1) {
          MouseTo.setTarget(val2, val3);
          while (MouseTo.move() == false) {}
        }
        else if (val1 == 2) {
          Mouse.move(val2, val3);
        }
        else if (val1 == 3) {
          Mouse.click();
        }
        else if (val1 == 4) {
          Mouse.press();
        }
        else if (val1 == 5) {
          Mouse.release();
        }
        else if (val1 == 6) {
          Keyboard.write(val4);
        }
        else if (val1 == 7) {
          Keyboard.press(val5);
        }
        else if (val1 == 8) {
          Keyboard.releaseAll();
        }
        else if (val1 == 9) {
          Mouse.moveABS(val2, val3);
        }
        else if (val1 == 20) {
          Keyboard.print("T");
        }
        break;
      default:
        if (spos < 36) {
          instring[spos++] = c;
          instring[spos] = 0;
        }
    }
  }
}
