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
#include "transmitter.h"

void setup() {
    MainSerial.begin(9600);
    Telemetry::init(115200);
    BMV::init(19200);
    MPPT::init(19200);
    Satellites::init(9600);
    Transmitter::init();
    Motor::init();
    Controller::init();

    Watchdog.enable(RESET_MODE, WDT_PRESCALER_512); // Режим сторжевого сброса , таймаут ~4с


    Log::info("-------------setup is done-----------", MAIN_MODULE);
}

void loop() {

    Controller::read();
    Motor::read();
    Satellites::read();
    MPPT::read();
    BMV::read();
    Transmitter::read();
    Telemetry::GetJSON();

    Watchdog.reset(); // Периодический сброс watchdog, означающий, что устройство не зависло
}

