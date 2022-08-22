#include "mppt.h"

namespace MPPT {


    void init(unsigned long baudRate) {
        if (MPPT_ENABLED)
            mppt.begin(baudRate);
    }

    void read() {
        if (!MPPT_ENABLED)
            return;
        char symbol;
        char s[20];
        String MPPT_cmd_name = ""; // command name
        String MPPT_cmd_value = "";
        long MPPT_cmd_value_int = 0;
        int i = 0;

        //Serial.println("read mppt");

        while (mppt.available()) {
            symbol = mppt.read();
            s[i] = symbol;
            //Serial.print(s[i]);
            i++;
            if (symbol == 10) {                // end of line
                for (int j = 0; s[j] != 9; j++) {
                    MPPT_cmd_name += s[j];          // collect chars of the value name
                }
                for (int j = MPPT_cmd_name.length() + 1; j < (i - 2); j++) {
                    MPPT_cmd_value += s[j];
                }
                if (MPPT_cmd_name == "V") {      //Volts
                    //Serial.println(MPPT_cmd_value);
//                if (is_it_sd_writing_time()) sd_write_data(MPPT_cmd_value, "volts_m.txt");
                    // TODO: storage write
                    MPPT_cmd_value_int = MPPT_cmd_value.toInt() / 1000; //mV -> V
                    Telemetry::MPPTVolts(MPPT_cmd_value_int);
                }
                if (MPPT_cmd_name == "PPV") {      // Panel power
//                if (is_it_sd_writing_time()) sd_write_data(MPPT_cmd_value, "w_panel.txt");
                    // TODO: storage write

                    MPPT_cmd_value_int = MPPT_cmd_value.toInt();
                    Telemetry::MPPTWatts(MPPT_cmd_value_int);
                }
                i = 0;
                MPPT_cmd_value = "";
                MPPT_cmd_name = "";
                MPPT_cmd_value_int = 0;
            }
        }
    }
}