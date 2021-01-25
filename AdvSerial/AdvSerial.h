#ifndef ADVSERIAL_H
#define ADVSERIAL_H

#include <Arduino.h>

class AdvSerial
{
public:
  AdvSerial(char end_char='\n');
  String Read();
  String Background_Read();
  
  
  
private:
  char _end_char;
  String _backgroundString;
};

AdvSerial::AdvSerial(char end_char)
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
#endif