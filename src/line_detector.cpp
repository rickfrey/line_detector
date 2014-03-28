/*#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>


#include <iostream>

int main(int argc, char **argv)
{
//ros::init(int argc, char **argv);
  ros::NodeHandle n;
  std::cout << "Hello World!";
  return 0;
}
*/

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include "abstand.h"
#include "normabstand.h"

using namespace cv;
using namespace std;

void help()
{
 cout << "\nThis program demonstrates line finding with the Hough transform.\n"
         "Usage:\n"
         "./houghlines <image_name>, Default is pic1.jpg\n" << endl;
}

int main(int argc, char** argv)
{
 //const char* filename = argc >= 2 ? argv[1] : "home/rick/catkin_ws/src/line_detector/pic1.jpg";
    //Mat src = imread(pic2.jpg,0);
 //Mat src = imread(filename, 0);

    const char* imagename= "pic3.jpg";
            Mat src = imread(imagename);

 if(src.empty())
 {
     help();
     cout << "can not open " << "filename" << endl;
     return -1;
 }

 Mat dst, cdst;
 //Canny(src, dst, 43, 44, 3);
 cv::Canny(src,dst,60,80,3);
 cvtColor(dst, cdst, CV_GRAY2BGR);



                // ICH MUSS EINE PROJEKTION DES GRAVITATIONSVEKTORS AUF DIE X-Y-EBENE MACHEN (WIE FÜR PHI)
                // DER WINKEL ZUR X-ACHSE ENTSPRICHT THETA, SO KANN EINE LINIE GEZEICHNET WERDEN!
                // DIE SCHNITTPUNKTE DIESER MIT DEN BEIDEN BANDENLINIEN MÜSSEN GEFUNDEN WERDEN, UM DAS BILD DER BANDENHÖHE ZU BERECHNEN!!!



 #if 1
  vector<Vec2f> lines;
  HoughLines(dst, lines, 1, CV_PI/180, 200, 0, 0 );

 /********************************************
Alle Linien rausschmeißen, die in Richtung Gravitationsvektor zeigen (Überprüfen der Theta-Werte)
=> AKTUELL NUR ÜBER WINKEL, ANSCHLIEßEND ÜBER GRAVITATIONSVEKTOR!!!
    for (int j=0;j<lines.size();j++)
{
        if (lines[j][1]> CV_PI/4 && lines[j][1]< 3*CV_PI/4)
  {
  lines[j][1]=0;
  lines[j][0]=0;
  }
}
************************************************/

  for( size_t i = 0; i < lines.size(); i++ )
  {
     float rho = lines[i][0], theta = lines[i][1];
     Point pt1, pt2;
     double a = cos(theta), b = sin(theta);
     double x0 = a*rho, y0 = b*rho;
     pt1.x = cvRound(x0 + 2000*(-b)); // Point pt1 = Schnittpunkt der Gerade mit der ersten Bildzeile (obere Bildkante)
     pt1.y = cvRound(y0 + 2000*(a));  // cvRound rundet float auf eine integer
     pt2.x = cvRound(x0 - 2000*(-b)); // Point pt1 = Schnittpunkt der Gerade mit letzten Bildzeile
     pt2.y = cvRound(y0 - 2000*(a));
     cout<<"lines["<<i<<"][0]="<<lines[i][0]<<"; " <<"lines["<<i<<"][1]="<<lines[i][1]<<endl;// Ausgabe der Einträge von lines
     line( cdst, pt1, pt2, Scalar(0,0,255), 1, CV_AA);//Hier wird eine Linie gezeichnet!!! CV_AA ist Linientyp
  }
  std::cout << lines[0][0] << endl << lines[0][1]<< std::endl;
 #else
  vector<Vec4i> lines;
  HoughLinesP(dst, lines, 1, CV_PI/180, 50, 50, 10 );
  for( size_t i = 0; i < lines.size(); i++ )
  {
    Vec4i l = lines[i];
    line( cdst, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0,0,255), 3, CV_AA);
  }

 #endif


  //GRAVITATIONSVEKTOR:
  float x,y,z;
  x=0.20111294;
  y=7.5561004;
  z=4.7405195;

  //TEST:ANFANG
 // float kk=0,iii;
 // vector<Vec2f> Punkteoben;
