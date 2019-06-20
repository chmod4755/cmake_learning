//A simple program that computes the square root of a number
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "TutorialConfig.h"
#include "mysqrt.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stdout, "%s Version %d.%d\n", PROJECT_NAME, Tutorial_VERSION_MAJOR, Tutorial_VERSION_MINOR);
        fprintf(stdout, "Usage: %s [number]\n", argv[0]);
        return 1;
    }

    double inputValue = atof(argv[1]);
    double outputValue = sqrt(inputValue);
    double myanswear = mysqrt(inputValue);
    fprintf(stdout, "The square root of the number %g is %g\n", inputValue, outputValue);
    fprintf(stdout, "mysqrt answear is %g\n",  myanswear);
    return 0;
}