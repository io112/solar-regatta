#include <controller.h>

namespace Controller {

    int tempSensorVal;
    int tempResist = 10000;  // resistor for controller temp sensor, om
    double tempVin = 4.7;   // voltage input used in voltage dividers for temp sensors


    void readSensors() {
        tempSensorVal = analogRead(controller_temp_sensor);
        Log::debug("Temp sensor: " + String(tempSensorVal), CONTROLLER_MODULE);
    }

    double countTemp(double resistOm) {
        resistOm /= 100000;
        return exp(-50487 * pow(resistOm, 5) + 30273 * pow(resistOm, 4) - 6912.4 * pow(resistOm, 3) +
                   741.56 * pow(resistOm, 2) - 48.174 * resistOm +
                   5.0263);
    }

    void getTemp() {
        double vout = Utils::map(tempSensorVal, 0, 1023, 0, 5); // from (0,1024) to (0,5)
        double om = (tempResist * vout) / (tempVin - vout);

        double temp = countTemp(om);
        Telemetry::ControllerTemp(temp);
        Log::debug("Controller temp: " + String(temp), CONTROLLER_MODULE);
    }

    void init() {

    }

    void read() {
        readSensors();
        getTemp();
    }
}