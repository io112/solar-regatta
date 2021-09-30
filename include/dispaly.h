#ifndef SOLAR_DISPALY_H
#define SOLAR_DISPALY_H

#include <Arduino.h>

namespace Display {
#define display       Serial2   // serial-порт к которому подключён Nextion-экран

    String readCommand();

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
}

#endif //SOLAR_DISPALY_H
