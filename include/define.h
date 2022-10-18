#include <Arduino.h>

#ifndef SOLAR_DEFINE_H
#define SOLAR_DEFINE_H

// SERIALS
#define MainSerial          Serial1
#define GPS_SERIAL          Serial3     // serial-порт к которому подключён GPS-модуль
#define RaspberrySerial       Serial     // serial-порт к которому подключён Raspberry
#define mpptSerial           Serial2     // serial-порт к которому подключён MPPT контроллер
#define ExternalSerial      Serial1      // serial-порт к которому подключён BMV702 (battery monitor)


// ENABLE MODULES
#define SATELLITES_ENABLED  1
#define BMV_ENABLED         1
#define MPPT_ENABLED        1
#define STORAGE_ENABLED     0


// MODULE NAMES
#define SATELLITES_MODULE   "SATELLITES"
#define BMV_MODULE          "BMV"
#define CONTROLLER_MODULE   "CONTROLLER"
#define MOTOR_MODULE        "MOTOR"
#define MPPT_MODULE         "MPPT"
#define STORAGE_MODULE      "STORAGE"
#define MAIN_MODULE         "MAIN"

// COMMANDS
#define COMMAND_REMEMBER    "set_point_A"

#define LOG_LEVEL 10
#endif //SOLAR_DEFINE_H
