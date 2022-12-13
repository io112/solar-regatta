#include "transmitter.h"

namespace Transmitter {
    RF24 radio(PIN_CE, PIN_CSN); // Объект radio с указанием выводов CE и CSN

    String receivedString;
    int RECEIVED_STRING_SIZE;
    char buffer[TRANSMITTER_BUFFER_SIZE];
    char symbol_start = 1;
    char symbol_stop = 3;

    void splitAndTransmit() {
        radio.write(&symbol_start, sizeof(symbol_start));
        RaspberrySerial.println("Start Sending");
        for (unsigned int i = 0;
             i < RECEIVED_STRING_SIZE; i += TRANSMITTER_BUFFER_SIZE-1) {
            receivedString.substring(i).toCharArray(buffer, TRANSMITTER_BUFFER_SIZE);
            radio.write(&buffer, TRANSMITTER_BUFFER_SIZE);
            delay(50)
        }
        radio.write(&symbol_stop, sizeof(symbol_stop));
        RaspberrySerial.println("Sended");
        RaspberrySerial.println("Waiting for a new Payload");
    }

    void receiveData() {
        if (RaspberrySerial.available() > 0) {
            receivedString = RaspberrySerial.readStringUntil('\n');
            RaspberrySerial.println("Got a new Payload");
            RECEIVED_STRING_SIZE = receivedString.length();
            splitAndTransmit();
        }
    }

    void init() {
        radio.begin();
        radio.setDataRate(RF24_1MBPS);
        radio.setPALevel(RF24_PA_HIGH);
        radio.openWritingPipe(0x7878787878LL);
        RaspberrySerial.println("Waiting for a Payload");
    }

    void read() {
        receiveData();
    }

}