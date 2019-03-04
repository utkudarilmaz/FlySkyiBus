# FlySky iBus Decoder Library

This library decoding FlySky i6 (not tested) or i6x (tested) tranmistted data.
The used reciever when testing library is FlySky FS-A8S.

Default library supported 10 channels.

## Usage

	git clone https://github.com/utkudarilmaz/FlySkyiBus
	mv FlySkyiBus <arduino-ide>/libraries/

Then import the library to source code.

	#include "FlySkyiBus.h"

	FlySkyiBus iBus(<rx>, <tx>);

	void setup() {
		Serial.begin(9600);
		iBus.begin(115200);
	}

	void loop() {
		Frame *framePtr = iBus.read_serial();
		Serial.print(framePtr->data[<channel>];
		delete framePtr;
	}

## Hacking Library

Normally iBus supported 14 channels communication.

If you need more channels, edit the CHANNEL_SIZE macro on the FlySkyiBus.h
header file.
