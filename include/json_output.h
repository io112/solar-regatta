//
// Created by schtu on 12.05.2022.
//

#ifndef BOAT_CONTROLLER_JSON_OUTPUT_H
#define BOAT_CONTROLLER_JSON_OUTPUT_H


class Json_Output {
private:
    //created_at = "2022-05-03T18:58:29.402Z";
    long int Controller_Watts;
    int Time_To_Go;
    long int Controller_Volts;
    long int MPPT_Volts;
    long int MPPT_Watts;
    double Motor_Temp;
    int Motor_Revols;
    double Speed;
    double Position_Lat;
    double Position_Lng;

public:
    Json_Output();
    Json_Output(Json_Output Temp);
    void Controller_Watts(long int Watts);
    void Time_To_Go(int Time_to_go);
    void Controller_Volts(long int Volts);
    void MPPT_Volts(long int Volts);
    void MPPT_Watts(long int Watts);
    void Motor_Temp(double Temperature);
    void Motor_Revols(int Revols)();
    void Speed(double Speed);
    void Position_Lat(double Position_lat);
    void Position_Lng(double Position_lang);
    string show();
};


#endif //BOAT_CONTROLLER_JSON_OUTPUT_H
x