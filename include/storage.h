//
// Created by gamiy on 30.09.2021.
//

#ifndef SOLAR_STORAGE_H
#define SOLAR_STORAGE_H

#include <Arduino.h>
#include <WString.h>
#include <SD.h>
#include "log.h"
#include "define.h"

namespace Storage {
#define SDchipSelect  53

    void init();
}

#endif //SOLAR_STORAGE_H
