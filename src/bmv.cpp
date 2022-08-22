#include "bmv.h"

namespace BMV {
    SoftwareSerial BmvSerial(11, 12); // RX, TX
    void init(unsigned long baudRate) {
        if (BMV_ENABLED)
            BmvSerial.begin(baudRate);
    }

    void read() {
        if(!BMV_ENABLED)
            return;
        char symbol;
        char s[20];
        String BMV_cmd_name = ""; // command name
        String BMV_cmd_value = "";
        int i = 0;
        long BMV_cmd_value_int = 0;

        while (BmvSerial.available()) {
            symbol = BmvSerial.read();
            s[i] = symbol;
            /* Serial.print(s[i]);
             Serial.print(" ");
             Serial.write(int(s[i)]);
             Serial.println(" ");
             */
            i++;
            if (symbol == 10) {                // the symbol which mean end of the line
                for (int j = 0; s[j] != 9; j++) {
                    BMV_cmd_name += s[j];          // collect chars of the command name
                    //Serial.print(s[j]);
                }

                for (int j = BMV_cmd_name.length() + 1; j < (i - 2); j++) {
                    BMV_cmd_value += s[j];
                }
                // Serial.print(BMV_cmd_name);
                // Serial.print(" ");
                // Serial.println(BMV_cmd_value);
                if (BMV_cmd_name == "P") {      // Watts
//                if (is_it_sd_writing_time()) sd_write_data(BMV_cmd_value, "watts_b.txt");
                    // TODO: storage write
                    BMV_cmd_value_int = BMV_cmd_value.toInt();
                    Telemetry::ControllerWatts(BMV_cmd_value_int);
                    //Serial.println(BMV_cmd_value_int);
                }
                if (BMV_cmd_name == "V") {     // Volts
                    //Serial.println(BMV_cmd_value);
//                if (is_it_sd_writing_time()) sd_write_data(BMV_cmd_value, "volts_b.txt");
                    // TODO: storage write
                    BMV_cmd_value_int = BMV_cmd_value.toInt() / 1000; //mV -> V
                    Telemetry::ControllerVolts(BMV_cmd_value_int);
                }
                if (BMV_cmd_name == "TTG") {     //Time to go
                    //Serial.println("ttg is found");
                    if (BMV_cmd_value == "-1") BMV_cmd_value = "inf";
                    Telemetry::TimeToGo(BMV_cmd_value);
                }

                i = 0;
                BMV_cmd_value = "";
                BMV_cmd_name = "";
                BMV_cmd_value_int = 0;
            }
        }
    }
}