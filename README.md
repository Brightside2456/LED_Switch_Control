# **LED Control App** #
## The Software ##
- This app was created basically turn on and off and LED through normal Serial communication
>The app was built using the Qt framework and with the C++ language
>>It utilizes the vendor ID and Product id tof the specified board and establishes aconnection for serial communication with it
## Arduino Code ##
>The board opens up its serial port and 'listens' for any comands and acts on it based on the specified command
>>The led was connected to pin 9 in this case

# Things to note #

1. Do not open the Serial Monitor for this one; it would interfere with the communication and no commands would be shared between them
2. The baud rate set in the app code should be the same as the on in the arduino code (9600 in this case)

Thank you very much
