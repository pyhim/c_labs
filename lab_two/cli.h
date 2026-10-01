//
// Created by dmytro on 23.09.2026.
//

#pragma once

#include "../utils/math.h"

int ask_for_value(double *value_out, char value_label);

void print_equation_result(int equation_id, double result, const math_debug_code_t *dbg_code);

int start_menu();