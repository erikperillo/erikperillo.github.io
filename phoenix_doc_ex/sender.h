/**
@file   sender.h
@brief  Sender side protocol function declarations.
*/

#include <serial.h>

//@{
///PID parameters range.
#define PID_PARAMS_MIN -100.0
#define PID_PARAMS_MAX 100.0
//@}

//@{
///Ground velocity range.
#define GND_VEL_MIN -100.0
#define GND_VEL_MAX 100.0
//@}

///Messages supported by protocol.
enum
{
	///Brake the robot.
	BRAKE,

	///Set new ground velocity for robot.
	GND_VEL,

	///Send PID control parameters.
	PID_PARAMS
};

/**
@brief Converts an unsigned int into two bytes and send them over serial.

Least-significant bytes go first.
Assumes big-endian representation of numbers on architecture.

@param serial Serial class representing communication between devices.
@param value Value to write.
*/
void write(serial::Serial& serial, uint16_t value);

/**
@brief Scales a float value to fit within the interval [0, 2^16-1].

Uses unity-based normalization.

@param value Value to normalize.
@param min Minimum value parameter 'value' can have.
@param max Maximum value parameter 'value' can have.
*/
uint16_t scale(float value, float min, float max);

/**
@brief Sends one of protocol-defined messages through serial.

@param serial Serial class representing communication between devices.
@param message One of protocol-defined messages to send.
*/
void send_msg(serial::Serial& serial, uint8_t message);

/**
@brief Scales a value and sends it through serial.

@param min Minimun value 'value' can have.
@param max Maximum value 'value' can have.
@param value The value to send.
*/
void send_val(serial::Serial& serial, float min, float max, float value);
