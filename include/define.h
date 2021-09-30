#include <Arduino.h>

#ifndef SOLAR_DEFINE_H
#define SOLAR_DEFINE_H

// SERIALS
#define MainSerial          Serial
#define GPS_SERIAL          Serial1  // serial-порт к которому подключён GPS-модуль
#define DisplaySerial       Serial2   // serial-порт к которому подключён Nextion-экран
#define BmvSerial           Serial3 // // serial-порт к которому подключён BMV702 (battery monitor)


// ENABLE MODULES
#define SATELLITES_ENABLED  1
#define DISPLAY_ENABLED     1
#define BMV_ENABLED         0
#define MPPT_ENABLED        0
#define STORAGE_ENABLED     0


// MODULE NAMES
#define SATELLITES_MODULE   "SATELLITES"
#define BMV_MODULE          "BMV"
#define CONTROLLER_MODULE   "CONTROLLER"
#define DISPLAY_MODULE      "DISPLAY"
#define MOTOR_MODULE        "MOTOR"
#define MPPT_MODULE         "MPPT"
#define STORAGE_MODULE      "STORAGE"
#define MAIN_MODULE         "MAIN"

#define LOG_LEVEL 1
#endif //SOLAR_DEFINE_H
