#include <stdio.h>
#include <cmath>
#include "MyMathFunctions.h"
#include "TutorialConfig.h"

// a hack square root calculation using simple operations
double mysqrt(double x)
{
    if (x <= 0)
    {
        return 0;
    }

    double result;
    double delta;
    result = x;

    // do ten iterations
    int i;
    for (i = 0; i < 10; ++i)
    {
        if (result <= 0)
        {
            result = 0.1;
        }
        delta = x - (result * result);
#if defined(HAVE_LOG) && defined(HAVE_EXP)
        result = exp(log(x) * 0.5);
    }
    fprintf(stdout, "use system log() and exp()\n");
#else
        result = result + 0.5 * delta / result;
    }
#endif

    return result;
}