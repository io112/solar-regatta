#include "satellites.h"


namespace Satellites {
    char strTime[MAX_SIZE_MASS];  // массив для хранения текущего времени
    char strDate[MAX_SIZE_MASS];  // массив для хранения текущей даты
    char latitudeBase60[MAX_SIZE_MASS];  // массив для хранения широты в градусах, минутах и секундах
    char longitudeBase60[MAX_SIZE_MASS];  // массив для хранения долготы в градусах, минутах и секундах
    unsigned long R = 6371e3;       //радиус Земли
    Point PointA;
    Point PointB;
    Point CurrentPoint;

    float pointA_lat, pointA_long, pointB_lat, pointB_long; // for gps start
    char buffer[100];
    MicroNMEA nmea(buffer, sizeof(buffer));


    void printUnknownSentence(MicroNMEA &nmea) {
        Log::warn(String("unknownSentence: ") + nmea.getSentence(), SATELLITES_MODULE);
    }

    double toRadians(double val) {
        return (M_PI / 180) * val;
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

    double distance(Point p1, Point p2) {
        double phi1 = toRadians(p1.lat);
        double phi2 = toRadians(p2.lat);
        double dphi = toRadians(p2.lat - p1.lat);
        double dalfa = toRadians(p2.lng - p1.lng);


        double a = sin(dphi / 2) * sin(dphi / 2) +
                   cos(phi1) * cos(phi2) *
                   sin(dalfa / 2) * sin(dalfa / 2);

        double c = 2 * atan2(sqrt(a), sqrt(1 - a));

        return R * c;
    }


    void sendpointA() {  // установка точки а
        Display::pointA(PointA.lat, PointA.lng);

    }

    void sendpointB() {  // установка точки б
        Display::pointB(PointB.lat, PointB.lng);
    }

    void sendDistance(Point p1, Point p2) {  // установка точки б
        double dist = distance(p1, p2);
        long distInt = floor(dist);
        Display::distance(distInt);
    }

    void printSatellites() {  // выводим количество видимых спутников
        Display::satellitesNum(nmea.getNumSatellites());
        sendpointA();
        sendpointB();
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

    void rememberPoint() {
        PointA = CurrentPoint;
    }



//    void check_if_starting_line(float lat_now = gps.getLatitudeBase10(), float long_now = gps.getLongitudeBase10()) {
//
//    }


    void read() {
        if (SATELLITES_ENABLED) {
            printTime();
            if (GPS_SERIAL.available()) {  // считываем данные и парсим
                char c = GPS_SERIAL.read();
                if (nmea.process(c)) {
                    printSatellites();
                    logCoords();
                    printTime();
                    CurrentPoint.lat = nmea.getLatitude() / 1000000;
                    CurrentPoint.lng = nmea.getLongitude() / 1000000;
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