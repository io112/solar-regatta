#include <Arduino.h>
#include <GyverWDT.h>
#include "satellites.h"
#include "dispaly.h"
#include "bmv.h"
#include "mppt.h"
#include "motor.h"
#include "controller.h"

#include <TroykaGPS.h>  // библиотека для работы с GPS устройством

#include <DallasTemperature.h>  // для датчика температуры
#include <OneWire.h>  // для датчика температуры

#include <SoftwareSerial.h>

#include <SPI.h>                // Подключаем библиотеку SPI
#include <SD.h>                 // Подключаем библиотеку SD


/* SD CARD ADAPTER
    CS - 10 (changable)
    SCK - 52
    MOSI - 51
    MISO - 50
*/




void setup() {
    Serial.begin(115200);
    //Serial.print("Serial init OK\r\n");

    //GPS_SERIAL.begin(9600);  // открываем Serial-соединение с GPS-модулем на скорости 9600 бод

    //GPS_SERIAL.write("$PMTK251,9600*17\r\n");   // используем NMEA-команду «$PMTK251,9600*17\r\n» для оперирования на 9600 бод

    //pinMode(A0,INPUT);
    display.begin(115200);  // открываем Serial-соединение с Nextion-модулем
    bmv.begin(19200);
    MPPT::mppt.begin(19200);

    Watchdog.enable(RESET_MODE, WDT_PRESCALER_512); // Режим сторжевого сброса , таймаут ~4с

    while (!SD.begin(Storage::SDchipSelect)) {           //sd init
        Serial.println("SD initialization failed!");
    }
    Serial.println("SD initialization done.");

    Serial.println("-------------setup is done-----------");
}


void loop() {
    Serial.println("\nloop start");
    BMV::read();
    MPPT::read();


    //Serial.println("bmv done");
    //readNextion();
    //Serial.println("nextion done");

    double motor_temp = Motor::getTemp();
    Display::motorTemp(motor_temp);
    Serial.println(motor_temp);


    double controller_temp = Controller::getTemp();
    Display::controllerTemp(controller_temp);
    Serial.println(controller_temp);


    Motor::getRevolutions();
    //Serial.println("motor revols done");

    //sd_write_temp(motor_temp, controller_temp);
    //Serial.println("sd write temp done");

//    update_sd_writing_time();  //!!!!!!



    /*  if(gps.available()){  // считываем данные и парсим
       gps.readParsing();       // проверяем состояние GPS-модуля
       switch(gps.getState()) {
         case GPS_OK:           // всё OK
           Serial.println("GPS IS OK");
           gps.getTime(strTime, MAX_SIZE_MASS);
           //gps.getDate(strDate, MAX_SIZE_MASS);
           sendSatellites();
           write_speed();
           write_time();
           break;
         case GPS_ERROR_DATA:   // ошибка данных
           Serial.println("GPS error data");
           break;

         case GPS_ERROR_SAT:   // нет соединение со спутниками
           Serial.println("GPS no connect to satellites!!!");
           break;
       }
      }
      */
    Watchdog.reset(); // Переодический сброс watchdog, означающий, что устройство не зависло
}