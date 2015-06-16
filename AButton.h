/*
  AButton.h - Button Abstraction object for Arduino
  Created by Jacob Wallen February, 2015.
*/

#ifndef AButton_h
#define AButton_h

#include "Arduino.h"


class AButton
{
  public:
    AButton(int buttonPin, bool mode); // 0=INPUT, 1=INPUT_PULLUP
    bool pressed();
    bool pushed();
    bool released();
    void read();

    void force_pressed();
    void force_pushed();
    void force_released();
    void force_all_false();

  private:
    int _buttonPin;
    bool _mode;
    bool _pressed;
    bool _pushed;
    bool _released;
    bool _lastState;
    bool _force;
};

#endif
