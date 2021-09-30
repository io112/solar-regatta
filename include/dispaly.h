#ifndef SOLAR_DISPALY_H
#define SOLAR_DISPALY_H

#include <Arduino.h>
#include "define.h"
#include "log.h"

namespace Display {

    void init(int baudRate);

    String read();

    void resetPoints();

    void controllerWatts(long value);

    void timeToGo(String value);

    void controllerVolts(long value);

    void controllerTemp(double value);

    void MPPTVolts(long value);

    void MPPTWatt(long value);

    void motorTemp(double temp);

    void motorRevols(int revols);

    void distance(int dist);

    void satellitesNum(int number);

    void pointA(float lat, float lng);

    void pointB(float lat, float lng);

    void time(String time);

    void speed(float speed);
}

#endif //SOLAR_DISPALY_H
