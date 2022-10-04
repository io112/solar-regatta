#include <Arduino.h>
#include <GyverWDT.h>
#include "satellites.h"
#include "bmv.h"
#include "mppt.h"
#include "motor.h"
#include "controller.h"
#include "external.h"
#include "define.h"
#include "telemetry.h"
#include "SPI.h"


void setup() {
    MainSerial.begin(9600);
    Telemetry::init(115200);
    BMV::init(19200);
    MPPT::init(19200);
    Satellites::init(9600);

    Watchdog.enable(RESET_MODE, WDT_PRESCALER_512); // Режим сторжевого сброса , таймаут ~4с


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
    Controller::read();
    Motor::read();
    Satellites::read();
    MPPT::read();
    BMV::read();
    Telemetry::GetJSON();

    //Serial.println(GPS_SERIAL.available());

    Watchdog.reset(); // Переодический сброс watchdog, означающий, что устройство не зависло
}

