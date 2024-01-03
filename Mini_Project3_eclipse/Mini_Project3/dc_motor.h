 /******************************************************************************
 *
 * Module: DC-Motor
 *
 * File Name: dc_motor.h
 *
 * Description: header file for the Dc Motor driver
 *
 * Author: Abdelrahman Maher
 *
 *******************************************************************************/


#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "std_types.h"

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
extern uint8 g_speed;

typedef enum
{
	stop, clockwise,anticlockwise
}DcMotor_state;


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/


void DcMotor_init(void);

void DcMotor_Rotate(DcMotor_state state, uint8 g_speed);

#endif /* DC_MOTOR_H_ */
