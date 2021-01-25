#ifndef ADVSERIAL_H
#define ADVSERIAL_H

#include <Arduino.h>

class AdvSerial
{
public:
  AdvSerial(char end_char='\n', int max_length=128);
  String Read();
  
  
  
private:
  char _end_char;
  int _max_length;
  char* in_array;
};
#endif
