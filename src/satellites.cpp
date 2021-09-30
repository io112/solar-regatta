#include "satellites.h"


namespace Satellites {
    char strTime[MAX_SIZE_MASS];  // массив для хранения текущего времени
    char strDate[MAX_SIZE_MASS];  // массив для хранения текущей даты
    char latitudeBase60[MAX_SIZE_MASS];  // массив для хранения широты в градусах, минутах и секундах
    char longitudeBase60[MAX_SIZE_MASS];  // массив для хранения долготы в градусах, минутах и секундах

    float pointA_lat, pointA_long, pointB_lat, pointB_long; // for gps start
    GPS gps(GPS_SERIAL);  // создаём объект класса GPS и передаём в него объект Serial1



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

    void sendSatellites() {  // выводим количество видимых спутников
        Display::satellitesNum(gps.getSat());
    }

    void write_time() {  // выводим количество видимых спутников
        gps.getTime(strTime, MAX_SIZE_MASS);
        String time_now = String(gps.getHour()) + ':' + String(gps.getMinute()) + ':' + String(gps.getSecond());
        Serial.print(time_now);
        Display::time(time_now);
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


    void check_if_starting_line(float lat_now = gps.getLatitudeBase10(), float long_now = gps.getLongitudeBase10()) {

    }

}