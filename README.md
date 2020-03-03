# readSMS

This is a library update for the SparkFun LTE Cat M1/NB-IoT Shield.
I have added a readSMS function that reads SMS messages that are saved to the shield.
The clear message function is working. Calling lte.clearMessages() erases all messages from the shield. 
I have included an example sketch to get it working.

The readSMS function takes in one parameter, the index you want to retrieve a message from. Just make sure you don't ask for an empty
index or you won't get anything useful out of it. I wanted to get this up for others to use and tinker with, so there may be bugs I 
didn't catch. 

The clearMessages function takes one parameter. When called, it clears all messages from the SARA modem according to the flag you provide as a string "0", "1", "2", "3", "4".

The getSMS function takes an index parameter and returns a struct with a phone number string and message content string. 

Examples for getSMS and readSMS are included in the examples folder and should be accessible if the library is installed in the Arduino IDE. 

This was a volunteer effort to help others better use their shields and make cool stuff. 
