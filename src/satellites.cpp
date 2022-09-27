#include "satellites.h"


namespace Satellites {
    //радиус Земли
    unsigned long R = 6371e3;

    // допуск в метрах к расстоянию между
    // текущей точкой и точкой отсчета
    unsigned long tolerance = 5;

    // время в миллисекундах сколько нужно находиться в
    // пределах допуска для изменения состояния
    unsigned long toleranceTime = 5;

    // Текущее состояние находимся ли мы в радиусе допуска
    bool state = false;
    bool pendingState = false;
    unsigned long stateChange = 0;

    Point PointA;
    Point CurrentPoint;

    unsigned long laps = 0;

    char buffer[100];
    MicroNMEA nmea(buffer, sizeof(buffer));


    void printUnknownSentence(MicroNMEA &nmea) {
        Log::warn(String("unknownSentence: ") + nmea.getSentence(), SATELLITES_MODULE);
    }

    double toRadians(double val) {
        return (M_PI / 180) * val;
    }


    // distance возвращает расстояние между точками в метрах
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


    void logCoords() {
        Log::monitor("coords: lat: " + String(CurrentPoint.lat) + ", lng: " + String(CurrentPoint.lng),
                     SATELLITES_MODULE);

    }

    // выводим установленную точку
    void printPointA() {
        //Display::pointA(PointA.lat, PointA.lng);

    }

    // выводим количество видимых спутников
    void printSatellites() {
        Telemetry::SatellitesNum(nmea.getNumSatellites());
        Log::info(String(nmea.getNumSatellites()), SATELLITES_MODULE);
        logCoords();
        Serial.println(nmea.getNumSatellites());
    }

    // выводим текущее время
    void printTime() {
        char *c = new char[16];
        sprintf(c, "%d:%d:%d", nmea.getYear(), nmea.getMonth(), nmea.getDay());
        Telemetry::CreatedAt(c);
        Serial.println(c);
    }

    // выводим текущую скорость
    void printSpeed() {
        //Telemetry::Speed(float(nmea.getSpeed()));
    }

    // выводим расстояние до точки отсчета
    void printDistance() {
        //Display::distance(float(distance(PointA, CurrentPoint)));
    }

    // выводим количество кругов
    void printLaps() {
        //Display::laps(laps);
    }


    void setPoint() {
        PointA = CurrentPoint;
    }

    void readCurrentPoint() {
        CurrentPoint.lat = double(nmea.getLatitude()) / 1000000;
        CurrentPoint.lng = double(nmea.getLongitude()) / 1000000;
        Telemetry::PositionLat(CurrentPoint.lat);
        Telemetry::PositionLng(CurrentPoint.lng);
        Serial.println(String(CurrentPoint.lat)+" "+String(CurrentPoint.lng));
       // Serial.println(double(nmea.getLatitude()) / 1000000);
        //Serial.println(String(1234567.0/100000));
    }

    void checkLap() {
        double dist = distance(PointA, CurrentPoint);
        bool oldPendingState = pendingState;
        bool oldState = state;
        if (dist < tolerance) {
            pendingState = true;
        } else {
            pendingState = false;
        }
        if (pendingState != oldPendingState) {
            stateChange = millis();
            return;
        }
        if (pendingState != state) {
            if (millis() - stateChange > toleranceTime) {
                state = pendingState;
            }
        }
        if (!oldState && state) {
            laps++;
        }
    }


    void read() {
        if (!SATELLITES_ENABLED) {
            return;
        }
        if (GPS_SERIAL.available()) {  // считываем данные и парсим
            //Serial.println("gps_start");
            char c = GPS_SERIAL.read();
            if (nmea.process(c)) {
                readCurrentPoint();
                checkLap();
                printLaps();
                printPointA();
                printSatellites();
                printTime();
                printSpeed();
                printDistance();
            }
        }
    }


}