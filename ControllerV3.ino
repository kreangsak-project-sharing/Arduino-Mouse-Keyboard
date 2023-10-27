#include <Mouse.h> // Include the Mouse library for mouse functions
#include <MouseTo.h>
#include <Keyboard.h>

void processReceivedValues(String receivedString) {
  // Create an array to store individual values
  int intValue[5];

  // Use sscanf to parse the values from the string
  sscanf(receivedString.c_str(), "%d %d %d %d %d", &intValue[0], &intValue[1], &intValue[2], &intValue[3], &intValue[4]);

  // Move the mouse based on the received values
  if (intValue[0] == 6) {
    Mouse.move(intValue[1], intValue[2]);
  }

  if (val1 == 1) {
    MouseTo.setTarget(intValue[1], intValue[2]);
    while (MouseTo.move() == false) {}
  }
  if (val1 == 2) {
    Mouse.move(intValue[1], intValue[2]);
  }
  if (val1 == 3) {
    Mouse.click();
  }
  if (val1 == 4) {
    Mouse.press();
  }
  if (val1 == 5) {
    Mouse.release();
  }
  if (val1 == 6) {
    Keyboard.write(intValue[3]);
  }
  if (val1 == 7) {
    Keyboard.press(intValue[4]);
  }
  if (val1 == 8) {
    Keyboard.releaseAll();
  }
  if (val1 == 9) {
    Mouse.moveABS(intValue[1], intValue[2]);
  }

  // Print the received values to the serial monitor
  Serial.print("Received values: ");
  for (int i = 0; i < 5; i++) {
    Serial.print(intValue[i]);
    Serial.print(" ");
  }
  Serial.println();
}

void setup() {
  Serial.begin(128000); // Make sure to match the baud rate with your C# program
  Keyboard.begin();
  Mouse.begin();
  //MouseTo.setScreenResolution(1680, 1050);
  MouseTo.setScreenResolution(2560, 1440);
  //MouseTo.setCorrectionFactor(.9445); //for MouseTo
  MouseTo.setCorrectionFactor(.4745); //for MouseTo
  //Mouse.init(1680, 1050); //for MouseASB
  Mouse.init(2560, 1440); //for MouseASB
}

void loop() {
  if (Serial.available() > 0) {
    // Read the values as a single string
    String receivedString = Serial.readStringUntil('\n');

    // Process the received values using the processReceivedValues function
    processReceivedValues(receivedString);
  }
}
