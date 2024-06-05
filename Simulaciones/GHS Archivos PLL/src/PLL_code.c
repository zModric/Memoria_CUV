#include "PLL_code.h"
#include <stdio.h>
#include <stdlib.h>


void abc_dq(double theta, double a, double b, double c, double* d, double* q) {
    double CS=0.666666666666666666667;
    double PI23=2.0943951023931954923084289221863;
    *d=CS*(a*cos(theta)+b*cos(theta-PI23)+c*cos(theta+PI23));
    *q=-CS*(a*sin(theta)+b*sin(theta-PI23)+c*sin(theta+PI23));
}



void PLL(double vq, double* theta, double C1, double C2, double h,double* w,double* e_ant){
    double e_act=0;
    double tm=6.283185307179586476925286766559;
    e_act=(0+vq);
    *w=C1*e_act+C2*(*e_ant)+(*w);
    *theta+=(*w)*h;
    if(*theta<-tm){*theta+=tm;}
    if(*theta>tm){*theta-=tm;}
    *e_ant=e_act; 
}







