#include <Arduino.h>
#include "AdvSerial.h"

AdvSerial::AdvSerial(char end_char, int max_length)
{
  _end_char = end_char;
  _max_length =max_length;
}

String AdvSerial::Read()
{
  int length = 0;
  bool ended = false;
  in_array = (char*) malloc(_max_length * sizeof(char));
  if (in_array == NULL)
  {
    Serial.println("Not enough memory!");
    return NULL;
  }
  
  
  while (not ended)
  {
    while (not Serial.available()){}
    char in = Serial.read();
    in_array[length] = in;
    if(in == _end_char) { ended = true; }
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
  free(in_array);
  return return_string;
}
