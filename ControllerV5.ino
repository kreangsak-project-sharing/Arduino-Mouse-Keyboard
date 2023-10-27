#include <Mouse.h> // Include the Mouse library for mouse functions
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
  switch (intValue[0]) {
    case 1:
      MouseTo.setTarget(intValue[1], intValue[2]);
      while (MouseTo.move() == false) {}
      break;
    case 2:
      Mouse.move(intValue[1], intValue[2]);
      break;
    case 3:
      Mouse.click();
      break;
    case 4:
      Mouse.press();
      break;
    case 5:
      Mouse.release();
      break;
    case 6:
      Keyboard.write(intValue[3]);
      break;
    case 7:
      Keyboard.press(intValue[4]);
      break;
    case 8:
      Keyboard.releaseAll();
      break;
    case 9:
      Mouse.moveABS(intValue[1], intValue[2]);
      break;
    // Add more cases if needed
    default:
      // Handle unknown values
      break;
  }
}

void setup() {
  Serial.begin(128000); // Make sure to match the baud rate with your C# program
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
