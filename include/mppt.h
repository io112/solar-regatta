//
// Created by gamiy on 30.09.2021.
//

#ifndef SOLAR_MPPT_H
#define SOLAR_MPPT_H

#include <SoftwareSerial.h>
#include <Arduino.h>
#include <WString.h>
#include "dispaly.h"

namespace MPPT {
    SoftwareSerial mppt(11, 12); // RX, TX

    void read();

}
#endif //SOLAR_MPPT_H
