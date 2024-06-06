#include "code.h"
#include <stdio.h>
#include <stdlib.h>

void control(double In, double Ref, double* Out, double kp, double ki, double sat_up, double sat_down, double* x) {
    double e, C1, C2;
    //*Out = 1; // Asignar el valor 1 a la ubicación de memoria apuntada por Out
    C1 = (kp - ki) / kp;
    C2 = -ki / (kp * kp);
    e = Ref - In;
    *x = C1 * (*x) + C2 * (*Out); // Acceder al contenido de las ubicaciones de memoria apuntadas por x y Out
    *Out = kp * (e - (*x)); // Acceder al contenido de la ubicación de memoria apuntada por x
    if (*Out > sat_up)
        *Out = sat_up;
    else if (*Out < sat_down)
        *Out = sat_down;
}

void Sx(int* Sx, int S1, int S2, int S3, int S4){
    *Sx= S1-S4*(1-S1)*(S3+(1-S3)*(1-S2));
}

void abc_dq(double* d, double* q, double theta, double a, double b, double c) {
    double PI23=2.0943951023931954923084289221863;
    double CS=0.666666666666666666667;
    *d=CS*(a*cos(theta)+b*cos(theta-PI23)+c*cos(theta+PI23));
    *q=-CS*(a*sin(theta)+b*sin(theta-PI23)+c*sin(theta+PI23));
}
void Vabc_dq(double* d, double* q, double theta, int Vdc, double a, double b, double c) {
    double PI23=2.0943951023931954923084289221863;
    double CS=0.666666666666666666667;
    *d=0.5*Vdc*CS*(a*cos(theta)+b*cos(theta-PI23)+c*cos(theta+PI23));
    *q=-0.5*Vdc*CS*(a*sin(theta)+b*sin(theta-PI23)+c*sin(theta+PI23));
}
void  abc_ab(double* alpha, double* beta, double a, double b, double c) {
    double d2_3=0.66666666666666666666666666666666666666666666666666666666666666;
    double d1_3=0.3333333333333333333333333333333333333333333333333333333333333333;
    double d1_sq3=0.57735026918962576450914878050196;
    *alpha = (d2_3*a - d1_3*b - d1_3*c);
    *beta = (d1_sq3*b - d1_sq3*c); 
}

void Vck1(double* Vcd_k1, double* Vcq_k1, double Vd_ant, double Vq_ant, double Vcd, double Vcq, double Vcd_ant, double Vcq_ant, double i2d_k, double i2q_k, double i2d_ant, double i2q_ant, double L1, double h, double Cf, double w, double d1_L1C){    
    *Vcd_k1= Vd_ant*h*h*d1_L1C + 2*Vcd - Vcd_ant*(1-w*w*h*h+h*h*d1_L1C) + Vcq*2*w*h - Vcq_ant*2*w*h - i2d_k*L1*h*d1_L1C + i2d_ant*L1*h*d1_L1C + i2q_ant*w*L1*h*h*d1_L1C;
    *Vcq_k1= Vq_ant*h*h*d1_L1C + 2*Vcq - Vcq_ant*(1-w*w*h*h+h*h*d1_L1C) - Vcd*2*w*h + Vcd_ant*2*w*h - i2q_k*L1*h*d1_L1C + i2q_ant*L1*h*d1_L1C - i2d_ant*w*L1*h*h*d1_L1C;
}

void ik1(double* ik1_a, double* ik1_b, double ik_a, double ik_b, double V_a, double V_b, double h, double R1, double tau1, double e_d, double e_q){
    *ik1_a = ((V_a-e_d)*R1+ik_b)*(1-exp(-h*tau1)) - ik_a*exp(-h*(tau1));
    *ik1_b = ((V_b-e_q)*R1-ik_a)*(1-exp(-h*tau1)) - ik_b*exp(-h*(tau1));
}

void Vgk1(double* Vgd_k1, double* Vgq_k1, double i2d, double i2q, double igd, double igq ,double Vgd, double Vgq, double h, double d1_C2, double w){
    *Vgd_k1 = h*d1_C2*(i2d-igd) + w*h*Vgq+ Vgd;
    *Vgq_k1 = h*d1_C2*(i2q-igq) - w*h*Vgd+ Vgq;
}

