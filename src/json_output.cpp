//
// Created by schtu on 12.05.2022.
//

#include "../src/json_output.h"
#include "string.h"



namespace json_output{

    ~json_output(){

    }


    json_output(){
        controller_watts = 0;
        time_to_go = 0;
        controller_volts = 0;
        MPPT_volts = 0;
        MPPT_watts = 0;
        motor_temp = 0;
        motor_revols = 0;
        speed = 0;
        position_lat = 0;
        position_lng = 0;
    }


    void cwatts_input(long int Watts){
        this->controller_watts = Watts;
    }


    void ttg_input(int Time_to_go){
        this->time_to_go = Time_to_go;
    }


    void cvolts_input(long int Volts){
        this->controller_volts = Volts;
    }


    void MPPTvolts_input(long int Volts){
        this->MPPT_volts = Volts;
    }


    void MPPTwatts_input(long int Watts){
        this->MPPT_watts = Watts;
    }


    void motortemp_input(double Temperature){
        this->motor_temp = Temperature;
    }


    void motorrev_input(int Revols){
        this->motor_revols = Revols;
    }


    void speed_input(double Speed){
        this->speed = Speed;
    }


    void positionlat_input(double Position_lat){
        this->position_lat = Position_lat;
    }


    void positionlang_input(double Position_lang){
        this->position_lng = Position_lang;
    }

    void output(){
        string Out = "controller_watts="+controller_watts+"&time_to_go="+time_to_go+"&controller_volts="+controller_volts+
                "&MPPT_volts="+MPPT_volts+"&MPPT_watts="+MPPT_watts+"&motor_temp="+motor_temp+"&motor_revols="+motor_revols+
                "&speed="+speed+"&position_lat="+position_lat+"&position_lng="+position_lng;
        Serial.println(Out);
    }

}
