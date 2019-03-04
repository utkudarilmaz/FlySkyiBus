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
    boolean frame_validation(Frame*, uint8_t*);
    void set_data(Frame*, uint8_t*);
public:
    FlySkyiBus (uint8_t rx, uint8_t tx): SoftwareSerial(rx, tx) {};
    Frame *read_serial();
    uint16_t get_channel(Frame*, uint8_t);
};
