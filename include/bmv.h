#ifndef SOLAR_BMV_H
#define SOLAR_BMV_H

#include <SoftwareSerial.h>
#include <Arduino.h>
#include <WString.h>
#include "storage.h"
#include "dispaly.h"
#include "define.h"

namespace BMV {

    void init(unsigned long baudRate);

    void read();
}

#endif //SOLAR_BMV_H
