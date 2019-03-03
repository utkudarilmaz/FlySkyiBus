#ifndef "FlySkyiBus.h"
#define "FlySkyiBus.h"
#endif

#ifndef "Arduino.h"
#define  "Arduino.h"
#endif

Frame* IBusSerial::read_serial() {
    Frame *frame = new Frame;
    if (iBus->available()>32) {
        while(1){
            if (ibus->read() == 0x20) {

                frame->buffer[0] = 0x20;

                for (uint8_t i=1; i<32; i++) {
                    frame->buffer[i] = ibus->read();
                }

                return frame;
            } else continue;
        }
    } else delayMicroseconds(7.7);
}
