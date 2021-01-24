#include <Arduino.h>
#include "AdvSerial.h"

AdvSerial::AdvSerial(char end_char='\n')
{
  _end_char = end_char;
}

String AdvSerial::Read()
{
  int length = 0;
  bool ended = false;
  
  while (not ended)
  {
    while (not Serial.available()){}
		in_array[length] = Serial.read();
		if(in_array[length] == _end_char) { ended = true; }
		length++;
  }
  String return_string;
  
  for (int i=0; i<length; i++)
  {
    char Char = in_array[i];
    if (Char != _end_char)
    {
      return_string += Char;
    }
  }
  return return_string;
}