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

        void JsonOutput::SetCreatedAt(String CreatedAt){
            this->CreatedAt = CreatedAt;
        }

        void JsonOutput::SetControllerWatts(long int Watts) {
            this->ControllerWatts = Watts;
        }


        void JsonOutput::SetTimeToGo(int TimeToGo) {
            this->TimeToGo = TimeToGo;
        }


        void JsonOutput::SetControllerVolts(long int Volts) {
            this->ControllerVolts = Volts;
        }


        void JsonOutput::SetMPPTVolts(long int Volts) {
            this->MPPTVolts = Volts;
        }


        void JsonOutput::SetMPPTWatts(long int Watts) {
            this->MPPTWatts = Watts;
        }


        void JsonOutput::SetMotorTemp(double Temperature) {
            this->MotorTemp = Temperature;
        }


        void JsonOutput::SetMotorRevols(int Revols) {
            this->MotorRevols = Revols;
        }


        void JsonOutput::SetPositionLat(double PositionLat) {
            this->PositionLat = PositionLat;
        }


        void JsonOutput::SetPositionLng(double PositionLng) {
            this->PositionLng = PositionLng;
        }

        void JsonOutput::SetSatellitesNum(int SatellitesNum){
            this->SatellitesNum = SatellitesNum;
        }

        void JsonOutput::GetJSON() {
            StaticJsonDocument<200> json;
            json['created_at'] = JsonOutput::CreatedAt;
            json['ControllerWatts'] = JsonOutput::ControllerWatts;
            json['TimeToGo'] = JsonOutput::TimeToGo;
            json['ControllerVolts'] = JsonOutput::ControllerVolts;
            json['MPPTVolts'] = JsonOutput::MPPTVolts;
            json['MPPTWatts'] = JsonOutput::MPPTWatts;
            json['MotorTemp'] = JsonOutput::MotorTemp;
            json['MotorRevols'] = JsonOutput::ControllerWatts;
            json['PositionLat'] = JsonOutput::PositionLat;
            json['PositionLat'] = JsonOutput::PositionLat;
            json['PositionLng'] = JsonOutput::PositionLng;
            json['SatellitesNum'] = JsonOutput::SatellitesNum;
            serializeJson(json, RaspberrySerial);
        }

        JsonOutput Data = JsonOutput();


    void CreatedAt(String CreatedAt){
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

};