//
// Created by gamiy on 30.09.2021.
//

#ifndef SOLAR_CONTROLLER_H
#define SOLAR_CONTROLLER_H

#include <Arduino.h>

namespace Controller {
#define controller_temp_sensor A1

    int r_controller_temp = 10000;  // resistor for controller temp sensor, om
    double temp_vin = 4.7;   // voltage input used in voltage dividers for temp sensors


    double getTemp();
}

#endif //SOLAR_CONTROLLER_H
