//
// Created by schtu on 12.05.2022.
//

#ifndef BOAT_CONTROLLER_JSON_OUTPUT_H
#define BOAT_CONTROLLER_JSON_OUTPUT_H


class json_output {
private:
    //created_at = "2022-05-03T18:58:29.402Z";
    long int controller_watts;
    int time_to_go;
    long int controller_volts;
    long int MPPT_volts;
    long int MPPT_watts;
    double motor_temp;
    int motor_revols;
    double speed;
    double position_lat;
    double position_lng;

public:
    ~json_output();
    json_output();
    void cwatts_input();
    void ttg_input();
    void cvolts_input();
    void MPPTvolts_input();
    void MPPTwatts_input();
    void motortemp_input();
    void motorrev_input();
    void speed_input();
    void positionlat_input();
    void positionlang_input();
    void output();
};


#endif //BOAT_CONTROLLER_JSON_OUTPUT_H
