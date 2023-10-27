#include <Mouse.h> // Include the Mouse library for mouse functions

int receivedValues[5]; // Array to store received values

void setup() {
  Serial.begin(128000); // Make sure to match the baud rate with your C# program
}

void loop() {
  if (Serial.available() > 0) {
    // Read the values separated by spaces
    for (int i = 0; i < 5; i++) {
      receivedValues[i] = Serial.parseInt();
    }

    // Process the received values using a switch statement
    processReceivedValues(receivedValues);
  }
}

void processReceivedValues(int values[]) {
  // Check if values[0] is equal to 6 for mouse move
  if (values[0] == 6) {
    // Move the mouse based on values[1] and values[2]
    Mouse.move(values[1], values[2]);
  }

  // Check if values[0] is equal to 7 for mouse click
  else if (values[0] == 7) {
    // Perform a mouse click
    Mouse.click();
  }

  // Print the received values to the serial monitor
  Serial.print("Received values: ");
  for (int i = 0; i < 5; i++) {
    Serial.print(values[i]);
    Serial.print(" ");
  }
  Serial.println();
}