//  Punkteoben[1][0]=33.5;
  //        cout<<"Punkteoben[0][0]"<<Punkteoben[0][0]<<endl;
  /*for(iii=0;iii<14;iii++)
  {
      Punkteoben[iii][0]=kk;
      Punkteoben[iii][1]=0;
      kk=kk+40;
  }*/
  //TEST:ENDE

  // ERZEUGEN DER BILDRANDPUNKTE (NACHHER IN SCHLEIFE PACKEN)
  Point o1,o2,o3,o4,o5,o6,o7,o8,o9,o10,o11,o12,o13;                       // Punkte am oberen (kürzeren) Bildrand
  Point s1,s2,s3,s4,s5,s6,s7,s8,s9,s10,s11,s12,s13,s14,s15,s16,s17;       // Punkte am linken seitlichen (längeren) Bildrand

  o1.x=0, o1.y=0;
  o2.x=0, o2.y=40;
  o3.x=0, o3.y=80;
  o4.x=0, o4.y=120;
  o5.x=0, o5.y=160;
  o6.x=0, o6.y=200;
  o7.x=0, o7.y=240;
  o8.x=0, o8.y=280;
  o9.x=0, o9.y=320;
  o10.x=0, o10.y=360;
  o11.x=0, o11.y=400;
  o12.x=0, o12.y=440;
  o13.x=0, o13.y=480;
  circle(cdst,o1,5,255,-1,CV_AA),circle(cdst,o2,5,255,-1,CV_AA),circle(cdst,o3,5,255,-1,CV_AA),circle(cdst,o4,5,255,-1,CV_AA),circle(cdst,o5,5,255,-1,CV_AA);
  circle(cdst,o6,5,255,-1,CV_AA),circle(cdst,o7,5,255,-1,CV_AA),circle(cdst,o8,5,255,-1,CV_AA),circle(cdst,o9,5,255,-1,CV_AA),circle(cdst,o9,5,255,-1,CV_AA);
  circle(cdst,o10,5,255,-1,CV_AA),circle(cdst,o11,5,255,-1,CV_AA),circle(cdst,o12,5,255,-1,CV_AA),circle(cdst,o13,5,255,-1,CV_AA);

  s1.x=0, s1.y=0;
  s2.x=40, s2.y=0;
  s3.x=80, s3.y=0;
  s4.x=120, s4.y=0;
  s5.x=160, s5.y=0;
  s6.x=200, s6.y=0;
  s7.x=240, s7.y=0;
  s8.x=280, s8.y=0;
  s9.x=320, s9.y=0;
  s10.x=360, s10.y=0;
  s11.x=400, s11.y=0;
  s12.x=440, s12.y=0;
  s13.x=480, s13.y=0;
  s14.x=520, s14.y=0;
  s15.x=560, s15.y=0;
  s16.x=600, s16.y=0;
  s17.x=640, s17.y=0;
  circle(cdst,s1,5,255,-1,CV_AA),circle(cdst,s2,5,255,-1,CV_AA),circle(cdst,s3,5,255,-1,CV_AA),circle(cdst,s4,5,255,-1,CV_AA),circle(cdst,s5,5,255,-1,CV_AA);
  circle(cdst,s6,5,255,-1,CV_AA),circle(cdst,s7,5,255,-1,CV_AA),circle(cdst,s8,5,255,-1,CV_AA),circle(cdst,s9,5,255,-1,CV_AA),circle(cdst,s9,5,255,-1,CV_AA);
  circle(cdst,s10,5,255,-1,CV_AA),circle(cdst,s11,5,255,-1,CV_AA),circle(cdst,s12,5,255,-1,CV_AA),circle(cdst,s13,5,255,-1,CV_AA),circle(cdst,s14,5,255,-1,CV_AA),
  circle(cdst,s15,5,255,-1,CV_AA),circle(cdst,s16,5,255,-1,CV_AA),circle(cdst,s17,5,255,-1,CV_AA);

  // GRAVITATIONS-KOS IN BILD-KOS WANDELN
  float xBild=y, yBild=x;

  // ERZEUGUNG DER JEWEILS ZWEITEN PUNKTE (z für zwei)
  Point o1z,o2z,o3z,o4z,o5z,o6z,o7z,o8z,o9z,o10z,o11z,o12z,o13z;


  o3z.x=o3.x+cvRound(70*xBild);
  o3z.y=o3.y+cvRound(70*yBild);
  circle(cdst,o3z,5,255,-1,CV_AA);
  line(cdst,o3,o3z,Scalar(0,0,255),1,CV_AA);// Linie, die Punkt o3 und o3z verbindet


  //Bestimmung des ersten Schnittpunktes von Lines mit der Gravitationslinie von Punkt o3
  Point L1P1,L1P2;  //Linie1: Punkt1, Punkt2
  L1P1.x=(lines[0][0])*cos(lines[0][1]);
  L1P1.y=lines[0][0]*sin(lines[0][1]);
  L1P2.x=L1P1.x+400*sin(lines[0][1]);
  L1P2.y=L1P1.y-400*cos(lines[0][1]);
  line(cdst,L1P1,L1P2,Scalar(0,0,255),3,CV_AA);

  //Schnittpunkt: selbe Gravitationslinie, andere Bandenlinie:
  Point L2P1,L2P2;
  L2P1.x=(lines[1][0])*cos(lines[1][1]);
  L2P1.y=lines[1][0]*sin(lines[1][1]);
  L2P2.x=L1P1.x+400*sin(lines[1][1]);
  L2P2.y=L1P1.y-400*cos(lines[1][1]);



