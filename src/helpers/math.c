#include "helpers/math.h"

int math_map_i(int value, int input_min, int input_max, int output_min, int output_max)
{
    return (value - input_min) * (output_max - output_min) / (input_max - input_min) + output_min;
}

double math_map_d(double value, double input_min, double input_max, double output_min, double output_max)
{
    return (value - input_min) * (output_max - output_min) / (input_max - input_min) + output_min;
}
