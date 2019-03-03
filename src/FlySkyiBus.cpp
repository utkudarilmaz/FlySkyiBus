#ifndef FlySkyiBus
#include "FlySkyiBus.h"
#endif

Frame *FlySkyiBus::read_serial() {

    if (available() >= 32) {
        if (read() == 0x20) {
            Frame *framePtr = new Frame;
            uint8_t buffer[32];
            buffer[0] = 0x20;

            uint8_t i;
            for (i=1; i<32; i++) {
                buffer[i] = read();
            }

            if (FlySkyiBus::frame_validation(framePtr, buffer) == true) {
                FlySkyiBus::set_data(framePtr, buffer);
                return framePtr;
            }
        }
        return read_serial();

    } else {
        delayMicroseconds(7);
        return read_serial();
    }

}

boolean FlySkyiBus::frame_validation(Frame *framePtr, uint8_t *buffer) {

    uint8_t i;

    for (i=0; i<30; i++) {
        framePtr->checksum -= buffer[i];
    }
    framePtr->rxChecksum = buffer[30] + (buffer[31] << 8);

    if (framePtr->rxChecksum == framePtr->checksum) {
        return true;
    } else {
        return false;
    }
}

void FlySkyiBus::set_data(Frame *framePtr, uint8_t *buffer) {

    uint8_t i;

    for (i=1; i<15; i++) {
        framePtr->data[i-1] = buffer[i * 2] + (buffer[i * 2 + 1] << 8);
    }
}
