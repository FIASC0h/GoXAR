#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

struct Button {
  int pin;
  bool last_state;
};

int counter = 0;
bool last_up = HIGH;
const int switch_pin_up = D3;
const int switch_pin_down = D2;

Button count_up_btn = { switch_pin_up, HIGH };
Button count_down_btn = { switch_pin_down, HIGH };


bool wasPressed(Button &btn) {
  bool state = digitalRead(btn.pin);
  bool triggered = (btn.last_state == HIGH && state == LOW);
  btn.last_state = state;
  return triggered;
}

void setup() {
  pinMode(switch_pin_up, INPUT_PULLUP);
  pinMode(switch_pin_down, INPUT_PULLUP);
  delay(500);
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  display.clearDisplay();
}

void loop() {

  if(wasPressed(count_up_btn)){
    counter++;
  }
  if(wasPressed(count_down_btn)){
    counter--;
  }

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 8);
  display.println(counter);
  display.display();
}