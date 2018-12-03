THIS PROJECT IS STILL BEING PUT TOGETHER. 
I'm just getting used to using github as my personal space. rTally will be operational around January 2019

Soon!

 - Allan
 December 1, 2018.
 __________________
 
 
One of the annoying things with using a steadycam rig for live productions (apart from balance, camera roll and the rig’s weight) is the lack of a tally. 

I’ve designed a simple radio tally system that can communicate with up to 8 cameras wirelessly. It uses cheap transmitter/receiver combos available from eBay. They operate in the 600MHz band so check your local regulations. 
You’ll need one transmitter and a receiver for each camera. search for 'WT8' on ebay.
You might already be using these in your production as a wireless com system, so you’re in luck because the tally signal rides on the of the normal audio - on the same channel at the same time! A single UHF channel for audio and 8 camera tally signals. 

The project is called ‘rTally’ (short for Radio Tally). It is now open source on GitHub, so feel free to contribute at https://github.com/allanalderson/rtally

I am in the process of having the PCBs manufactured. email me if you would prefer to purchase one rather than make your own.
allanalderson at icloudcom.


HOW IT WORKS...
The UHF transmitter and receivers are each supplemented with a 5-volt Arduino Mini which must be clocked at 16MHz. 
 The Arduino at the transmitter sends various audio tones (which correspond to tally signals from the desk) which vary in frequency from 10kHz to 20kHz - slightly above what a typical 50 year old human male can hear. These tones are further attenuated at receiver’s the earphone, so they’re quite difficult to hear. 

At the receiver, another Arduino continually samples the audio and performs an FFT to determine which tone peak was received. A second order high pass filter helps ensure signals below 10kHz (the speech part) don’t interfere with the FFT analysis. 
To detect signals at 20kHz, sampling needs to be performed at 40kHz and is the reason that routine needs to run without the Atmega’s hardware interrupt timers (which slows down the code as well as introduces excessive jitter). 
But without these hardware timers running continuously, the Auduino delay() function doesn’t work as expected. So the code is ugly and you’re welcome to improve it. I’m waiting for your Git pull-request. 

Drift was an important consideration in design. The transmitter might be in an air conditioned room while a receiver might be outside in the blazing sun. To get around drift in the Arduino’s local 16MHz oscillator, I decided to ‘lock’ the receiver’s calibration to a reference tone sent by the transmitter and is the reason there are actually 9 tones for 8 cameras. A 10kHz tone performs this action. The receiver will continually track the Ref tone and adjust its FFT algorithm accordingly.  Tones above the Ref are the actual tally data. 

rTally was originally designed to quickly send a byte containing a single bit, but any 8-bit number can be transmitted because the reference tone is also used as a ‘frame marker’ to transfer all previously received bits from temporary memory to a valid output byte. Once this happens and  the temporary has been cleared, new bits are once again added to the temporary byte up until the next reference tone. A typical output byte containing decimal 19 (bits 1,2 & 5) would be sent as:
Ref;tone1;tone2;tone5;Ref. 
Obviously it takes longer to send more bits - but it can be done. 
To do: Some vision mixers allow for a ‘Preview’ signal as well as an ‘On Air’ tally. Ths mode (not yet implemented) means only 4 cameras could be signalled. The first 4 bits being ‘On Air’ tally and bits 5-8 the ‘Ready’ tally.  


If the receiver goes out of range of the transmitter, the previously held byte remains at the output until a Ref tone is heard. 
If a peak tone is detected outside the range of valid tones (i.e. less than 10kHz), the system waits for a few hundred milliseconds before continuing. This might happen if the producers microphone gets bumped or yelled into. 

