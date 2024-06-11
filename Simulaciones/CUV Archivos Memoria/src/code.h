#ifndef MULTIPLICAR_H
#define MULTIPLICAR_H

//void control(double In, double Ref, double* Out, double kp, double ki, double sat_up, double sat_down, double* x);
void  abc_ab(double* alpha, double* beta, double a, double b, double c);
void FC_cuad(double* gx, double ia_ref, double ib_ref, double ik1_a, double ik1_b);
void opt(double* g_opt, int* x_opt, double gx, int x);
void abc_dq(double* d, double* q, double theta, double a, double b, double c);
void Vabc_dq(double* d, double* q, double theta, int Vdc, double a, double b, double c);
void PLL(double vq, double* theta, double C1, double C2, double h,double* w,double* e_ant);
void angle(double* theta, double h, double w, double dp);
void Vck1(double* Vcd_k1, double* Vcq_k1, double Vd_ant, double Vq_ant, double Vcd, double Vcq, double Vcd_ant, double Vcq_ant, double i2d_k, double i2q_k, double i2d_ant, double i2q_ant, double L1, double h, double Cf, double w, double d1_L1C);
void act(double* Vgd_ant, double* Vgq_ant, double* Vd_ant, double* Vq_ant, double* Vcd_ant, double* Vcq_ant, double* i2d_ant, double* i2q_ant, double ed, double eq, double V_d, double V_q, double Vcd, double Vcq, double i2d_k, double i2q_k);
//void ik1(double* ik1_a, double* ik1_b, double ik_a, double ik_b, double V_a, double V_b, double h, double R1, double tau1, double e_d, double e_q);
void ik1(double* ik1_d, double* ik1_q, double i2d_k, double i2q_k, double Vcd, double Vcq, double h, double w, double R, double d1_L2, double Vgd, double Vgq);
void Vgk1(double* Vgd_k1, double* Vgq_k1, double i2d, double i2q, double igd, double igq ,double Vgd, double Vgq, double h, double d1_C2, double w);
void Sx(int* Sx, int S1, int S3);
#endif