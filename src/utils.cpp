//
// Created by gamiy on 10.10.2022.
//

#include "utils.h"

namespace Utils {
    double map(double value,double from_start,
               double from_end, double dest_start, double dest_end) {
        return value * (dest_end - dest_start) / (from_end - from_start);
    }
}
