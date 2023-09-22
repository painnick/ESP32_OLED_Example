/*********
  Rui Santos
  Complete project details at https://randomnerdtutorials.com
*********/

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define I2C_Freq 100000

#define SDA_0 15 // 21
#define SCL_0 4 // 22

TwoWire I2C_0 = TwoWire(0);

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &I2C_0, -1);

void setup() {

    I2C_0.begin(SDA_0, SCL_0, I2C_Freq);

    Serial.begin(115200);

    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C, false, false)) { // Address 0x3D for 128x64
        Serial.println(F("SSD1306 allocation failed"));
        for (;;);
    }
    delay(2000);
    display.clearDisplay();

    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 10);
    // Display static text
    display.println("Hello, world!");
    display.display();
}

static int count = 0;
unsigned long lastChecked = 0;

void loop() {
    unsigned long now = millis();

    if (now - lastChecked > 1000) {
        lastChecked = now;

        count++;

        display.clearDisplay();
        display.setTextColor(WHITE);
        display.setCursor(0, 10);
        // Display static text
        display.print("Count ");
        display.print(count);
        display.display();
    }
}