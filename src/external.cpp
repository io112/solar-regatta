//
// Created by Paramonov Dmitriy on 16.11.2021.
//
#include "external.h"

namespace External {
    String data = "";

    void send(String data) {
        ExternalSerial.print(data);
    }

    String read() {
        if (ExternalSerial.available()) {
            data += char(ExternalSerial.read());
        }
        String res = data;
        data = "";
        return res;
    }
}
