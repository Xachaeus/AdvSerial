#ifndef ADVSERIAL_H
#define ADVSERIAL_H

#include <Arduino.h>

class AdvSerial
{
  public:
  AdvSerial(char end_char);
  String Read();
  
  
  
  private:
  char _end_char;
  char in_array[];
};
#endif
