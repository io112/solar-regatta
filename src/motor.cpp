#include "motor.h"

namespace Motor {

    // ---for rotation sensor------------------
    long delay_in_microsec = 1000;

    int delay_in_sec = delay_in_microsec / 1000;
    int mult = 60 / delay_in_sec;
    int rotations_per_min;
    bool revol_count_working = 0;

    int edge_black = 800;
    int edge_white = 700;

    unsigned long start_time_revolutions;
    unsigned long time_spent;
    int rotations = 0;
    bool was_white = 0;
    bool was_black = 0;
    int r_motor_temp = 4700;   // resistor for motor temp sensor, om
    double temp_vin = 4.7;   // voltage input used in voltage dividers for temp sensors


//---------------- end---------------


    int getRevolutions() {
        if (!revol_count_working) {
            start_time_revolutions = millis();
            revol_count_working = 1;
        }

        if ((millis() - start_time_revolutions) > delay_in_microsec) {
            rotations_per_min = rotations * mult;
            start_time_revolutions = millis();
            rotations = 0;
            revol_count_working = 0;
            Display::motorRevols(rotations_per_min);
            //Serial.println(rotations_per_min);
//        sd_write_data(String(rotations_per_min), "revols.txt");
            //TODO: storage write
        }

        int sensorValue = analogRead(revolutionMeter);
        //Serial.println(sensorValue);
        if (sensorValue <= edge_white) {
            was_white = 1;
        } else if (sensorValue >= edge_black && was_white == 1) {
            was_black = 1;
        }
        if (was_black && was_white) {
            rotations++;
            was_black = 0;
            was_white = 0;

            //Serial.print(rotations);

            //Serial.print(" ");
            //Serial.println((millis()-start_time)/1000);

        }
        return rotations;
    }

    double getTemp() {
        int val = analogRead(tempSensor);
        double vout = val / 204.6; //(204.6 = 1023/5) from (0,1024) to (0,5)
        double om = (r_motor_temp * vout) / (temp_vin - vout);
        //Serial.println(om);
        om /= 100;
        //Serial.println(om);
        double temp = 0.0138 * om * om * om - 0.9088 * om * om + 30.77 * om - 130.73;
        return temp;
    }

}