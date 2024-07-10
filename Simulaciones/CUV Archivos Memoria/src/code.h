#ifndef MULTIPLICAR_H
#define MULTIPLICAR_H

void  abc_ab(double* alpha, double* beta, double a, double b, double c);
void FC_cuad(double* gx, double ia_ref, double ib_ref, double ik1_a, double ik1_b);
void optp(double* g_opt, int* x_opt, double gx, int x, double Sa, double Sb, double Sc, double Sao, double Sbo, double Sco);
void opt(double* g_opt, int* x_opt, double gx, int x);
void abc_dq(double* d, double* q, double theta, double a, double b, double c);
void Vabc_dq(double* d, double* q, double theta, int Vdc, double a, double b, double c);
void PLL(double vq, double* theta, double C1, double C2, double h,double* w,double* e_ant);
void angle(double* theta, double h, double w, double dp);
void Vck1(double* Vcd_k1, double* Vcq_k1, double Vd_ant, double Vq_ant, double Vcd, double Vcq, double Vcd_ant, double Vcq_ant, double i2d_k, double i2q_k, double i2d_ant, double i2q_ant, double L1, double h, double Cf, double w, double d1_L1C);
void act(double* Vgd_ant, double* Vgq_ant, double* Vd_ant, double* Vq_ant, double* Vcd_ant, double* Vcq_ant, double* i2d_ant, double* i2q_ant, double ed, double eq, double V_d, double V_q, double Vcd, double Vcq, double i2d_k, double i2q_k);
void ik1(double* ik1_d, double* ik1_q, double i2d_k, double i2q_k, double Vcd, double Vcq, double h, double w, double R, double d1_L2, double Vgd, double Vgq);
void Vgk1(double* Vgd_k1, double* Vgq_k1, double i2d, double i2q, double igd, double igq ,double Vgd, double Vgq, double h, double d1_C2, double w);
void Sx(int* Sx, int S1, int S3);
void MPPT(double* vpvk, double* ipvk, double* ppvk, double* cont, double* cont2, double* cont4, double* vpvk_1, double* ppvk_1, double* vpv_ref, double* vpv_ref_1, double* vpv_ref_max, double* ppvk_ref_max, double* rampa, double Fs, double deltaV, double deltaV2, double vpv_min, double vpv_max);
void CTension(double* ic_ref,double* i_ref, double ipv, double* ic_act, double e_actv, double* x_actv, double vpv_ref, double vpv, double* x_antv, double* ic_ant, double C1v, double C2v, double kpv, double satv);
void CCorriente(double* d_acta, double i_refa, double e_acta, double C1, double C2, double i_La, double* x_acta, double* x_anta, double* d_anta, double kp, double sat);
void CT_bess(double* u_actv, double vf_ref, double e_actv, double C1v, double C2v, double vf, double* x_actv, double* x_antv, double* u_antv, double kpv, double vcontmax, double vcontmin);
void i1p(double* ik1_d, double* ik1_q, double h, double d1_L1, double w, double i1d, double i1q, double Vd, double Vq, double Vcd, double Vcq);
void Vcp(double* Vcd_k1, double* Vcq_k1, double h, double d1_c, double w, double i1d, double i1q, double i2d, double i2q, double Vcd, double Vcq);
void i2p(double* ik1_d, double* ik1_q, double i2d_k, double i2q_k, double Vcd, double Vcq, double h, double w, double R, double d1_L2, double Vgd, double Vgq);
//void Ref(double* id_r, double* Vcd_r, double P, double Vgd_r, double R);
void Ref(double* id_r, double* iq_r, double* Vcd_r, double* Vcq_r, double P, double Vgd_r, double Vgq_r, double R);

#endif