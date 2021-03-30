#ifndef GP2Y0A21_SENSOR_H
#define GP2Y0A21_SENSOR_H


/*============================================================================*/
/* Inclusions */
/*============================================================================*/
/* Attributes */
#include "T_Distance.h"
#include <stdbool.h>

/* Realized interfaces */
#include "Distance_Measurement.h"

/* Required interfaces */
#include "Analogic_Input.h"


/*============================================================================*/
/* Component_Type */
/*============================================================================*/
typedef struct {
    T_Distance Mesured_Distance;
    bool Is_Valid;
} GP2Y0A21_Sensor_Var;

typedef struct {

    /* Variable attributes */
    GP2Y0A21_Sensor_Var* var_attr;

    /* Required interfaces */
    const Analogic_Input* Analog_Pin;

    /* Inner objects */

} GP2Y0A21_Sensor;


/*============================================================================*/
/* Component_Operations */
/*============================================================================*/
void GP2Y0A21__Mesure_Distance( const GP2Y0A21_Sensor* Me );


/*============================================================================*/
/* Realized interfaces */
/*============================================================================*/
void GP2Y0A21__Mesure__Get_Measured_Distance(
    const GP2Y0A21_Sensor* Me,
    T_Distance* distance );
void GP2Y0A21__Mesure__Is_Measured_Distance_Valid(
    const GP2Y0A21_Sensor* Me,
    bool* is_measure_valid );


#endif