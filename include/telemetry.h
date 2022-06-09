//
// Created by schtu on 12.05.2022.
//

#ifndef BOAT_CONTROLLER_TELEMETRY_H
#define BOAT_CONTROLLER_TELEMETRY_H
#include "string.h"

namespace Telemetry {

    class JsonOutput {
    private:
        string CreatedAt;
        long int ControllerWatts;
        int TimeToGo;
        long int ControllerVolts;
        long int MPPTVolts;
        long int MPPTWatts;
        double MotorTemp;
        int MotorRevols;
        double Speed;
        double PositionLat;
        double PositionLng;

    public:
        JsonOutput();

        void CreatedAt(string CreatedAt);

        void ControllerWatts(long int Watts);

        void TimeToGo(int TimeToGo);

        void ControllerVolts(long int Volts);

        void MPPTVolts(long int Volts);

        void MPPTWatts(long int Watts);

        void MotorTemp(double Temperature);

        void MotorRevols(int Revols);

        void Speed(double Speed);

        void PositionLat(double PositionLat);

        void PositionLng(double PositionLng);

        string Show();
    };

    void CreatedAt(string CreatedAt);

    void ControllerWatts(long int Watts);

    void TimeToGo(int TimeToGo);

    void ControllerVolts(long int Volts);

    void MPPTVolts(long int Volts);

    void MPPTWatts(long int Watts);

    void MotorTemp(double Temperature);

    void MotorRevols(int Revols);

    void Speed(double Speed);

    void PositionLat(double PositionLat);

    void PositionLng(double PositionLng);

    String Show

}
#endif //BOAT_CONTROLLER_TELEMETRY_H
x