# AdvSerial
An arduino library for advanced communication with the serial port. Adds an 
AdvSerial() object that will record incoming serial information until a custom 
delimiter and will return it as an arduino String.

To instantiate the AdvSerial object:

	AdvSerial instance_name = AdvSerial(delimiter_char, maximum_length);

Syntax:

	instance_name : The name of the AdvSerial instance.

	delimiter_char : The char to determine the end of received serial messages.
                     By default, this char is Newline, or '\n'.
	
	maximum_length : The maximum amount of chars that can be sent in a single 
	                 message. This value is 128 by default, but can be raised 
			 or lowered depending on memory usage.

To to wait and receive a full message from the Serial port:

	String message = instance.Read();

Syntax:

	instance : An instance of AdvSerial() object.
 
AdvSerial.Read() will return an arduino String object containing the received message. 
Note that this function will stop the program until it receives the delimiter that was
set.

To wait and receive a full message without stopping the program:
	
	String message = instace.Background_Read();

Syntax:

	instance : An instance of AdvSerial() object.

AdvSerial.Background_Read() will log all incoming serial data to a buffer and return
the buffer as a string when it receives the delimiter. However, Background_Read() will
return an empty string when called until it receives a full message, allowing your 
program to continue running while it collects data in the background.
