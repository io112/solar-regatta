#include "log.h"

namespace Log {
    char buffer[300];

    String getString(String value, String module, String level) {
        sprintf(buffer, "[%lu.5][%s] %s: %s", millis(), module.c_str(), level.c_str(), value.c_str());
        return buffer;
    }

    void send(String val, String module, String level) {
        MainSerial.println(getString(val, module, level));
    }

    void debug(String val, String module) {
        if (LOG_LEVEL <= DEBUG_LEVEL) {
            send(val, module, DEBUG_S);
        }
    }

    void info(String val, String module) {
        if (LOG_LEVEL <= INFO_LEVEL) {
            send(val, module, INFO_S);
        }
    }

    void warn(String val, String module) {
        if (LOG_LEVEL <= WARN_LEVEL) {
            send(val, module, WARN_S);
        }
    }

    void error(String val, String module) {
        if (LOG_LEVEL <= ERROR_LEVEL) {
            send(val, module, ERROR_S);
        }
    }

    void monitor(String val, String module) {
        if (LOG_LEVEL <= MONITOR_LEVEL) {
            send(val, module, MONITOR_S);
        }
    }
}