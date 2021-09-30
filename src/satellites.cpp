#include "satellites.h"


namespace Satellites {
    char strTime[MAX_SIZE_MASS];  // массив для хранения текущего времени
    char strDate[MAX_SIZE_MASS];  // массив для хранения текущей даты
    char latitudeBase60[MAX_SIZE_MASS];  // массив для хранения широты в градусах, минутах и секундах
    char longitudeBase60[MAX_SIZE_MASS];  // массив для хранения долготы в градусах, минутах и секундах

    float pointA_lat, pointA_long, pointB_lat, pointB_long; // for gps start
    char buffer[100];
    MicroNMEA nmea(buffer, sizeof(buffer));


    void printUnknownSentence(MicroNMEA &nmea) {
        Log::warn(String("unknownSentence: ") + nmea.getSentence(), SATELLITES_MODULE);
    }


    void init(unsigned long baudRate) {
        if (SATELLITES_ENABLED) {
            GPS_SERIAL.begin(baudRate);
            nmea.setUnknownSentenceHandler(printUnknownSentence);
            MicroNMEA::sendSentence(GPS_SERIAL, "$PORZB");
            MicroNMEA::sendSentence(GPS_SERIAL, "$PORZB,RMC,1,GGA,1");
            MicroNMEA::sendSentence(GPS_SERIAL, "$PNVGNME,2,9,1");
            Log::debug("init satellite done", SATELLITES_MODULE);
        }
    }

    float latlng2distance(float lat1, float long1, float lat2, float long2) {
        //радиус Земли
        unsigned long R = 6372795;
        //перевод коордитат в радианы
        lat1 *= 3.14 / 180;
        lat2 *= 3.14 / 180;
        long1 *= 3.14 / 180;
        long2 *= 3.14 / 180;
        //вычисление косинусов и синусов широт и разницы долгот
        float cl1 = cos(lat1);
        float cl2 = cos(lat2);
        float sl1 = sin(lat1);
        float sl2 = sin(lat2);
        float delta = long2 - long1;
        float cdelta = cos(delta);
        float sdelta = sin(delta);
        //вычисления длины большого круга
        float y = sqrt(pow(cl2 * sdelta, 2) + pow(cl1 * sl2 - sl1 * cl2 * cdelta, 2));
        float x = sl1 * sl2 + cl1 * cl2 * cdelta;
        float ad = atan2(y, x);
        float dist = ad * R; //расстояние между двумя координатами в метрах
        return dist;
    }

    void senddistance(float lat1, float long1, float lat2, float long2) {  // установка точки б
        float dist = latlng2distance(lat1, long1, lat2, long2);
        int distInt = floor(dist);
        Display::distance(distInt);
    }

    void printSatellites() {  // выводим количество видимых спутников
        Display::satellitesNum(nmea.getNumSatellites());
        Log::info(String(nmea.getNumSatellites()), SATELLITES_MODULE);
    }

    void printTime() {  // выводим количество видимых спутников
        char *c = new char[16];
        sprintf(c, "%d:%d:%d", nmea.getHour(), nmea.getMinute(), nmea.getSecond());
//        Serial.print(time_now);
        Display::time(c);
    }

    void printSpeed() {  // выводим текущую скорость
        Display::speed(float(nmea.getSpeed()));
    }

    void logCoords() {
        Log::monitor("coords: lat: " + String(nmea.getLatitude()) + ", lng: " + String(nmea.getLongitude()),
                     SATELLITES_MODULE);
    }


    void sendpointA() {  // установка точки а
        //pointA_lat = gps.getLatitudeBase10();
        pointA_lat = 321;
        //pointA_long = gps.getLongitudeBase10();
        pointA_long = 654;

        Display::pointA(pointA_lat, pointA_long);

    }

    void sendpointB() {  // установка точки б
        //pointB_lat = gps.getLatitudeBase10();
        pointB_lat = 123;


        //pointB_long = gps.getLongitudeBase10();
        pointB_long = 456;

        Display::pointB(pointB_lat, pointB_long);
    }


//    void check_if_starting_line(float lat_now = gps.getLatitudeBase10(), float long_now = gps.getLongitudeBase10()) {
//
//    }

    void read() {
        if (SATELLITES_ENABLED) {
            printTime();
            if (GPS_SERIAL.available()) {  // считываем данные и парсим
//                MainSerial.write(GPS_SERIAL.read());
                char c = GPS_SERIAL.read();
//                MainSerial.print(c);
                if (nmea.process(c)) {
//                    if (nmea.getNavSystem())
//                        Log::info(String(nmea.getNavSystem()), SATELLITES_MODULE);
//                    else
//                        Log::info("none", SATELLITES_MODULE);
                    printSatellites();
                    logCoords();
                    printTime();
                }
//                Log::debug(GPS_SERIAL.readString(), SATELLITES_MODULE);
//                gps.readParsing();       // проверяем состояние GPS-модуля
//                Log::info("GPS state: " + String(gps.getState()), SATELLITES_MODULE);
//                switch (gps.getState()) {
//                    case GPS_OK:           // всё OK
//                        Log::info("GPS OK", SATELLITES_MODULE);
//                        gps.getTime(strTime, MAX_SIZE_MASS);
//                        printSatellites();
//                        printSpeed();
//                        printTime();
//                        logCoords();
//                        break;
//                    case GPS_ERROR_DATA:   // ошибка данных
//                        Log::error("GPS error data", SATELLITES_MODULE);
//                        break;
//
//                    case GPS_ERROR_SAT:   // нет соединение со спутниками
//                        Log::warn("GPS no connect to satellites!", SATELLITES_MODULE);
//                        break;
//                }
//            } else {
//                Log::error("GPS not available", SATELLITES_MODULE);
            }
        }

    }


}