#ifndef Arduino
#include  "Arduino.h"
#endif

#ifndef SoftwareSerial
#include "SoftwareSerial.h"
#endif

struct Frame {
    uint16_t data[10];
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
    void start();
    Frame *read_serial();
};
