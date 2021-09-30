//
// Created by gamiy on 30.09.2021.
//
#include <Arduino.h>
#include <TroykaGPS.h>
#include <MicroNMEA.h>
#include "dispaly.h"
#include "log.h"

#ifndef SOLAR_SATELLITES_H
#define SOLAR_SATELLITES_H

namespace Satellites {
#define MAX_SIZE_MASS 16  // задаём размер массива для времени, даты, широты и долготы

    class Point {
        String time;
        float lat;
        float lng;
        float speed;
    };

    void init(int baudRate);

    void read();
}

#endif //SOLAR_SATELLITES_H
