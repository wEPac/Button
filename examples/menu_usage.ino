#include "Button.h"


#define  SETTING_TIMEOUT  60000   // how long before to abort setting mode (in millis)
#define  TOUCH_DOWN       1000    // how long for a long touch (in millis)
#define  TOUCH_TIMEOUT    500     // how long between a touch repeat (in millis)


Button BUT1(A0); // Connect your button between pin A0 and GND
Button BUT2(A1); // Connect your button between pin A1 and GND
Button BUT3(A2); // Connect your button between pin A2 and GND
Button BUT4(A3); // Connect your button between pin A3 and GND

void setup()
{
  BUT1.begin();
  BUT2.begin();
  BUT3.begin();
  BUT4.begin();

  Serial.begin(9600);
}

void loop()
{
  if      (BUT1.pressedFor() > TOUCH_DOWN)   // enter in setting mode 1
  {
    if (SettingMode1()) Serial.println("<=== Setting1 valided");
    else                Serial.println("<=== Setting1 aborted");

    while (!BUT1.toggled());  // wait to release the button
  }
  else if (BUT1.released()) // quick command 1
  {
    Serial.println("Quick command 1");
  }

  if      (BUT2.pressedFor() > TOUCH_DOWN)
  {
    Serial.println("Long command 2");
    while (!BUT2.toggled());  // wait to release the button
  }
  else if (BUT2.released())
  {
    Serial.println("Quick command 2");
  }

  if      (BUT3.pressedFor() > TOUCH_DOWN)
  {
    Serial.println("Long command 3");
    while (!BUT3.toggled());  // wait to release the button
  }
  else if (BUT3.released())
  {
    Serial.println("Quick command 3");
  }

  if      (BUT4.pressedFor() > TOUCH_DOWN)   // enter in setting mode 4
  {
    Serial.println("Long command 4");
    while (!BUT4.toggled());  // wait to release the button
  }
  else if (BUT4.released())
  {
    Serial.println("Quick command 4");
  }
}

bool SettingMode1()
{
  Serial.println("===> start Setting1 mode");
  while (!BUT1.toggled());  // wait to release the button

  unsigned long timerStamp = millis();
  byte          steps_max  = 2;
  byte          steps      = 0;
  while ((unsigned long)(millis() - timerStamp) < SETTING_TIMEOUT)
  {
    byte inc = true;
    if      (BUT1.pressedFor() > TOUCH_DOWN) return false;  // abort setting mode 1
    else if (BUT1.released()) // quick command 1
    {
      steps      = (++steps) % steps_max;
      Serial.println("next setting 1 step");
    }
    else if (BUT2.pressedFor() > TOUCH_DOWN)
    {
      Serial.print("setting 1 Long command 2");
      delay(TOUCH_TIMEOUT);
    }
    else if (BUT2.released())
    {
      Serial.print("setting 1 Quick command 2");
    }
    else if (BUT3.pressedFor() > TOUCH_DOWN)
    {
      Serial.print("setting 1 Long command 3");
      delay(TOUCH_TIMEOUT);
    }
    else if (BUT3.released())
    {
      Serial.print("setting 1 Quick command 3");
    }
    else if (BUT4.released()) return true; // valid setting mode 1
    else inc = false;

    if (inc)
    {
      timerStamp = millis();

      switch (steps)
      {
        case 0: Serial.println(" for value A"); break;
        case 1: Serial.println(" for value B"); break;
      }
    }
  }

  return false; // auto return after a while, aborted
}
