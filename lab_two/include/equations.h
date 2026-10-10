//
// Created by dmytro on 23.09.2026.
//

#pragma once

#include <utils/math.h>

// K = 4
// ((N^3 + K^2) % 60) + 1 = [5, 8, 7, 2, 1]
// Дурак, це ж оператор побітове виключне АБО, правильно буде:
// ((N * N * N + K * K) % 60) + 1 = [18, 25, 44, 21, 22]

double task18(double x, double y, math_debug_code *dbg_code);

double task21(double x, math_debug_code *dbg_code);

double task22(double x, double y, math_debug_code *dbg_code);

double task25(double x, double y, math_debug_code *dbg_code);

double task44(double x, double y, math_debug_code *dbg_code);

/*double task1(double x, math_debug_code *dbg_code);

double task2(double x, double y, math_debug_code *dbg_code);

double task5(double x, math_debug_code *dbg_code);

double task7(double x, double y, math_debug_code *dbg_code);

double task8(double x, math_debug_code *dbg_code);*/
