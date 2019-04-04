/* -----------------------------------------------------------------
 * Fork from :
 * 
 * Button
 * https://github.com/madleech/Button
 * Button - a small library for Arduino to handle button debouncing
 * 
 * MIT licensed.
 * 
 * Copyright (c) 2016 Michael D K Adams 
 * 
 * -----------------------------------------------------------------
 * Modified by Eric Paquot, 03-2019
 * -----------------------------------------------------------------
*/

#include <Arduino.h>
#include "Button.h"



Button::Button(uint8_t pin):
  _pin(pin),
  _state(RELEASED),
  _changed(false),
  _debounce_ms(0)
{
}

void Button::begin()
{
#ifdef BUTTON_PULLUP
  pinMode(_pin, INPUT_PULLUP);
#else
  pinMode(_pin, INPUT);
#endif
}



// ======== public methods ========

bool Button::changed()
{
  // true:  button has changed after a read()
  // Can be used to reinit BButton state

  if (!_changed) return false;

  _changed = false;
  return true;
}

bool Button::read()
{
  // read the current Button then set its states
  
  if (_debounce_ms < millis())   // debouncing
  {
    if (digitalRead(_pin) != _state)  // pin has changed
    {
      _debounce_ms  = millis() + BOUTTON_DELAY;
      _state        = !_state;
      _changed      = true;
    }
  }

  return _state;
}

bool Button::toggled()
{
  // true:  toggled from on/off~off/on
  // false: no change

  read();
  return changed();
}

bool Button::pressed()
{
  // true:  button gone from off -> on

  if (read() == PRESSED && changed())   return true;
  return false;
}

uint32_t Button::pressedFor()
{
  // how long in millis the button is on

  if (read() == PRESSED && !changed())  return uint32_t(millis() - _debounce_ms + BOUTTON_DELAY);
  return false;
}

bool Button::released()
{
  // true:  button gone from on -> off

  if (read() == RELEASED && changed())  return true;
  return false;
}

uint32_t Button::releasedFor()
{
  // how long in millis the button is off

  if (read() == RELEASED && !changed()) return uint32_t(millis() - _debounce_ms - BOUTTON_DELAY);
  return false;
}
