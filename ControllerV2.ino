#include <Mouse.h> // Include the Mouse library for mouse functions

void processReceivedValues(String receivedString) {
  // Create an array to store individual values
  int intValue[5];

  // Use sscanf to parse the values from the string
  sscanf(receivedString.c_str(), "%d %d %d %d %d", &intValue[0], &intValue[1], &intValue[2], &intValue[3], &intValue[4]);

  // Move the mouse based on the received values
  if (intValue[0] == 6) {
    Mouse.move(intValue[1], intValue[2]);
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
}

void loop() {
  if (Serial.available() > 0) {
    // Read the values as a single string
    String receivedString = Serial.readStringUntil('\n');

    // Process the received values using the processReceivedValues function
    processReceivedValues(receivedString);
  }
}
