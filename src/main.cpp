#include <Arduino.h>
#include <GyverWDT.h>
#include "satellites.h"
#include "dispaly.h"
#include "bmv.h"
#include "mppt.h"
#include "motor.h"
#include "controller.h"
#include "define.h"

/* SD CARD ADAPTER
    CS - 10 (changable)
    SCK - 52
    MOSI - 51
    MISO - 50
*/




void setup() {
    MainSerial.begin(9600);
    //Serial.print("Serial init OK\r\n");

    //GPS_SERIAL.begin(9600);  // открываем Serial-соединение с GPS-модулем на скорости 9600 бод

    //GPS_SERIAL.write("$PMTK251,9600*17\r\n");   // используем NMEA-команду «$PMTK251,9600*17\r\n» для оперирования на 9600 бод

    //pinMode(A0,INPUT);
    Display::init(115200);
    BMV::init(19200);
    MPPT::init(19200);
    Satellites::init(9600);

//    Watchdog.enable(RESET_MODE, WDT_PRESCALER_512); // Режим сторжевого сброса , таймаут ~4с

    Storage::init();

    Log::info("-------------setup is done-----------", MAIN_MODULE);
}


void loop() {
//    Serial.println("\nloop start");
//    BMV::read();
//    MPPT::read();
//    String command = Display::read();

//    double motor_temp = Motor::getTemp();
//    Display::motorTemp(motor_temp);
//    Serial.println(motor_temp);


//    double controller_temp = Controller::getTemp();
//    Display::controllerTemp(controller_temp);


//    Motor::getRevolutions();
    Satellites::read();
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
//    Watchdog.reset(); // Переодический сброс watchdog, означающий, что устройство не зависло
}