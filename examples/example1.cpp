/* %93 success rate from transmistted data frame.
    This rate testing on 7251 data frame. */

#include "FlySkyiBus.h"

FlySkyiBus ibusSerial(2, 2); // RX, TX

void setup() {
    Serial.begin(115200);
    Serial.println("Welcome!");
    ibusSerial.begin(115200);
}

uint8_t i=0;

void loop() {

    Frame *framePtr = ibusSerial.read_serial();

    for(i=0; i<14; i++){
        Serial.print(framePtr->data[i], DEC);
        Serial.print("\t");
    }
    Serial.print("\n");

    delete framePtr;

}
