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

#include <stdint.h>
#include "my_typedef.h"
#include "iodefine.h"
#include "app.h"
#include "run.h"
#include "init.h"
#include "intrpt.h"
#include "serial.h"
#include "sensor.h"
#include "global.h"
#include "common.h"
#include "parameter.h"
#include "map.h"
#include "contest.h"
#include "adjustment.h"
#include "flash.h"

void main(void) {
	//uint8_t i, j;

	init();
	checkLowVoltage();
	notificateStartUp();
	switchSensorLED(ON);
	switch (selectMode(10)) {
	case 0: //////////////////////////////////////////////////////////////////////////////////////
		driveRGB(ORANGE, ON);

		selectContest();

//		 FLASH.DFLWE0.WORD = 0x1EFF; //プロテクト解除
//		 changeFCUMode(1, 1, P_E);
//		 driveRGB(RED, ON);
//		 notificateClock(1, 1);
//
//		 eraseFCU(0, 0);
//		 driveRGB(BLUE, ON);
//		 programFCU(1, 1, 0x44);
//
//		 driveRGB(GREEN, ON);
//		 changeFCUMode(1, 1, READ);
//		 myprintf("%d\n", readFCUValue(1, 1));
//
//		 FLASH.DFLWE0.WORD = 0x1E00; // disable

		break;
	case 1: //////////////////////////////////////////////////////////////////////////////////////
		driveRGB(MAGENTA, ON);
		//selectAdjustment1(T14);
		g_log_count = 0;
		waitSensor();
		g_log_count = 0;
		waitTime(2000);
		soundPrint();
		waitButton();
		printLog4();

		break;
	case 2: //////////////////////////////////////////////////////////////////////////////////////
		driveRGB(BLUE, ON);

		selectAdjustment2();

//		driveRGB(GREEN, ON);
//		waitTime(1000);
//		calcGyroZRef();
//		driveSuction(70, ON);
//		waitTime(1000);
//		initRun();
//		driveMotor(ON);
//		switchSensorLED(ON);
//
//		g_flag_shortest_goal = 1;
//
//		runStraight(30, SECTION * 5, 4, 0);
//
//		waitTime(300);
//		driveMotor(OFF);
//		driveSuction(70, OFF);
//		waitButton();
//		printLog4();

		break;
	case 3: //////////////////////////////////////////////////////////////////////////////////////
		driveRGB(YELLOW, ON);
		driveSuction(100, ON);
		break;
	case 4: //////////////////////////////////////////////////////////////////////////////////////
		driveRGB(CYAN, ON);
		waitSensor();
		calcGyroZRef();
		g_log_count = 0;
		g_current_angle = 0;
		waitTime(1500);
		driveRGB(MAGENTA, ON);
		printLog();
		break;
	case 5: //////////////////////////////////////////////////////////////////////////////////////
		driveRGB(MAGENTA, ON);
		waitSensor();
		calcGyroZRef();
		g_log_count = 0;
		g_current_angle = 0;
		while (1) {
			myprintf("%8.5f %8.5f\n", g_current_angle, g_current_omega);
		}
		break;
	case 6: //////////////////////////////////////////////////////////////////////////////////////
		driveRGB(WHITE, ON);
		selectAdjustment1(T16);
		break;
	case 7: //////////////////////////////////////////////////////////////////////////////////////
		driveRGB(ORANGE, ON);
		waitSensor();
		driveRGB(GREEN, ON);
		waitTime(1000);
		calcGyroZRef();
		driveSuction(100, ON);
		waitTime(1000);
		initRun();
		driveMotor(ON);
		switchSensorLED(ON);
		runStraight(13, SECTION, 2.2, 2.2);
		g_log_count = 0;
		g_flag_FF = 1;
		turnCornerContinuous(90, 1400);
		runStraight(13, SECTION, 2.2, 0);
		driveRGB(BLUE, ON);
		waitTime(300);
		driveMotor(OFF);
		driveSuction(70, OFF);
		waitButton();
		printLog4();
		break;
	case 8: //////////////////////////////////////////////////////////////////////////////////////
		driveRGB(WATER, ON);
		switchSensorLED(ON);
		while (1) {
			myprintf("FL:%6.0f L:%6.0f R:%6.0f FR:%6.0f\n", g_sensor_FL_lowpass,
								g_sensor_L_lowpass, g_sensor_R_lowpass, g_sensor_FR_lowpass);
//			myprintf("FL:%6.1d L:%6.1d R:%6.1d FR:%6.1d\n", g_sensor_FL,
//					g_sensor_L, g_sensor_R, g_sensor_FR);
//			myprintf("%4.1d	%4.1d\n", g_sensor_FL, g_sensor_FR);
			waitTime(50);
		}
		break;
	case 9: //////////////////////////////////////////////////////////////////////////////////////
		driveRGB(LBLUE, ON);
		waitSensor();
		calcGyroZRef();
		g_flag_control = 1;

		driveMotor(ON);
		waitTime(2000);
		waitButton();
		printLog4();
		break;
	case 10: //////////////////////////////////////////////////////////////////////////////////////
		driveRGB(LRED, ON);
		waitSensor();

		calcGyroZRef();
		switchSensorLED(ON);
		g_flag_control = 1;
		g_flag_blindalley = 2;
		driveMotor(ON);
		while (1) {

		}
		break;
	default: //////////////////////////////////////////////////////////////////////////////////////
		break;
	}

}

