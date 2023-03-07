#include <Arduino.h>
#include <WString.h>
#include <RF24.h>
#include <nRF24L01.h>
#include "define.h"


#ifndef SOLAR_REGATTA_TRANSMITTER_H
#define SOLAR_REGATTA_TRANSMITTER_H

namespace Transmitter {
#define PIN_CE 10 //Номер пина, к которому подключен вывод CE
#define PIN_CSN 9 //Номер пина, к которому подключен вывод CSN
#define TRANSMITTER_BUFFER_SIZE 32

    const String PAYLOAD_REQUEST = "Waiting for a new Payload";
    const String PAYLOAD_RECEIVED = "Got a new Payload";
    const String PAYLOAD_SENDING = "Start Sending";
    const String PAYLOAD_SENT = "Sent";


    void init();

    void receiveData();

    void splitAndTransmit();

    void read();
}

#endif //SOLAR_REGATTA_TRANSMITTER_H
