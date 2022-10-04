//
// Created by gamiy on 30.09.2021.
//
#include <Arduino.h>
#include <TroykaGPS.h>
#include <MicroNMEA.h>
#include "telemetry.h"
#include "log.h"
#include "math.h"

#ifndef SOLAR_SATELLITES_H
#define SOLAR_SATELLITES_H

namespace Satellites {
#define MAX_SIZE_MASS 16  // задаём размер массива для времени, даты, широты и долготы

    class Point {
    public:
        String time;
        double lat;
        double lng;
        double speed;
    };

    void init(unsigned long baudRate);

    void read();

    void setPoint();
}

#endif //SOLAR_SATELLITES_H
