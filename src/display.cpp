#include "dispaly.h"
#include <WString.h>

namespace Display {
    char buffer[80];

    void init(unsigned long baud) {
        if (DISPLAY_ENABLED) {
            RaspberrySerial.begin(baud);  // открываем Serial-соединение с Nextion-модулем
            Log::debug("display started", DISPLAY_MODULE);
        }
    }

    void commandEnd() {                     // команда поступающая в дисплей должна кончаться символами «0xFF0xFF0xFF»
        for (int i = 0; i < 3; i++) {
            RaspberrySerial.write(0xff);
        }
        Log::debug("command end", "");
    }

    void send(String name, String type, String value) {
        sprintf(buffer, "%s.%s=\"%s\"", name.c_str(), type.c_str(), value.c_str());
        RaspberrySerial.print(buffer);
        Log::monitor(buffer, DISPLAY_MODULE);
        // TODO: send to external
        commandEnd();
    }

    void resetPoints() {  // сброс точек
        send("t30", "txt", "0");
        send("t31", "txt", "0");
        send("t32", "txt", "0");
        send("t33", "txt", "0");
    }


    void controllerWatts(long value) {
        send("t3", "txt", String(value) + " W");
    }

    void timeToGo(String value) {
        send("t4", "txt", value);

    }

    void controllerVolts(long value) {
        send("t13", "txt", String(value) + " V");

    }

    void controllerTemp(double value) {
        send("t11", "txt", String(value) + " C");
        send("j1", "val", String(value));

    }

    void MPPTVolts(long value) {
        send("t6", "txt", String(value) + " V");

    }

    void MPPTWatt(long value) {
        send("t0", "txt", String(value) + " W");

    }

    void motorTemp(double temp) {
        send("t12", "txt", String(temp) + " C");
        send("j0", "val", String(temp));
    }

    void motorRevols(int revols) {
        send("t5", "txt", String(revols));
    }


    void distance(long dist) {  // установка точки б
        send("n5", "val", String(dist));
    }

    void satellitesNum(int number) {
        send("n30", "val", String(number));
    }

    void pointA(float lat, float lng) {
        send("t30", "txt", String(lat));
        send("t31", "txt", String(lng));
    }

    void laps(float laps) {
        // TODO: print laps number
    }

    void speed(float value) {
        send("t5", "txt", String(value) + " КМ/Ч");
    }

    void time(String time) {
        send("t7", "txt", time);
    }


    String read() {
        if (!DISPLAY_ENABLED)
            return "";
        String data = "";
        while (RaspberrySerial.available()) { // TODO: one bit one cicle
            data += char(RaspberrySerial.read());
            //Serial.println(dataDisplay.length());
        }
        if (data) {
            return data;
        }
        return String("");
    }

}


