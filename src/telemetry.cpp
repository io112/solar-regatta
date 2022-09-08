//
// Created by schtu on 12.05.2022.
//

#include "telemetry.h"
namespace Telemetry {

        JsonOutput::JsonOutput() {
            CreatedAt = "0";
            ControllerWatts = 0;
            TimeToGo = 0;
            ControllerVolts = 0;
            MPPTVolts = 0;
            MPPTWatts = 0;
            MotorTemp = 0;
            MotorRevols = 0;
            Speed = 0;
            PositionLat = 0;
            PositionLng = 0;
            SatellitesNum = 0;
        }

        void SetCreatedAt(string CreatedAt){
            this->CreatedAt = CreatedAt;
        }

        void SetControllerWatts(long int Watts) {
            this->ControllerWatts = Watts;
        }


        void SetTimeToGo(int TimeToGo) {
            this->TimeToGo = TimeToGo;
        }


        void SetControllerVolts(long int Volts) {
            this->ControllerVolts = Volts;
        }


        void SetMPPTVolts(long int Volts) {
            this->MPPTVolts = Volts;
        }


        void SetMPPTWatts(long int Watts) {
            this->MPPTWatts = Watts;
        }


        void SetMotorTemp(double Temperature) {
            this->MotorTemp = Temperature;
        }


        void SetMotorRevols(int Revols) {
            this->MotorRevols = Revols;
        }


        void SetSpeed(double Speed) {
            this->Speed = Speed;
        }


        void SetPositionLat(double PositionLat) {
            this->PositionLat = PositionLat;
        }


        void SetPositionLng(double PositionLng) {
            this->PositionLng = PositionLng;
        }

        void SetSatellitesNum(int SatellitesNum){
            this->SatellitesNum = SatellitesNum;
        }

        string Show() {
           json Out ={
           {"CreatedAt:",CreatedAt},
           {"ControllerWatts:", ControllerWatts},
           {"TimeToGo:", TimeToGo},
           {"ControllerVolts:", ControllerVolts},
           {"MPPTVolts:", MPPTVolts},
           {"MPPTWatts:", MPPTWatts},
           {"MotorTemp:", MotorTemp},
           {"MotorRevols:", MotorRevols},
           {"Speed:", Speed},
           {"PositionLat:", PositionLat},
           {"PositionLng:", PositionLng},
           {"SatellitesNum:", SatellitesNum}
           };
            return Out;
        }

    };

    JsonOutput Data();

    void CreatedAt(string CreatedAt){
        Data.SetCreatedAt(CreatedAt);
    }

    void ControllerWatts(long int Watts){
        Data.SetControllerWatts(Watts);
    }


    void TimeToGo(int TimeToGo){
        Data.SetTimeToGo(TimeToGo);
    }


    void ControllerVolts(long int Volts){
        Data.SetControllerVolts(Volts);
    }


    void MPPTVolts(long int Volts){
        Data.SetMPPTVolts(Volts);
    }


    void MPPTWatts(long int Watts){
        Data.SetMPPTWatts(Watts);
    }


    void MotorTemp(double Temperature){
        Data.SetMotorTemp(Temperature);
    }


    void MotorRevols(int Revols){
        Data.SetMotorRevols(Revols);
    }


    void PositionLat(double PositionLat){
        Data.SetPositionLat(PositionLat);
    }


    void PositionLng(double PositionLng){
        Data.SetPositionLng(PositionLng);
    }

    void SatellitesNum(int SatellitesNum){
        Data.SetSatellitesNum(SatellitesNum);
    }

    void GetJSON(){
        Data.GetJSON();
    }
