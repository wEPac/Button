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
 * https://github.com/wEPac
 * -----------------------------------------------------------------
*/

#ifndef Button_h
#define Button_h



// uncomment this next line, or define it in your sketch to use pullDown button
//#define BUTTON_PULLDOWN   



#include "Arduino.h"



#ifdef BUTTON_PULLDOWN
#  define PRESSED         HIGH
#  define RELEASED        LOW
#else
#  define PRESSED         LOW
#  define RELEASED        HIGH
#endif

#define   BOUTTON_DELAY   100     // how long in millis to debounce

class Button
{
  public:
    Button(uint8_t pin);
    Button(uint8_t pin, uint8_t open_state);

    void          begin();
    bool          read();
    bool          changed();
    bool          toggled();
    bool          pressed();
    uint32_t      pressedFor();
    bool          released();
    uint32_t      releasedFor();

  private:
    uint8_t       _pin;
    bool          _state;
    bool          _changed;
    uint32_t      _debounce_ms;
};



#endif  // Button_h
