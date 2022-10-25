//
// Created by gamiy on 30.09.2021.
//

#ifndef SOLAR_MOTOR_H
#define SOLAR_MOTOR_H

#include <Arduino.h>
#include "telemetry.h"
#include "log.h"
#include "utils.h"

namespace Motor {
#define revolutionMeter A2
#define tempSensor A0
    // ---for rotation sensor------------------
    const unsigned long MILLIS_IN_MINUTE = 1000;
    const unsigned long DELAY_MILLIS = 1000;

    const short edge_black = 800;
    const short edge_white = 700;

    double countRevolutionsPerMin(unsigned long revols, unsigned long measureTime);
    void getRevolutions();
    void getTemp();
    void read();
    void init();
    void readSensors();
}

#endif //SOLAR_MOTOR_H
