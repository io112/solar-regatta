//
// Created by gamiy on 30.09.2021.
//

#ifndef SOLAR_MOTOR_H
#define SOLAR_MOTOR_H

#include <Arduino.h>
#include "telemetry.h"

namespace Motor {
#define revolutionMeter A2
#define tempSensor A0

    void getRevolutions();
    void getTemp();
    void read();
}

#endif //SOLAR_MOTOR_H
