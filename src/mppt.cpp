#include "mppt.h"

namespace MPPT {


    String getCommandName(const char *s) {
        String res = "";
        for (int j = 0; s[j] != 9; j++) {
            res += s[j];          // collect chars of the command name
        }
        return res;
    }


    String getCommandValue(const char *s, const String &cmdName, int i) {
        String res = "";

        for (int j = cmdName.length() + 1; j < (i - 2); j++) {
            res += s[j];
        }
        return res;
    }


    void processWatts(String value) {
        Telemetry::MPPTWatts(value.toInt());
    }

    void processVolts(String value) {
        long intValue = value.toInt() / 1000; //mV -> V
        Telemetry::MPPTVolts(intValue);
    }

    void processCommand(const char *s, int i) {
        String cmdName = getCommandName(s);
        String cmdValue = getCommandValue(s, cmdName, i);

        if (cmdName == WATTS_KEY) {      // Watts
            processWatts(cmdValue);
        }
        if (cmdName == VOLTS_KEY) {     // Volts
            processVolts(cmdValue);
        }
    }

    void init(unsigned long baudRate) {
        if (MPPT_ENABLED)
            mpptSerial.begin(baudRate);
    }

    void read() {
        if (!MPPT_ENABLED)
            return;
        char s[20];
        int i = 0;
        char symbol;

        while (mpptSerial.available()) {
            symbol = mpptSerial.read();
            s[i] = symbol;

            if (symbol == 10) {                // the symbol which mean end of the line
                processCommand(s,  i);
                i = 0;
            }

            i++;
        }
    }
}