/*
  Send an SMS with the SparkFun LTE Cat M1/NB-IoT Shield
  By: Don Hagen
  Date: February 29, 2020

  Adopted from the SparkFun SMS_Send example sketch
  
  License: This code is public domain but you buy me a beer if you use this 
  and we meet someday (Beerware license).
  Feel like supporting our work? Buy a board from SparkFun!
  https://www.sparkfun.com/products/14997

  This example demonstrates how to read an SMS message with the LTE Shield.

  Before beginning, you should have your shield connected on a MNO.
  See example 00 for help with that.

  Once programmed, open the serial monitor, set the baud rate to 9600,
  and type the index of the message you would like to read that is stored on your shield.
  
  Hardware Connections:
  Attach the SparkFun LTE Cat M1/NB-IoT Shield to your Arduino
  Power the shield with your Arduino -- ensure the PWR_SEL switch is in
    the "ARDUINO" position.
*/

//Click here to get the library: http://librarymanager/All#SparkFun_LTE_Shield_Arduino_Library
#include <SparkFun_LTE_Shield_Arduino_Library.h>

// Create a SoftwareSerial object to pass to the LTE_Shield library
SoftwareSerial lteSerial(8, 9);
// Create a LTE_Shield object to use throughout the sketch
LTE_Shield lte;

void setup() {
  Serial.begin(9600);

  if ( lte.begin(lteSerial, 9600) ) {
    Serial.println(F("LTE Shield connected!"));
  }
  Serial.println(F("Choose an SMS index, press enter to read: "));
}

void loop() {
  static String index = "";
  if (Serial.available())
  {
    char c = Serial.read();
    // Read an index until a \n (newline) is received
    if (c == '\n') {
      // Once we receive a newline, read the message at the specified index
      Serial.println("Message: ");
      Serial.println();
      
      Serial.println(lte.readSMS(index));

      Serial.println();
      
      index = ""; // Clear message string
    } else {
      index += c; // Add last character to message
    }
  }
}
