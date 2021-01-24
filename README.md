# AdvSerial
An arduino library for advanced communication with the serial port. Adds an 
AdvSerial() object that will record incoming serial information until a custom 
delimiter and will return it as an arduino String.

To instantiate the AdvSerial object:

AdvSerial <instance name> = AdvSerial(<delimiter char>);

Syntax:
  <instance name> : The name of the AdvSerial instance.
  <delimiter char> : The char to determine the end of received serial messages.
                     By default, this char is Newline, or '\n'.

To read a full message from the Serial port:

String message = <instance>.read();

Syntax:
  <instance> : An instance of AdvSerial() object.
 
AdvSerial.read() will return an arduino String object containing the received message. 
Note that this function will stop the program until it receives the delimiter that was
set.
