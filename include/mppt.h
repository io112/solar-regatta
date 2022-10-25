//
// Created by gamiy on 30.09.2021.
//

#ifndef SOLAR_MPPT_H
#define SOLAR_MPPT_H

#include <SoftwareSerial.h>
#include <Arduino.h>
#include <WString.h>
#include "define.h"
#include "telemetry.h"

namespace MPPT {
    const String WATTS_KEY = "PPV";
    const String VOLTS_KEY = "V";

    void init(unsigned long baudRate);

    void read();

}
#endif //SOLAR_MPPT_H