// Berechnung des Schnittpunktes (Stützvektor)+t*(Richtungsvektor)
  float aa=L1P1.x,bb=L1P1.y,cc=sin(lines[0][1]),dd=(-cos(lines[0][1])),ee=o3.x,ff=o3.y,gg=xBild,hh=yBild;
  float t=(cc*(bb-ff)+dd*(ee-aa))/(cc*hh-gg*dd);

// Einsetzen für t in Geradengleichung => Schnittpunkt
  Point SP;                     //Schnittpunkt
  SP.x=cvRound(o3.x+t*xBild);
  SP.y=cvRound(o3.y+t*yBild);
  cout<<"SP.x="<<SP.x<<endl;
  cout<<"SP.y="<<SP.y<<endl;
  circle(cdst,SP,5,255,-1,CV_AA);
  //TEST, OB PUNKTE AUF GERADEN LIEGEN
  Point Test,Test2;
  Test.x=L1P1.x+220*sin(lines[0][1]), Test.y=L1P1.y+220*(-cos(lines[0][1]));
  circle(cdst,Test,5,255,-1,CV_AA);
  Test2.x=o3.x+10*xBild;
  Test2.y=o3.y+10*yBild;
  circle(cdst,Test2,5,255,-1,CV_AA);



 namedWindow( "source",WINDOW_NORMAL);
 imshow("source", src);
 namedWindow( "detected lines",WINDOW_NORMAL);
 imshow("detected lines", cdst);

float beta= 3.14/12;
float B=2.3; //Abbildungshöhe
float BI=1;
Abstand Distanz1;
Distanz1.setParameter(B,beta,BI,x,y,z);
float g1=Distanz1.Berechnungg();
float D1=Distanz1.BerechnungD();
float H1=Distanz1.BerechnungH();
std::cout<<"g1="<<g1<<endl<<"D1="<<D1<<endl<<"H1="<<H1<<endl;

float beta2=3.14/12;
float B2=2.4;
float BI2=1.2;
Abstand Distanz2;
Distanz2.setParameter(B2,beta2,BI2,x,y,z);
float g2=Distanz2.Berechnungg();
float D2=Distanz2.BerechnungD();
float H2=Distanz2.BerechnungH();
std::cout<<"g2="<<g2<<endl<<"D2="<<D2<<endl<<"H2="<<H2<<endl;

float alpha=3.1415/6;
Normabstand rechtwinkligerabstand1;
rechtwinkligerabstand1.setParameter(D1,D2,alpha);
float DN=rechtwinkligerabstand1.BerechnungDN();

std::cout<<"c="<<rechtwinkligerabstand1.getc()<<endl<<"DN="<<DN<<endl;




//std::cout<<"PHI (radian)="<<PHI<<endl;
//std::cout<<"PHI (degree)="<<PHI*360/(2*3.1415)<<endl;


//vector<Vec3f> Gravitationsvektor;
//Gravitationsvektor[0][0]=x;
//Gravitationsvektor[0][0]=y;
//Gravitationsvektor[0][0]=z;



 waitKey();

 return 0;
}
