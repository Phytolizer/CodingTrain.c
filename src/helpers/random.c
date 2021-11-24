#include "helpers/random.h"
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int rand_range_i(int min, int max)
{
    static bool seeded = false;
    if (!seeded)
    {
        srand(time(NULL));
        seeded = true;
    }
    return rand() % (max - min + 1) + min;
}

double rand_range_d(double min, double max)
{
    static bool seeded = false;
    if (!seeded)
    {
        srand(time(NULL));
        seeded = true;
    }
    return (double)rand() / (double)RAND_MAX * (max - min) + min;
}