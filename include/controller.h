//
// Created by gamiy on 30.09.2021.
//

#ifndef SOLAR_CONTROLLER_H
#define SOLAR_CONTROLLER_H

#include <Arduino.h>
#include "telemetry.h"
#include "utils.h"
#include "log.h"

namespace Controller {
#define controller_temp_sensor A1

    void getTemp();

    double countTemp(double resistOm);

    void readSensors();

    void init();

    void read();
}

#endif //SOLAR_CONTROLLER_H
