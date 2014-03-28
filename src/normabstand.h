#ifndef NORMABSTAND_H
#define NORMABSTAND_H

class Normabstand
{
private:
    float d1;       // Distanz 1
    float d2;       // Distanz 2
    float gamma;    // Winkel Gamma
    float alpha;    // Öffnungswinkel
    float c;        // Strecke c
    float DN;       // normaler Abstand


public:
    Normabstand();
    ~Normabstand();

    void setParameter(float d1, float d2, float alpha);

    float BerechnungDN();

//NUR TEST:
    float getc();

};

#endif
