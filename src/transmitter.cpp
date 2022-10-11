#include "transmitter.h"

namespace Transmitter {
    RF24 radio(PIN_CE, PIN_CSN); // Объект radio с указанием выводов CE и CSN

    char recievedString[RECEIVED_STRING_SIZE];
    char buffer[TRANSMITTER_BUFFER_SIZE];
    int index;

    void splitAndTransmit() {
        index = 0;
        for (unsigned int i = 0;
             i < RECEIVED_STRING_SIZE; i += TRANSMITTER_BUFFER_SIZE) { // TODO: not safe, last partition may be lost
            strncpy(buffer, recievedString + i, sizeof(buffer));
            radio.write(&buffer, sizeof(buffer));
        }
    }


    void transmit(String val) {
        val.toCharArray(recievedString, sizeof(recievedString));
        splitAndTransmit();
    }


    void receiveData() {
        if (RaspberrySerial.available() > 0) {
            transmit(RaspberrySerial.readStringUntil('\n'));
        }
    }

    void init() {
        radio.begin();
        radio.setChannel(5);
        radio.setDataRate(RF24_1MBPS);
        radio.setPALevel(RF24_PA_HIGH);
        radio.openWritingPipe(0x7878787878LL);
    }

    void read() {
        receiveData();
    }

}