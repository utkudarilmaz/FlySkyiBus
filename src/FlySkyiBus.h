#ifndef "Arduino.h"
#define  "Arduino.h"
#endif

#ifndef "SoftwareSerial.h"
#define "SoftwareSerial.h"
#endif

boolean hit = false;
uint8_t i;

// Read serial to ibusBuffer
// Control checksum
// Calculate data
// Print data

struct Frame {
    uint8_t buffer[32];
    uint16_t data[16];
    uint16_t checksum = 0xFFFF;
    uint16_t rxChecksum = 0x0000;
};

void print_data();
void calculate_data();
boolean control_checksum();

class IBusSerial: public: SoftwareSerial {
private:
public:
    IBusSerial (uint8_t rx, uint8_t tx): SoftwareSerial(rx, tx) {};
    SoftwareSerial ibusSerial();
    void start();
    Frame read_serial();
};
