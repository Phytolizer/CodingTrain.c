#pragma once

int rand_range_i(int min, int max);
double rand_range_d(double min, double max);

#define rand_range(min, max) _Generic((min), int : rand_range_i, double : rand_range_d)((min), (max))