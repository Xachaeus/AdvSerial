#include <Arduino.h>
#include "AdvSerial.h"

AdvSerial::AdvSerial(char end_char='\n')
{
  _end_char = end_char;
}

String AdvSerial::Read()
{
  bool ended = false;
  String returnString = "";
  
  while (not ended)
  {
    while (not Serial.available()){}
    char in = Serial.read();
    if(in == _end_char) { return returnString; ended = true;}
    returnString += in;
    
  }
}

String AdvSerial::Background_Read()
{
  while (Serial.available())
  {
    char in = Serial.read();
    if (in == _end_char)
    {
      String temp = _backgroundString;
      _backgroundString = "";
      return temp;
    }
    _backgroundString += in;
  }
  return "";
}