#include <Arduino.h>
#include <WString.h>
#include "define.h"

#ifndef SOLAR_LOG_H
#define SOLAR_LOG_H

namespace Log {
#define DEBUG_S "DEBUG"
#define INFO_S "INFO"
#define WARN_S "WARN"
#define MONITOR_S "MONITOR"
#define ERROR_S "ERROR"
#define DEBUG_LEVEL 10
#define INFO_LEVEL 20
#define WARN_LEVEL 30
#define MONITOR_LEVEL 35
#define ERROR_LEVEL 40


    void debug(String val, String module);

    void info(String val, String module);

    void warn(String val, String module);

    void error(String val, String module);

    void monitor(String val, String module);
}

#endif //SOLAR_LOG_H
