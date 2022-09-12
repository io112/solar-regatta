//
// Created by schtu on 12.05.2022.
//

#include "telemetry.h"

namespace Telemetry {

    JsonOutput::JsonOutput() {
        this->CreatedAt = "0";
        this->ControllerWatts = 0;
        this->TimeToGo = 0;
        this->ControllerVolts = 0;
        this->MPPTVolts = 0;
        this->MPPTWatts = 0;
        this->MotorTemp = 0;
        this->MotorRevols = 0;
        this->Speed = 0;
        this->PositionLat = 0;
        this->PositionLng = 0;
        this->SatellitesNum = 0;
    }

    void JsonOutput::SetCreatedAt(String CreatedAt) {
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

    void JsonOutput::SetSatellitesNum(int SatellitesNum) {
        this->SatellitesNum = SatellitesNum;
    }

    void JsonOutput::GetJSON() {
        DynamicJsonDocument json(2048);
        json["created_at"] = JsonOutput::CreatedAt;
        json["controller_watts"] = JsonOutput::ControllerWatts;
        json["time_to_go"] = JsonOutput::TimeToGo;
        json["controller_volts"] = JsonOutput::ControllerVolts;
        json["MPPT_volts"] = JsonOutput::MPPTVolts;
        json["MPPT_watts"] = JsonOutput::MPPTWatts;
        json["motor_temp"] = JsonOutput::MotorTemp;
        json["motor_revols"] = JsonOutput::ControllerWatts;
        json["position_lat"] = JsonOutput::PositionLat;
        json["position_lat"] = JsonOutput::PositionLat;
        json["position_lng"] = JsonOutput::PositionLng;
        json["satellites_num"] = JsonOutput::SatellitesNum;
        serializeJson(json, RaspberrySerial);
        RaspberrySerial.println();
    }

    JsonOutput Data = JsonOutput();


    void CreatedAt(String CreatedAt) {
        Data.SetCreatedAt(CreatedAt);
    }

    void ControllerWatts(long int Watts) {
        Data.SetControllerWatts(Watts);
    }


    void TimeToGo(int TimeToGo) {
        Data.SetTimeToGo(TimeToGo);
    }


    void ControllerVolts(long int Volts) {
        Data.SetControllerVolts(Volts);
    }


    void MPPTVolts(long int Volts) {
        Data.SetMPPTVolts(Volts);
    }


    void MPPTWatts(long int Watts) {
        Data.SetMPPTWatts(Watts);
    }


    void MotorTemp(double Temperature) {
        Data.SetMotorTemp(Temperature);
    }


    void MotorRevols(int Revols) {
        Data.SetMotorRevols(Revols);
    }


    void PositionLat(double PositionLat) {
        Data.SetPositionLat(PositionLat);
    }


    void PositionLng(double PositionLng) {
        Data.SetPositionLng(PositionLng);
    }

    void SatellitesNum(int SatellitesNum) {
        Data.SetSatellitesNum(SatellitesNum);
    }

    void GetJSON() {
        Data.GetJSON();
    }

    void init(long long baud) {
        RaspberrySerial.begin(baud);

    }

};
