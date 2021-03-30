#include "GP2Y0A21_Sensor.h"


/*============================================================================*/
/* Macros */
/*============================================================================*/
#define MAX_PIN_VOLTAGE 1023
#define MIN_PIN_VOLTAGE 0


/*============================================================================*/
/* Component_Operations */
/*============================================================================*/
void GP2Y0A21__Mesure_Distance( const GP2Y0A21_Sensor* Me )
{
    /* Get sensor pin voltage */
    T_Voltage pin_voltage;
    Me->Analog_Pin->Get_Voltage(&pin_voltage);
    
    /* Check voltage validity */
    if( pin_voltage > MAX_PIN_VOLTAGE || pin_voltage < MIN_PIN_VOLTAGE )
    { /* Voltage is invalid */
        Me->var_attr->Is_Valid = false;
    }
    else
    { /* Voltage is valid */
        Me->var_attr->Is_Valid = true;
        Me->var_attr->Mesured_Distance = 0;
    }
}


/*============================================================================*/
/* Realized interfaces */
/*============================================================================*/
void GP2Y0A21__Mesure__Get_Measured_Distance(
    const GP2Y0A21_Sensor* Me,
    T_Distance* distance )
{
    *distance =  Me->var_attr->Mesured_Distance;
}
/*----------------------------------------------------------------------------*/
void GP2Y0A21__Mesure__Is_Measured_Distance_Valid(
    const GP2Y0A21_Sensor* Me,
    bool* is_measure_valid )
{
    *is_measure_valid =  Me->var_attr->Is_Valid;
}