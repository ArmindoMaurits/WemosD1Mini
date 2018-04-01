/*
 Name:		WemosD1MiniTempSensorSketch.ino
 Created:	4/1/2018 1:10:46 PM
 Author:	A. Maurits
*/

//#include <WEMOS_SHT3X.h>
//
//SHT3X sht30(0x45);

//// the setup function runs once when you press reset or power the board
//void setup() {
//	Serial.begin(115200);
//}
//
//// the loop function runs over and over again until power down or reset
//void loop() {
//	sht30.get();
//	Serial.print("Temperature in Celsius : ");
//	Serial.println(sht30.cTemp);
//	Serial.print("Temperature in Fahrenheit : ");
//	Serial.println(sht30.fTemp);
//	Serial.print("Relative Humidity : ");
//	Serial.println(sht30.humidity);
//	Serial.println();
//	delay(1000);
//}

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_SSD1306.h"
#include <WEMOS_SHT3X.h>

#define OLED_RESET 0  // GPIO0
Adafruit_SSD1306 display(OLED_RESET);
SHT3X sht30(0x45);

void setup() {
	Serial.begin(115200);
	display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 64x48)
	display.display();
}

void loop() {
	sht30.get();
	display.clearDisplay();
	display.setTextSize(1);
	display.setTextColor(WHITE);
	display.setCursor(0, 0);

	display.println("- SHT30 -");
	display.print("T ");
	display.print(sht30.cTemp);
	display.println(" C");

	display.print("H ");
	display.print(sht30.humidity);
	display.println(" %");
	display.println("");
	display.println("AMA");
	display.display();
	delay(2000);
}