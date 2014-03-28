#include <iostream>
#include <math.h>
#include "abstand.h"

void Abstand::setParameter(float B, float beta, float BI, float x, float y, float z)
{this->B=B;
this->beta=beta;
this->BI=BI;
this->x=x;
this->y=y;
this->z=z;
}

// Berechnung des Abstandes zur Fokusebene
float Abstand::Berechnungg()
{
    this->phi=acos(sqrt(x*x+y*y)/sqrt(x*x+y*y+z*z));
    this->GStrich=G*cos(phi)-G*tan(phi)*tan(beta);
    this->g=f*((this->GStrich/this->B)+1);
    return this->g;
}
// Berechnung des horizontalen (noch nicht normalen) Abstandes
float Abstand::BerechnungD()
{
    this->D=cos(phi)*(g-sin(this->phi)*(g-f)*BI);
    return D;
}
// Berechnung der Kamerahöhe
float Abstand::BerechnungH()
{
    this->H=this->D*tan(phi)+G;
    return H;
}


Abstand::Abstand()
{
 G=310;     // Bandenhöhe [mm]
 //b=??     // Bildweite
 f=3.7 ;    // Brennweite Galaxy S3 [mm]
 hs=4.54;       // Sensorhöhe Galaxy S3 [mm] (Handy aufrecht)
 bs=3.42;       // Sensorbreite Galaxy S3 [mm] (Handy aufrecht)
 // Auflösung reinbringen?? Pixel zählen einfacher als Abstand berechnen
}

Abstand::~Abstand()
{
}
