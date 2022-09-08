//
// Created by schtu on 12.05.2022.
//

#ifndef BOAT_CONTROLLER_TELEMETRY_H
#define BOAT_CONTROLLER_TELEMETRY_H

#include "define.h"
#include <WString.h>
#include <ArduinoJson.h>

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
        int SatellitesNum;

    public:
        JsonOutput();

        void SetCreatedAt(String CreatedAt);

        void SetControllerWatts(long int Watts);

        void SetTimeToGo(int TimeToGo);

        void SetControllerVolts(long int Volts);

        void SetMPPTVolts(long int Volts);

        void SetMPPTWatts(long int Watts);

        void SetMotorTemp(double Temperature);

        void SetMotorRevols(int Revols);

        void SetPositionLat(double PositionLat);

        void SetPositionLng(double PositionLng);

        void SetSatellitesNum(int SatellitesNum);

        void GetJSON();
    };

    void CreatedAt(String CreatedAt);

    void ControllerWatts(long int Watts);

    void TimeToGo(int TimeToGo);

    void ControllerVolts(long int Volts);

    void MPPTVolts(long int Volts);

    void MPPTWatts(long int Watts);

    void MotorTemp(double Temperature);

    void MotorRevols(int Revols);

    void PositionLat(double PositionLat);

    void PositionLng(double PositionLng);

    void SatellitesNum(int SatellitesNum);

    void GetJSON();


}
#endif //BOAT_CONTROLLER_TELEMETRY_H