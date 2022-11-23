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
#define RECEIVED_STRING_SIZE 432
#define TRANSMITTER_BUFFER_SIZE 32

    void transmit(String val);

    void init();

    void receiveData();

    void splitAndTransmit();

    void read();
}

#endif //SOLAR_REGATTA_TRANSMITTER_H
