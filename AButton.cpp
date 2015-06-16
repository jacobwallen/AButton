#include "Arduino.h"
#include "AButton.h"

AButton::AButton(int buttonPin, bool mode)
{
  _buttonPin = buttonPin;
  _mode = mode;
  if (_mode == 0) {pinMode(_buttonPin, INPUT);}
  else {pinMode(_buttonPin, INPUT_PULLUP);}
  _pressed = false;
  _pushed = false;
  _released = false;
  _lastState;
  _force = false;
  Serial.print("\n");
  Serial.print(_mode);
  Serial.print("\n");
}

void AButton::read()
{
  if (_mode == 0) // If mode is INPUT
  {
    _pressed = digitalRead(_buttonPin);
  }
  else  // If mode is INPUT_PULLUP
  {
    _pressed = !digitalRead(_buttonPin);
  }

  // Check if button qualifies for released
  if (_lastState && !_pressed) {_released = true;}
  else {_released = false;}

  // Check if button qualifies for pushed
  if (!_lastState && _pressed) {_pushed = true;}
  else {_pushed = false;}

  _lastState = _pressed;
}

bool AButton::pressed()
{
  return _pressed;
}

bool AButton::pushed()
{
  return _pushed;
}

bool AButton::released()
{
  return _released;
}

void AButton::force_pressed()
{
  _pressed = true;
}
void AButton::force_pushed()
{
  _pushed = true;
}
void AButton::force_released()
{
  _released = true;
}

void AButton::force_all_false()
{
  _pressed = false;
  _pushed = false;
  _released = false;
}
