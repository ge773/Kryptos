/*
 * global.h
 *
 *  Created on: 2016/10/02
 *      Author: Gen
 */

#ifndef GLOBAL_H_
#define GLOBAL_H_

#include "my_typedef.h"

/****************************************
 グローバル変数extern宣言
 ****************************************/
//モード選択用速度取得変数
extern volatile float g_mode_velo;
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//目標速度
extern volatile float g_target_velo;
//現在速度
extern volatile float g_current_velo;
//現在偏差
extern volatile float g_velo_error;
//偏差積分
extern volatile float g_velo_error_integral;
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//目標角速度
extern volatile float g_target_omega;
extern volatile float g_target_omega_max;
//現在角速度
extern volatile float g_current_omega;
extern volatile float g_current_omega_tmp;
//現在偏差
extern volatile float g_omega_error;
//偏差積分
extern volatile float g_omega_error_integral;
//偏差微分
extern volatile float g_omega_error_derivative;
//Gyro　リファレンス
extern volatile float g_gyro_reference;
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//目標角度
extern volatile float g_target_angle;
extern volatile float g_target_angle_const;
extern volatile float g_count_time_angle;
//現在角度
extern volatile float g_current_angle;
//現在偏差
extern volatile float g_angle_error;
//偏差積分
extern volatile float g_angle_error_integral;

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//距離
extern volatile float g_distance;
//加速度
extern volatile float g_accele;
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//現在角加速度
extern volatile float g_target_alpha;
//最高角加速度
extern volatile float g_alpha_max;
extern volatile float g_turn_peaktime;
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//センサ
extern volatile int32_t g_sensor_FL;
extern volatile int32_t g_sensor_FR;
extern volatile int32_t g_sensor_L;
extern volatile int32_t g_sensor_R;

extern volatile float g_sensor_FL_lowpass;
extern volatile float g_sensor_FR_lowpass;
extern volatile float g_sensor_L_lowpass;
extern volatile float g_sensor_R_lowpass;

extern volatile int32_t g_sensor_L_derivative;
extern volatile int32_t g_sensor_R_derivative;
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//バッテリー電圧
extern volatile float g_battery_voltage;
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//エンコーダ差分
extern volatile float g_encoder_diff_L;
extern volatile float g_encoder_diff_R;
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//トルク
extern volatile float g_torque_L;
extern volatile float g_torque_R;

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//map
extern uint8_t g_orient;
extern volatile uint8_t g_current_x;
extern volatile uint8_t g_current_y;

extern wall_t g_wall_info[15];
extern wall_t g_wall_info_tmp[15];

extern step_t g_step[16];

extern volatile int16_t g_target_x;
extern volatile int16_t g_target_y;
extern volatile uint8_t g_step_map[16][16];
extern volatile uint16_t g_path[1024];
extern volatile uint16_t g_path_2[1024];
extern volatile uint16_t g_path_3[256];

extern volatile uint8_t g_flag_step_goal;
extern volatile uint8_t g_flag_step_goal_2;
extern volatile uint8_t g_flag_step_goal_3;
extern volatile uint8_t g_flag_curve;
extern volatile uint8_t g_flag_adachi_goal;
extern volatile uint8_t g_flag_path_run_goal;
extern volatile uint8_t g_flag_diagonal;

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//フラグ
extern volatile int8_t g_flag_mode_setting;
extern volatile int8_t g_flag_turn;
extern volatile int8_t g_flag_control;
extern volatile int8_t g_flag_failsafe;
extern volatile int8_t g_flag_blindalley;
extern volatile int8_t g_flag_circuit;
extern volatile int8_t g_flag_run_mode;
extern volatile int8_t g_flag_pillar_edge_L;
extern volatile int8_t g_flag_pillar_edge_R;
extern volatile int8_t g_flag_shortest_goal;
extern volatile int8_t g_flag_turn_continuous;
extern volatile int8_t g_flag_FF;
extern volatile int8_t g_flag_buzzer;
extern volatile int8_t g_flag_run_known_section;
//テスト用

extern volatile float g_duty_L;
extern volatile float g_duty_R;
extern volatile int16_t g_wait_count;
extern volatile int16_t g_buzzer_count;
extern volatile int16_t g_log_count;
extern volatile float g_log_array[];
extern volatile float g_log_array2[];
extern volatile float g_log_array3[];
extern volatile float g_log_array4[];
extern volatile int16_t g_log_array_int[];
extern volatile int16_t g_log_array2_int[];
extern volatile int8_t g_flag_control;
extern volatile uint16_t g_path_test[];
extern volatile uint16_t g_path_test_slant[];
#endif /* GLOBAL_H_ */
