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

#ifndef Button_h
#define Button_h



#include "Arduino.h"


#define PRESSED     LOW
#define RELEASED    HIGH

class Button
{
  public:
    Button(uint8_t pin);

    uint8_t     _delay;

    void        begin();
    bool        read();
    bool        toggled();
    bool        pressed();
    uint32_t    pressedFor();
    bool        released();
    uint32_t    releasedFor();

  private:
    uint8_t     _pin;
    bool        _state;
    bool        _changed;
    uint32_t    _debounce_ms;

    bool        changed();
};

#endif