/*


 while (1) {
 myprintf("%f\n", returnGyroZVal());
 waitTime(50);
 }





 switchSensorLED(ON);
 waitSensor();
 soundStart();
 g_flag_control = 1;
 g_log_count = 0;
 g_distance = 0;
 calcGyroZRef();

 driveMotor(ON);

 runStraight(5, SECTION, 1.3, 1);

 turnCorner(t_180_R_10);

 runStraight(5, SECTION, 1.3, 0);
 switchSensorLED(ON);
 driveMotor(OFF);
 waitButton();
 printLog();





 waitTime(3000);
 driveRGB(GREEN, ON);
 calcGyroZRef();

 while (1) {

 myprintf("%f %f\n", g_current_angularvelo, g_angle);

 }



 waitSensor();
 driveRGB(CYAN, ON);
 switchSensorLED(ON);
 driveMotor(ON);
 waitTime(1000);
 soundStartSearch();
 calcGyroZRef();
 initRun();

 searchAdachi();
 switchSensorLED(OFF);
 driveMotor(OFF);
 setCurrentCoord(START_X, START_Y);

 g_orient = 0x01;
 countStepShortest();
 makePath();
 makePath2();
 makePath3();

 //for (i = 0; i < 2; i++) {
 while(1){
 driveRGB(BLUE, ON);
 waitButton();
 waitSensor();
 switchSensorLED(ON);

 driveRGB(GREEN, ON);
 waitTime(1000);
 calcGyroZRef();
 soundStartRun();
 driveSuction(70, ON);
 waitTime(1000);
 initRun();
 driveMotor(ON);
 runPathDiagonal2();
 switchSensorLED(ON);
 driveMotor(OFF);
 driveSuction(100, OFF);
 }
 waitButton();
 printLog();



 waitSensor();
 waitTime(1000);
 calcGyroZRef();
 g_current_angle = 0;
 g_current_angularvelo = 0;
 g_log_count = 0;
 waitTime(1500);
 while (1) {
 myprintf("%f	%f	%f\n", g_current_angle, g_current_angularvelo,
 g_gyro_reference);

 }
 soundSensor();
 printLog();

 FLASH.DFLWE0.WORD = 0x1EFF; //プロテクト解除
 changeFCUMode(1, 1, P_E);
 driveRGB(RED, ON);
 notificateClock(1, 1);

 eraseFCU(0, 0);
 driveRGB(BLUE, ON);
 programFCU(1, 1, 0x44);

 driveRGB(GREEN, ON);
 changeFCUMode(1, 1, READ);
 myprintf("%d\n", readFCUValue(1, 1));

 FLASH.DFLWE0.WORD = 0x1E00; // disable
 */
