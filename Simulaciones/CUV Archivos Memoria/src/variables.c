static double h; 
static double Vdc; 
static double R;
static double L;
static double w;
static double tau;
static double tau1;
static double R1;
static double id_r;
static double iq_r;
static double e;
static double L1;
static double L2;
static double Cf;
static double Vcd_r;
static double Vcq_r;
static double d1_L1C;
static double d1_L2;
static double d1_C2;
static double Vgd_r;
static double Vgq_r;

double ik_d=0, ik_q=0, ik1_d=0, ik1_q=0;
double V_d=0, V_q=0;
int Sa=0, Sb=0, Sc=0;
double Vd_ant_2=0, Vd_ant=0, Vgd_ant_2=0, Vgd_ant=0;
double Vq_ant_2=0, Vq_ant=0, Vgq_ant_2=0, Vgq_ant=0;
double Vcdp=0, Vcqp=0;
double Vcd_ant_2=0, Vcd_ant=0, Vcd=0, Vcd_k0=0, Vcd_k1=0;
double Vcq_ant_2=0, Vcq_ant=0, Vcq=0, Vcq_k0=0, Vcq_k1=0;
double i2d_k=0, i2d_k0=0, i2d_k1=0, i2d_ant=0, i2d_ant_2=0;
double i2q_k=0, i2q_k0=0, i2q_k1=0, i2q_ant=0, i2q_ant_2=0;
double igd=0, igq=0;
double Vgd_k0=0, Vgq_k0=0, Vgd_k1=0, Vgq_k1=0;
double id_ref=30, iq_ref=0;
double ia_ref=0, ib_ref=0;
double id=0, iq=0, theta=0; 
double ed=0, xd=0, vd=0, edp=0;
double eq=0, xq=0, vq=0, eqp=0;
double ma=0, mb=0, mc=0;
double sat=1.15, dp=6.28318530718;
//double C1=0.8842, C2=50.3295;
double C1=431.7144964111, C2=-427.1047253342;
double kp=-0.0023010106499219266408540196522381;
double g[512], g_opt=10000000;
double gv[512];
double gb[512];
double t=0, gx=0, e_ant=0;
double ik0_d=0, ik0_q=0;
double e1=-0.99;

int cont_v=0;
int x=0;
int x_opt=0;
//Sa=[-1 -1 -1 -1 -1 -1 -1 -1 -1 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1]
Sa1=[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1];
Sa2=[0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0];
Sa3=[1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0];
//Sb=[-1 -1 -1  0 0 0  1 1 1  |-1 -1 -1  0 0 0    1 1 1 | -1 -1 -1  0 0 0    1 1 1]
Sb1=[0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1];
Sb2=[0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0];
Sb3=[1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0];
//Sc=[-1,0,1,-1,0,1,-1,0,1,-1,0,1,-1,0,1,-1,0,1,-1,0,1,-1,0,1,-1,0,1]
Sc1=[0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1];
Sc2=[0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0];
Sc3=[1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0];



#define sq3	1.732050807568877
#define sq3_2 0.86602540378
#define sq3_3 0.57735026919
#define d2_3 0.66666666666666666666666666666666666666666666666666666666666666
#define d1_3 0.3333333333333333333333333333333333333333333333333333333333333333
#define d1_sq3 0.57735026918962576450914878050196
#define pi  3.1415926535897932384626433832795
