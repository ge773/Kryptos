/***************************************************************/
/*                                                             */
/*      PROJECT NAME :  Kryptos                                */
/*      FILE         :  Kryptos.c                              */
/*      DESCRIPTION  :  Main Program                           */
/*      CPU SERIES   :  RX600                                  */
/*      CPU TYPE     :  RX631                                  */
/*                                                             */
/*      This file is generated by e2 studio.                   */
/*                                                             */
/***************************************************************/

#include <machine.h>
#include <stdint.h>
#include "my_typedef.h"
#include "iodefine.h"
#include "app.h"
#include "run.h"
#include "init.h"
#include "intrpt.h"
#include "serial.h"
#include "sensor.h"
#include "grobal.h"
#include "common.h"

void main(void) {
	uint16_t i = 0;
	init();
	checkBatt();

	TPUA.TSTR.BIT.CST4 = 1;
	MTU.TSTR.BIT.CST1 = 1;

	switch (selectMode(10)) {
	case 0: //////////////////////////////////////////////////////////////////////////////////////
		driveRGB(RED, ON);
		g_test_flag = 1;
		setMotorDutyL(20);
		setMotorDutyR(20);

		setMotorDirL(FORWARD);
		setMotorDirR(FORWARD);
		driveMotor(ON);
		while (1) {

		}

		break;
	case 1: //////////////////////////////////////////////////////////////////////////////////////
		driveRGB(GREEN, ON);
		while (1) {
			myprintf("WHO_AM_I: %d\n", commSPI(117, 0x0f, READ));
		}
		break;
	case 2: //////////////////////////////////////////////////////////////////////////////////////
		driveRGB(BLUE, ON);
		for (i = 0; i < 5000; i++) {
			myprintf("%f\n", g_test_array[i]);
		}
		break;
	case 3: //////////////////////////////////////////////////////////////////////////////////////
		driveRGB(YELLOW, ON);
		for (i = 0; i < 5000; i++)
			myprintf("%f\n", g_test_array[i]);
		break;
	case 4: //////////////////////////////////////////////////////////////////////////////////////
		driveRGB(CYAN, ON);
		break;
	case 5: //////////////////////////////////////////////////////////////////////////////////////
		driveRGB(MAGENTA, ON);
		break;
	case 6: //////////////////////////////////////////////////////////////////////////////////////
		driveRGB(WHITE, ON);
		break;
	case 7: //////////////////////////////////////////////////////////////////////////////////////
		driveRGB(ORANGE, ON);
		g_test_flag = 1;
		setMotorDutyL(20);
		setMotorDutyR(20);

		setMotorDirL(0);
		setMotorDirR(0);
		driveMotor(ON);
		driveRGB(50, 10, 10, ON);
		driveSuction(100, ON);
		while (1) {

		}

		break;
	case 8: //////////////////////////////////////////////////////////////////////////////////////
		driveRGB(WATER, ON);
		g_test_flag = 0;
		while (1) {
			myprintf("%8f %8f\n", returnVelocityL(), returnVelocityR());
		}
		break;
	case 9: //////////////////////////////////////////////////////////////////////////////////////
		driveRGB(LBLUE, ON);
		driveSuction(100, 1);
		break;
	case 10: //////////////////////////////////////////////////////////////////////////////////////
		driveRGB(LRED, ON);
		g_test_flag = 0;
		setMotorDutyL(50);
		setMotorDutyR(50);

		setMotorDirL(BACKWARD);
		setMotorDirR(BACKWARD);

		driveMotor(ON);
		break;
	default: //////////////////////////////////////////////////////////////////////////////////////
		break;
	}

}
