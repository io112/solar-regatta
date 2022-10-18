#ifndef SOLAR_BMV_H
#define SOLAR_BMV_H

#include <SoftwareSerial.h>
#include <Arduino.h>
#include <WString.h>
#include "telemetry.h"
#include "define.h"

namespace BMV {
    const String WATTS_KEY = "P";
    const String VOLTS_KEY = "V";
    const String TIME_TO_GO_KEY = "TTG";

    void init(unsigned long baudRate);

    void read();
}

#endif //SOLAR_BMV_H
