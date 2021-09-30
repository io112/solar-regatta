//
// Created by gamiy on 30.09.2021.
//
#include <Arduino.h>
#include <TroykaGPS.h>
#include "dispaly.h"

#ifndef SOLAR_SATELLITES_H
#define SOLAR_SATELLITES_H

namespace Satellites {
#define GPS_SERIAL    Serial1  // serial-порт к которому подключён GPS-модуль
#define MAX_SIZE_MASS 16  // задаём размер массива для времени, даты, широты и долготы


    GPS gps(GPS_SERIAL);  // создаём объект класса GPS и передаём в него объект Serial1



    void sendSatellites();

    void sendpointA();

    void sendpointB();
}

#endif //SOLAR_SATELLITES_H
