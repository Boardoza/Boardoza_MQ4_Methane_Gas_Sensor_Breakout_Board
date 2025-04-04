#include "Arduino.h"

const int AO_Pin=14; // Connect the AO of MQ-4 sensor with analog channel 0 pin (A0) of Arduino
const int DO_Pin=6; // Connect the DO of MQ-4 sensor with digital pin 8 (D8) of Arduino

int threshold; // Create a variable to store the digital output of the MQ-4 sensor
int adcValue; // Create a variable to store the analog output of the MQ-4 sensor
float Vc = 5000.0;
float Rl = 1000.0;
const float adcStepVoltage = 4.822; // milivolt
float Vrl;
float Rs;
float Ps;
float Ratio;
// Set up
void setup() {
Serial.begin(115200);  // Initialize serial monitor using a baud rate of 115200
pinMode(DO_Pin, INPUT); // Set the D8 pin as a digital input pin

}
 
// Main loop
void loop()
{
adcValue= analogRead(AO_Pin); // Read the analog output measurement sample from the MQ4 sensor's AO pin
threshold = digitalRead(DO_Pin); // Read the digital output of MQ-4 sensor's DO pin

Vrl = adcStepVoltage * adcValue;

Rs = (Vc / (Vrl - 1000.0)) * Rl;

Ps = ((Vc * Vc) * (Rs / ((Rs + Rl) * (Rs + Rl))));

Serial.print("Threshold: "); // Print out the text "Threshold: "
Serial.print(threshold);// Print the threshold reached - with will either print be LOW or HIGH (above or underneath)
Serial.print(", "); // print a comma and space
 
Serial.print("Methane Conentration: "); // Print out the text "Methane Concentration: "
Serial.print(adcValue); // Print out the methane value - the analog output - beteewn 0 and 1023
Serial.print("   ");
Serial.println(Rs); // Print out the methane value - the analog output - beteewn 0 and 1023
 
 

delay(1000); // Set a 10 second delay
}