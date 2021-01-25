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
#endif