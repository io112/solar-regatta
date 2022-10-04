#ifndef SOLAR_BMV_H
#define SOLAR_BMV_H

#include <SoftwareSerial.h>
#include <Arduino.h>
#include <WString.h>
#include "telemetry.h"
#include "define.h"

namespace BMV {

    void init(unsigned long baudRate);

    void read();
}

#endif //SOLAR_BMV_H
