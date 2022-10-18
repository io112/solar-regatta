#include "bmv.h"

namespace BMV {
    SoftwareSerial BmvSerial(11, 12); // RX, TX

    void init(unsigned long baudRate) {
        if (BMV_ENABLED)
            BmvSerial.begin(baudRate);
    }

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
        Telemetry::ControllerWatts(value.toInt());
    }
    void processVolts(String value) {
        long cmdNumValue = value.toInt() / 1000; //mV -> V
        Telemetry::ControllerVolts(cmdNumValue);
    }
    void processTimeToGo(String value) {
        Telemetry::TimeToGo(value.toInt());
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
        if (cmdName == TIME_TO_GO_KEY) {     //Time to go
            processTimeToGo(cmdValue);
        }
    }

    void read() {
        if (!BMV_ENABLED)
            return;
        char s[20];
        int i = 0;
        char symbol;

        while (BmvSerial.available()) {
            symbol = BmvSerial.read();
            s[i] = symbol;

            if (symbol == 10) {                // the symbol which mean end of the line
                processCommand(s,  i);
                i = 0;
            }

            i++;
        }
    }
}