#ifndef ABSTAND_H
#define ABSTAND_H

class Abstand
{
private:
    float b;        //Bildweite in mm
    float G;        //Objekthöhe in mm
    float f;        //Brennweite in mm
    float phi;      //Neigungswinkel Kamera (RADIAN)
    float GStrich;  //auf Fokusebene projizierte Objekthöhe(Berechnung noch nicht klar)
    float B;        // Abbildungshöhe (Sensor)
    float g;        //Abstand Kamera-Fokusebene
    float D;        // Horizontale (noch nicht normale) Distanz
    float H;        // Kamerahöhe
    float I;        // siehe Zeichnung
//    float J;        // siehe Zeichnung
    float BI;       // "Bild" der Strecke I auf Sensor
    float hs;       // Sensorhöhe (Handy aufrecht)
    float bs;       // Sensorbreite (Handy aufrecht)

    float x,y,z;    // Anteile am Gravitationsvektor


//    float gStrich;     // waagerechter u. rechtwinkliger Abstand zur Bande
    float beta;     // Winkel zw Bildoberkante u. Sensormitte

public:
    Abstand();
    ~Abstand();

    void setParameter(float B, float beta, float BI, float x, float y, float z);


    float Berechnungg();
    float BerechnungD();
    float BerechnungH();


};

#endif
