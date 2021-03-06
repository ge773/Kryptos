/*
 * intrpt.h
 *
 *  Created on: 2016/05/24
 *      Author: 元太
 */

#ifndef INTRPT_H_
#define INTRPT_H_

/****************************************
 割り込み関数CMT0
 ****************************************/
void intrptCMT0();
/****************************************
 割り込み関数CMT1
 ****************************************/
void intrptCMT1();

/****************************************
 ログ取得関数　割り込み
 ****************************************/
void getLog(float log1, float log2);
void getLog4(float log1, float log2, float log3, float log4);
void getLogInt(int16_t log1, int16_t log2);
/****************************************
 モード用速度取得関数　割り込み
 ****************************************/
void getModeVelocity(void);
/****************************************
 Dutyセット関数　割り込み
 ****************************************/
void setMotorDuty(void);
/****************************************
 加速　割り込み
 ****************************************/
void calcAcc(void);
/****************************************
 距離加算　割り込み
 ****************************************/
void calcDistance(void);

/****************************************
 角加速　割り込み
 ****************************************/
void calcAngularAcc(void);
/****************************************
 角度加算　割り込み
 ****************************************/
void calcAngle(void);
/****************************************
 バッテリー電圧取得
 ****************************************/
float getBatteryVoltage(void);
/****************************************
 壁切れ判定
 ****************************************/
uint8_t checkPillarEdgeL();
uint8_t checkPillarEdgeR();
/****************************************
 センサー値取得　割り込み
 ****************************************/
void getSensorVal(void);
/****************************************
フェイルセーフ　割り込み
 ****************************************/
void checkFailsafe(float velo,float angularvelo,float sensor);
#endif /* INTRPT_H_ */
