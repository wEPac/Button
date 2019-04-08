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




#define     BOUTTON_DELAY   100             // how long in millis to debounce

// comment this next line to use button (i.e. sensitive button)
// it doesnt use pullup and it has release state to LOW
//#define   BUTTON_PULLUP                   // button that uses the intern pullup


#ifdef BUTTON_PULLUP
#  define PRESSED         LOW
#  define RELEASED        HIGH
#else
#  define PRESSED         HIGH
#  define RELEASED        LOW
#endif



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
