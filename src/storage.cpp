#include "storage.h"

namespace Storage {
    void write_data(String data, String file_name) {
    File myFile = SD.open(file_name.c_str(), FILE_WRITE);
    //Serial.println("sd file is opened");
    if (gps.available()) {
        gps.readParsing();
        //Serial.println("gps is available");
        switch (gps.getState()) {
            case GPS_OK:
                gps.getTime(strTime, MAX_SIZE_MASS);
                data = data + " " + strTime;

        }
    }
    //Serial.println("data is recorded");
    myFile.println(String(data));

    myFile.close();
    }


    void read_data(String file_name) {

        File dataFile = SD.open(file_name.c_str());
        if (dataFile) {
            Serial.println("----------------------Start reading----------------------");
            while (dataFile.available()) {
                Serial.write(dataFile.read());
            }
            Serial.println("----------------------end reading----------------------");
            dataFile.close();
        }
    }


    bool is_it_sd_writing_time() {
        //Serial.println(millis()-sd_read_timestamp);
        if (millis() - sd_read_timestamp > delay_sd_write) {
            //Serial.println("it is sd writing time");
            return true;
        } else return false;
    }

    void write_temp(double motor_temp, double controller_temp) {
        if (is_it_sd_writing_time()) {
            //Serial.println("record is in process");
            write_data(String(motor_temp), "mot_temp.txt");

            write_data(String(controller_temp), "cont_temp.txt");
            //Serial.println("record t is done");
        }
    }


    void update_sd_writing_time() {
        if (millis() - sd_read_timestamp > delay_sd_write) {
            sd_read_timestamp = millis();
            //Serial.println("sd writing time is updated");
        }
    }

}