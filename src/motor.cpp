#include "motor.h"

namespace Motor {


    unsigned long measureStartTime;
    unsigned long revolsPerMin;
    int tempSensorVal;
    int rotations = 0;
    bool wasWhite = false;
    bool wasBlack = false;
    const int tempResist = 1000;   // resistor for motor temp sensor, om
    const double tempVin = 3.3;   // voltage input used in voltage dividers for temp sensors


//---------------- end---------------
    double countRevolutionsPerMin(unsigned long revols, unsigned long measureTime) {
        return (double) revols / (double) measureTime * MILLIS_IN_MINUTE;
    }

    double countTemp(double resistOm) {
        resistOm /= 100;
        return 0.0138 * resistOm * resistOm * resistOm - 0.9088 * resistOm * resistOm + 30.77 * resistOm - 130.73;;
    }


    void readSensors() {
        int sensorValue = analogRead(revolutionMeter);
        if (sensorValue <= edge_white) {
            wasWhite = true;
        } else if (sensorValue >= edge_black && wasWhite) {
            wasBlack = true;
        }
        if (wasBlack && wasWhite) {
            rotations++;
            wasBlack = false;
            wasWhite = false;
        }
        tempSensorVal = analogRead(tempSensor);
        Log::debug("Revols sensor: " + String(sensorValue), MOTOR_MODULE);
        Log::debug("Temp sensor: " + String(tempSensorVal), MOTOR_MODULE);

    }

    void getRevolutions() {
        unsigned long measureTime = millis() - measureStartTime;
        if (measureTime > DELAY_MILLIS) {
            revolsPerMin = countRevolutionsPerMin(rotations, measureTime);
            measureStartTime = millis();
            rotations = 0;

            Telemetry::MotorRevols(revolsPerMin);
            Log::debug("RPM: " + String(revolsPerMin), MOTOR_MODULE);
        }
    }

    void getTemp() {
        double vout = Utils::map(tempSensorVal, 0, 1023, 0, 5); // from (0,1024) to (0,5)
        double om = (tempResist * vout) / (tempVin - vout);
        double temp = countTemp(om);
        Telemetry::MotorTemp(temp);
        Log::debug("Temp: " + String(temp), MOTOR_MODULE);
    }

    void init() {
        measureStartTime = millis();
    }

    void read() {
        readSensors();
        getRevolutions();
        getTemp();
    }
}