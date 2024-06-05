%% Ajuste de PLL
% Autor: Guillermo Huerta Soto
% Proyecto: Memoria Pablo Vera Soto: Filtro de Kalman extendido.
%--------------- Parámetros que se definen.----------------------------%
fs=2250;     % Frecuencia de muestreo del algoritmo PLL.
fb=50;       % Frecuencia base en Hz o ancho para tu lazo cerrado.
chi=1/2^0.5; % Amortiguamiento escogido para tu lazo cerrado.
%--------------- Parámetros que se definen.----------------------------%
wb=fb*2*pi;  % Frecuencia base en radianes o ancho de banda del sistema.
h=1/fs;      % Periodo de muestreo
s = tf('s');
z = tf('z',h);
% Al multiplicar el controlador C con la planta P se obtiene un sistema de
% segundo orden de la forma: H(s)=(a*s + wn^2)/(s^2+chi*wn*s+wn^2).A través de 
% la elección del ancho de banda y el damping podremos encontrar la frecuencia 
% natural con la siguiente formula tras impones que |H(jwb)|=sqrt(1/2):
wn=(wb^2*((2*chi^2+1)^2+1)^0.5-(2*chi^2+1)*wb^2)^0.5; %Frecuencia natural del sistema
ws=chi*wn;   % Rapidez del sistema en lazo cerrado
ts=2*pi/ws;  % Tiempo de asentamiento del sistema en lazo cerrado
fprintf('\n\n El tiempo de asentiamiento de la PLL es: %4.10f [s]; \n Es decir, %4.10f veces el periodo de la red;  \n',ts, ts/0.02)
% Parámetros para Método de asignación de polos | Ver:
% Tarea_2_Gálvez_Huerta.pdf: Sección II, página 5.
% Implementacion_digital_Control_2019: página 12.
% 040 CAP 2 SISTEMAS MUESTREADOS v3.1: ecuación 10, página 9.
do=1; 
no=h;
a1=-2*exp(-chi*wn*h)*cos(wn*h*sqrt(1-chi^2));
a2=exp(-2*chi*wn*h);
kc=(a1+do+1)/no;
nc=(do-a2)/(a1+do+1);
% Parámetros del controlador discreto
kp=kc;           % El controlador es: C=kp+ki/(z-1).
ki=kp*(-nc+1);   % El controlador es: C=kp+ki/(z-1).
C1=kp;           % El controlador es: C=(kp*z+(ki-kp))/(z-1). Entonces C1=kp.
C2=ki-kp;        % El controlador es: C=(kp*z+(ki-kp))/(z-1). Entonces C2=ki-kp.
% Parámetros C1 Y C2, en caso de que quieras probar un controlador que ya usaste antes.
% C1=431.6648323278;
% C2=-422.5442641741;
% kp=C1;
% ki=C1+C2;
% Reemplazo de controlador C discreto
C=kp+ki/(z-1);
% Planta del sistema modelado. Recordar que la planta es V/s, pero la
% entrada a la PLL se divide en V, por lo que la planta es la indicada
% aquí:
P=c2d(1/s,h);
% RLTOOL.
% rltool(P,C)
% Lo que debes escribir en PLECS en Simulation Parameters/Inicialization
fprintf('Los parámetros optimizados que debes copiar al final del código en Simulation Parameters/Inicialization son: \n\n C1p=%4.10f; \n C2p=%4.10f; \n',C1,C2)
%% Al Control System Designer -> Ir a Export -> Exportar C, Luego compilar este código.
Ci=zpk(C);
kp=Ci.k; %% Valor C en infinito.
ki=kp*(-Ci.z{:}+1); %% C=kp+ki/(z-1) %kpc(z-a)/(z-1)
C1=kp; % Lo mismo que C.z{:}
C2=ki-kp;
fprintf('Los parámetros optimizados que debes copiar al final del código en Simulation Parameters/Inicialization son: \n\n C1p=%4.10f; \n C2p=%4.10f; \n',C1,C2)