void act(double* Vgd_ant, double* Vgq_ant, double* Vd_ant, double* Vq_ant, double* Vcd_ant, double* Vcq_ant, double* i2d_ant, double* i2q_ant, double ed, double eq, double V_d, double V_q, double Vcd, double Vcq, double i2d_k, double i2q_k){
    *Vgd_ant=ed;
    *Vgq_ant=eq;
    *Vd_ant=V_d;
    *Vq_ant=V_q;
    *Vcd_ant=Vcd;
    *Vcq_ant=Vcq;
    *i2d_ant=i2d_k;
    *i2q_ant=i2q_k;
}



void FC_cuad(double* gx, double ia_ref, double ib_ref, double ik1_a, double ik1_b){
    *gx=sqrt((ia_ref - ik1_a)*(ia_ref - ik1_a)) + sqrt((ib_ref - ik1_b)*(ib_ref - ik1_b));
}
void opt(double* g_opt, int* x_opt, double gx, int x){
    if (gx < *g_opt) {
        *g_opt = gx;
        *x_opt = x;
        }
}

void dq_abc(double theta, double* a, double* b, double* c, double d, double q) {
    double PI23=2.0943951023931954923084289221863;
    *a=d*cos(theta)-q*sin(theta);
    *b=d*cos(theta-PI23)-q*sin(theta-PI23); 
    *c=d*cos(theta+PI23)-q*sin(theta+PI23);
}
void minmax(double* a, double* b, double* c) {
    double min=100, max=-100, vmm=0;
    if(*a>max){max=*a;}
    if(*b>max){max=*b;}
    if(*c>max){max=*c;}
    if(*a<min){min=*a;}
    if(*b<min){min=*b;}
    if(*c<min){min=*c;}
    vmm=0.5*(min+max);
    *a=*a-vmm;
    *b=*b-vmm;
    *c=*c-vmm; 
}

void PLL(double vq, double* theta, double C1, double C2, double h,double* w, double* e_ant){
    double e_act=0;
    double tm=6.283185307179586476925286766559;
    e_act=(vq);
    *w=C1*e_act+C2*(*e_ant)+(*w);
    *theta+=(*w)*h;
    if(*theta<=-tm){*theta+=tm;}
    if(*theta>=tm){*theta-=tm;}
    *e_ant=e_act; 
}

void angle(double* theta, double h, double w, double dp){
    *theta+=w*h;
    if(*theta<-dp){*theta+=dp;}
    if(*theta>dp){*theta-=dp;}
}

void ramp(double* ramp,double rate,double ref,double h){
if(*ramp>=ref){
	*ramp=-rate*h*ref+(*ramp);
	if(*ramp<=ref)
		*ramp=ref;}
		
if(*ramp<=ref){
	*ramp=rate*h*ref+(*ramp);
	if(*ramp>=ref)
		*ramp=ref;}
}

void PBajo(double f, double h, double v,double* vf){
    double wc, c1;
    double PI=3.1415926535897932384626433832795;
    wc=2*PI*f;
    c1=exp(-wc*h);
    *vf=v*(1-c1)+c1*(*vf);
}


void ModeUD(int Step,double alpha,double* aD,double* aU,double* bD,double* bU,double* cD,double* cU,double* dD,double* dU,double* eD,double* eU,double* fD,double* fU,double* gD,double* gU,double* hD,double* hU){
if(Step==0)
{
    *aD=0.5;
    *aU=0;
    *bD=1;
    *bU=0.5;
    *cD=0.5+alpha;
    *cU=alpha;
    *dD=alpha;
    *dU=0.5+alpha;
    *eD=1;
    *eU=alpha;
    *fD=0.5;
    *fU=0.5+alpha;
    *gD=0.5;
    *gU=0.5+alpha;
    *hD=1;
    *hU=alpha;
}
else if(Step==1)
{
    *aD=0;
    *aU=0;
    *bD=0;
    *bU=0;
    *cD=0;
    *cU=0;
    *dD=0;
    *dU=0;
    *eD=0.5;
    *eU=0;
    *fD=1;
    *fU=0.5;
    *gD=0.5+alpha;
    *gU=alpha;
    *hD=alpha;
    *hU=0.5+alpha;
}
else
{
    *aD=0.5;
    *aU=0;
    *bD=1;
    *bU=0.5;
    *cD=0.5+alpha;
    *cU=alpha;
    *dD=alpha;
    *dU=0.5+alpha;
    *eD=1.1;
    *eU=0;
    *fD=1.1;
    *fU=0;
    *gD=1.1;
    *gU=0;
    *hD=1.1;
    *hU=0;
}
}


