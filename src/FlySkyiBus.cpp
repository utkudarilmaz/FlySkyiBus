/*
	FlySkyiBus Decoder Library

    iBus protocol total supports 14 channels.
    If you need more channels edit the CHANNEL_SIZE macro where defined in
    FlySkyiBus.h file.

    Source code: https://github.com/utkudarilmaz/FlySkyiBus/

    License file added in the root directory.

    Edited 04-04-2019
    Written by Seyit Utku Darılmaz <utkudarilmaz@gmail.com>

*/

#ifndef FlySkyiBus
#include "FlySkyiBus.h"
#endif


FlySkyiBus::~FlySkyiBus(void) {
    Serial.println("iBus object deleting.");
    delete data;
};

void FlySkyiBus::read_serial(void) {

    if (available() >= 32) {
        if (read() == 0x20) { // Start bit of frame
            uint8_t buffer[32];
            buffer[0] = 0x20;

            uint8_t i;
            for (i=1; i<32; i++) {
                buffer[i] = read();
            }

            if (FlySkyiBus::frame_validation(buffer) == true) {
                FlySkyiBus::set_data(buffer);
                return;
            }
        }
        return read_serial();

    } else {
        delayMicroseconds(7);
        return read_serial();
    }
}

bool FlySkyiBus::frame_validation(uint8_t *buffer) {

    uint8_t i;
    uint16_t checksum = 0xFFFF;
    uint16_t rxChecksum = 0x0000;

    for (i=0; i<30; i++) {
        checksum -= buffer[i];
    }

    rxChecksum = buffer[30] + (buffer[31] << 8);

    if (rxChecksum == checksum) {
        return true;
    } else {
        return false;
    }
}

void FlySkyiBus::set_data(uint8_t *buffer) {

    uint8_t i;

    for (i=1; i<CHANNEL_SIZE+1; i++) {
        data[i-1] = buffer[i * 2] + (buffer[i * 2 + 1] << 8);
    }
}

uint16_t FlySkyiBus::get_channel(uint8_t channel) {
    return data[channel];
}
