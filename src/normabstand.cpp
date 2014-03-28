#include <iostream>
#include <math.h>
#include "normabstand.h"

void Normabstand::setParameter(float d1, float d2, float alpha)
{
this->d1=d1;
this->d2=d2;
this->alpha=alpha;
}

float Normabstand::BerechnungDN()
{
    this->c=sqrt((d1*d1)+d2*d2-2*d1*d2*cos(alpha));
    this->gamma=asin(sin(alpha)*d2/c);
    this->DN=d1*sin(3.1415-gamma);
    return DN;
}

//NUR TEST:
float Normabstand::getc()
{
return c;
}


Normabstand::Normabstand()
{
}

Normabstand::~Normabstand()
{
}
