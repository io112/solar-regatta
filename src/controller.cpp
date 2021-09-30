#include <controller.h>

namespace Controller {
    int r_controller_temp = 10000;  // resistor for controller temp sensor, om
    double temp_vin = 4.7;   // voltage input used in voltage dividers for temp sensors


    double getTemp() {
        int val = analogRead(controller_temp_sensor);
        double vout = val / 204.6; //(204.6 = 1023/5) from (0,1024) to (0,5)
        double om = (r_controller_temp * vout) / (temp_vin - vout);
        //Serial.println(val);
        om /= 100000;
        double logtemp =
                -50487 * pow(om, 5) + 30273 * pow(om, 4) - 6912.4 * pow(om, 3) + 741.56 * pow(om, 2) - 48.174 * om +
                5.0263;
        double temp = exp(logtemp);
        //Serial.println(temp);
        return temp;
    }
}