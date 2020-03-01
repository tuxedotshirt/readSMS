# readSMS

This is a library update for the SparkFun LTE Cat M1/NB-IoT Shield.
I have added a readSMS function that reads SMS messages that are saved to the shield.
The clear message function is working. Calling lte.clearMessages() erases all messages from the shield. 
I have included an example sketch to get it working.

You will need to buy a phone number through Hologram for this to work properly. It cost me $1/month to secure the number. 

First, you'll need m-center from ublox. Get it here: https://www.u-blox.com/en/product/m-center
Connect your LTE shield to an uno or similar and load up the Serial_Passthrough example to allow m-center to 
communicate directly with the shield. Set up the COM Port in a similar way you would set it up in the Arduino IDE by clicking "Set port". 
Click "Connect" once your port is set up. Clicking "Get info" should now populate a bunch of data on that home screen if 
you're set up correctly. 

Next, on the home screen of m-center click the "AT Terminal" button in the top right. This will let you try out a bunch of AT commands 
and program your modem to do a TON of stuff. We need to enable text message receiving. In the input line below the terminal window 
type: 

at+cpms="ME","ME","ME"

and hit the send button. If you have a new number and haven't texted it yet, the following should be output to the terminal window:

+CPMS: 0,23,0,23,0,23

The zeroes tell you that there are no messages stored. If you send an SMS to your shield and rerun the at+cpms="ME","ME","ME" command, 
the zeroes should turn into ones. This means there is one message stored, and so on. 

The readSMS function takes in one parameter, the index you want to retrieve a message from. Just make sure you don't ask for an empty
index or you won't get anything useful out of it. I wanted to get this up for others to use and tinker with, so there may be bugs I 
didn't catch. 

The clearMessages function does not need any parameters. When called, it clears all messages from the SARA modem.

This was a volunteer effort to help others better use their shields and make cool stuff. 

Other things to work on are new message indication (ring) and error handling for invalid message indices. 
