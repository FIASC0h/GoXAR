struct Button {
  int pin;
  bool last_state;
};

int counter = 0;
bool last_up = HIGH;
const int switch_pin_up = D3;
const int switch_pin_down = D2;

Button btnUp = { switch_pin_up, HIGH };
Button btnDn = { switch_pin_down, HIGH };


bool wasPressed(Button &btn) {
  bool state = digitalRead(btn.pin);
  bool triggered = (btn.last_state == HIGH && state == LOW);
  btn.last_state = state;
  return triggered;
}