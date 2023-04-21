#include "Suplimental.h"
#include <ctime>
#include <iostream>

 float Suplimental::RandZeroToOne()
{
    float RandNumb = 0;
    RandNumb = (1 + rand() % 100);
    RandNumb = RandNumb / 100;

    return RandNumb;
}
