#include <Arduino.h>
#include <GyverWDT.h>
#include "satellites.h"
#include "dispaly.h"
#include "bmv.h"
#include "mppt.h"
#include "motor.h"
#include "controller.h"
#include "external.h"
#include "define.h"
#include "telemetry.h"

/* SD CARD ADAPTER
    CS - 10 (changable)
    SCK - 52
    MOSI - 51
    MISO - 50
*/




void setup() {
    MainSerial.begin(9600);
    Display::init(115200);
    BMV::init(19200);
    MPPT::init(19200);
    Satellites::init(9600);

    Watchdog.enable(RESET_MODE, WDT_PRESCALER_512); // Режим сторжевого сброса , таймаут ~4с

    Storage::init();

    Log::info("-------------setup is done-----------", MAIN_MODULE);
}

void processCommand(String command) {
    if (command == COMMAND_REMEMBER) {
        Satellites::setPoint();
    }
}

void processExternalData(String data) {
}


void loop() {


    Motor::getRevolutions();
    Satellites::read();
    String command = Display::read();
    String externalData = External::read();
    if (command != "")
        processCommand(command);
    if (externalData != "")
        processExternalData(externalData);

    Telemetry::GetJSON();

    //Serial.println("motor revols done");

    //sd_write_temp(motor_temp, controller_temp);
    //Serial.println("sd write temp done");

//    update_sd_writing_time();  //!!!!!!

    Watchdog.reset(); // Переодический сброс watchdog, означающий, что устройство не зависло
}

