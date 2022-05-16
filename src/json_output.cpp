//
// Created by schtu on 12.05.2022.
//

#include "../src/json_output.h"
#include "string.h"



class json_output{


    Json_Output(){
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


    Json_Output(Json_Output Temp){
        if(this->Controller_Watts == 0){
            this->Controller_Watts = Temp.Controller_Watts;
        }
        if(this->Time_To_Go == 0){
            this->Time_To_Go = Temp.Time_To_Go;
        }
        if(this->Controller_Volts == 0){
            this->Controller_Volts = Temp.Controller_Volts;
        }
        if(this->MPPT_Volts == 0){
            this->MPPT_Volts = Temp.MPPT_Volts;
        }
        if(this->MPPT_Watts == 0){
            this->MPPT_Watts = Temp.MPPT_Watts;
        }
        if(this->Motor_Temp == 0){
            this->Motor_Temp = Temp.Motor_Temp;
        }
        if(this->Motor_Revols == 0){
            this->Motor_Revols = Temp.Mototr_Revols;
        }
        if(this->Speed == 0){
            this->Speed = Temp.Speed;
        }
        if(this->Position_Lat == 0){
            this->Position_Lat = Temp.Position_Lat;
        }
        if(this->Position_Lng == 0){
            this->Position_Lng = Temp.Position_Lng;
        }
    }


    void Controller_Watts(long int Watts){
        this->controller_watts = Watts;
    }


    void Time_To_Go(int Time_to_go){
        this->time_to_go = Time_to_go;
    }


    void Controller_Volts(long int Volts){
        this->controller_volts = Volts;
    }


    void MPPT_Volts(long int Volts){
        this->MPPT_volts = Volts;
    }


    void MPPT_Watts(long int Watts){
        this->MPPT_watts = Watts;
    }


    void Motor_Temp(double Temperature){
        this->motor_temp = Temperature;
    }


    void Motor_Revols(int Revols){
        this->motor_revols = Revols;
    }


    void Speed(double Speed){
        this->speed = Speed;
    }


    void Position_Lat(double Position_lat){
        this->position_lat = Position_lat;
    }


    void Position_Lng(double Position_lang){
        this->position_lng = Position_lang;
    }

    string show(){
        string Out = "controller_watts="+controller_watts+"&time_to_go="+time_to_go+"&controller_volts="+controller_volts+
                "&MPPT_volts="+MPPT_volts+"&MPPT_watts="+MPPT_watts+"&motor_temp="+motor_temp+"&motor_revols="+motor_revols+
                "&speed="+speed+"&position_lat="+position_lat+"&position_lng="+position_lng;
        return Out;
    }

}
