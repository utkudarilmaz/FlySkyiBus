/*
	FlySkyiBus Decoder Library

    iBus protocol total supports 14 channels.
	If you need more channels edit the CHANNEL_SIZE.

    Source code: https://github.com/utkudarilmaz/FlySkyiBus/

    License file added in the root directory.

	Edited 04-04-2019
    Written by Seyit Utku Darılmaz <utkudarilmaz@gmail.com>

*/


#ifndef Arduino
#include  "Arduino.h"
#endif

#ifndef SoftwareSerial
#include "SoftwareSerial.h"
#endif

#define CHANNEL_SIZE 10

struct Frame {
    uint16_t data[CHANNEL_SIZE];
    ~Frame() {
        delete data;
    }
};

class FlySkyiBus: public SoftwareSerial {
private:
    boolean frame_validation(uint8_t*);
    void set_data(Frame*, uint8_t*);
public:
    FlySkyiBus (uint8_t rx, uint8_t tx): SoftwareSerial(rx, tx) {};
    Frame *read_serial();
    static uint16_t get_channel(Frame*, uint8_t);
};
