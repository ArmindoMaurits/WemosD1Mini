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
	display.print((int) sht30.cTemp);
	display.println(" C");

	display.print("H ");
	display.print((int) sht30.humidity);
	display.println(" %");
	display.println("");
	display.println("AMA");
	display.display();

	Serial.print(sht30.cTemp);

	delay(2000);
}