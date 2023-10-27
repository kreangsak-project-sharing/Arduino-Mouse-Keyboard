#include <Mouse.h>
#include <MouseTo.h>
#include <Keyboard.h>

void processReceivedValues(String receivedString) {
  // Create an array to store individual values
  int intValue[5];

  // Use sscanf to parse the values from the string
  sscanf(receivedString.c_str(), "%d %d %d %d %d", &intValue[0], &intValue[1], &intValue[2], &intValue[3], &intValue[4]);

  // Print the received values to the serial monitor (uncomment if needed)
  // Serial.print("Received values: ");
  // for (int i = 0; i < 5; i++) {
  //   Serial.print(intValue[i]);
  //   Serial.print(" ");
  // }
  // Serial.println();

  // Move the mouse or perform keyboard actions based on the received values
  if (intValue[0] == 1) {
    MouseTo.setTarget(intValue[1], intValue[2]);
    while (!MouseTo.move()) {}
  } else if (intValue[0] == 2) {
    Mouse.move(intValue[1], intValue[2]);
  } else if (intValue[0] == 3) {
    Mouse.click();
  } else if (intValue[0] == 4) {
    Mouse.press();
  } else if (intValue[0] == 5) {
    Mouse.release();
  } else if (intValue[0] == 6) {
    Keyboard.write(intValue[3]);
  } else if (intValue[0] == 7) {
    Keyboard.press(intValue[4]);
  } else if (intValue[0] == 8) {
    Keyboard.releaseAll();
  } else if (intValue[0] == 9) {
    Mouse.moveABS(intValue[1], intValue[2]);
  } 
  // Add more conditions if needed
  else {
    // Handle unknown values
  }
}

void setup() {
  Serial.begin(128000);
  Keyboard.begin();
  Mouse.begin();
  MouseTo.setScreenResolution(2560, 1440);
  MouseTo.setCorrectionFactor(.4745);
  Mouse.init(2560, 1440);
}

void loop() {
  if (Serial.available() > 0) {
    // Read the values as a single string
    String receivedString = Serial.readStringUntil('\n');

    // Process the received values using the processReceivedValues function
    processReceivedValues(receivedString);
  }
}
