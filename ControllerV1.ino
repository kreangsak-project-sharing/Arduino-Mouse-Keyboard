#include <Mouse.h> // Include the Mouse library for mouse functions

void processReceivedValues(String receivedString) {
  // Create a string array to store individual values
  String values[5];

  // Initialize variables for parsing
  int spaceIndex = receivedString.indexOf(' ');
  int startIndex = 0;

  // Parse and store individual values using if statements
  for (int i = 0; i < 5; i++) {
    if (spaceIndex == -1) {
      values[i] = receivedString.substring(startIndex);
    } else {
      values[i] = receivedString.substring(startIndex, spaceIndex);
      startIndex = spaceIndex + 1;
      spaceIndex = receivedString.indexOf(' ', startIndex);
    }
  }

  // Convert string values to integers
  int intValue[5];
  for (int i = 0; i < 5; i++) {
    intValue[i] = values[i].toInt();
  }

  // Check for different cases based on intValue[0]
  if (intValue[0] == 6) {
    // Move the mouse based on intValue[1] and intValue[2]
    Mouse.move(intValue[1], intValue[2]);
  } else if (intValue[0] == 7) {
    // Perform a mouse click
    Mouse.click();
  }
  // Add more cases as needed

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
