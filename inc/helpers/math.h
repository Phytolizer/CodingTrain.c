#pragma once

int math_map_i(int value, int input_min, int input_max, int output_min, int output_max);
double math_map_d(double value, double input_min, double input_max, double output_min, double output_max);

#define math_map(value, input_min, input_max, output_min, output_max)                                                  \
    _Generic((value), int : math_map_i, double : math_map_d)(value, input_min, input_max, output_min, output_max)