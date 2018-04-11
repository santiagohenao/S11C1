/**
*
*   Modelo SIR solucionado con el método de Euler
*
*   ./a.out t_0 t_f step N I_0 beta sigma (R_0=0)
*
*   t_0     double      Tiempo inicial
*   t_f     double      Tiempo final
*   step    double      Resolución temporal
*   N       int         Número total de personas. "Constante" en este modelo
*   I_0     int         Personas infectadas en t=0
*   beta    double      Tasa de propagación
*   sigma   double      Tasa de remoción (personas que se vuelven inmunes)
*   (R_0)   int         Personas infectadas en t=0. Valor por defecto como 0.
*
**/

#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;


// vectores para guardar los datos

vector<double> S,I,R,t;

int t_i=0;

// constantes del modelo

double beta=0;
double sigma=0;

/*
* Pasos individuales del método de Euler
*/
double Euler_step( vector<double>X ,double (*func)(int) , int time_index , double dt)
{
    return X[time_index]+dt*func(time_index);
}

/*
* Función de la ecuación de S
*/
double dR(int time_index)
{
    return sigma*I[time_index];
}

/*
* Función de la ecuación de S
*/
double dS(int time_index)
{
    return -beta*I[time_index]*S[time_index];
}

/*
* Función de la ecuación de S
*/
double dI(int time_index)
{
    return -dS(time_index)-dR(time_index);
}



int main(int argc, char *argv[])
{
    // Leer condiciones inciales dadas por parámetro

    double t_0=atof(argv[1]);
    double t_f=atof(argv[2]);
    double step=atof(argv[3]);
    int N = atoi(argv[4]);
    I.push_back(atof(argv[5]));
    beta+=atof(argv[6]);
    sigma +=atof(argv[7]);
    if(argc==9)
    {
        R.push_back(atof(argv[8]));
    }
    else
    {
        R.push_back(0.0);
    }

    // Calcular S inicial

    S.push_back(N-I[0]-R[0]);

    t.push_back(t_0);

    while(t[t.size()-1]<=t_f)
    {
        R.push_back(Euler_step(R,dR,t_i,step));
        S.push_back(Euler_step(S,dS,t_i,step));
        I.push_back(Euler_step(I,dI,t_i,step));
        t_i++;
        t.push_back(t[t.size()-1]+step);
    }

    ofstream result("MIR.dat");
    for(int i=0; i < S.size(); i++)
    {
        result << t[i] << "\t" << S[i] << "\t" << R[i]<< "\t" << I[i] << endl;
    }
    result.close();
}
