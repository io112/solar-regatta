//
// Created by gamiy on 30.09.2021.
//

#ifndef SOLAR_MOTOR_H
#define SOLAR_MOTOR_H

#include <Arduino.h>
#include "dispaly.h"

namespace Motor {
#define revolutionMeter A2
#define tempSensor A0

    int getRevolutions();
    double getTemp();
}

#endif //SOLAR_MOTOR_H
