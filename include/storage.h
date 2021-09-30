//
// Created by gamiy on 30.09.2021.
//

#ifndef SOLAR_STORAGE_H
#define SOLAR_STORAGE_H

#include <Arduino.h>
#include <WString.h>
#include <SD.h>

namespace Storage {
    const int SDchipSelect = 53; // for SD


    int delay_sd_write = 1000; // delay between records in microseconds
    unsigned long sd_read_timestamp;
}

#endif //SOLAR_STORAGE_H
