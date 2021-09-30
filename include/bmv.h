#ifndef SOLAR_BMV_H
#define SOLAR_BMV_H

#include <Arduino.h>
#include <WString.h>
#include "storage.h"
#include "dispaly.h"


namespace BMV {
#define bmv           Serial3 // // serial-порт к которому подключён BMV702 (battery monitor)

    void read();
}

#endif //SOLAR_BMV_H
