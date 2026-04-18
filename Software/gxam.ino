#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int counter = 0;
bool last_up = HIGH;
const int switch_pin_up = D3;

void setup() {
  pinMode(switch_pin_up, INPUT_PULLUP);
  delay(500);
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  display.clearDisplay();
}

void loop() {
  count(switch_pin_up, last_up);

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 8);
  display.println(counter);
  display.display();
}

int count(switch_pin, last_state) {
  bool current_state == digitalRead(switch_pin) == LOW

  if(last_state == HIGH && current_state == LOW){
    last_state = current_state;
    return true;
  }

  last_state = current_state;
  return false;
}
