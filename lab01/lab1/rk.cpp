#include "rk.h"
#include <cmath>


rk::rk()
{
}int rk::cool(int i)
{
	return i + 100;
}

void rk::foo(int i, double* &a, int &n)
{
	double *cool = new double[10];
	int n_ = 10;
	for (int i = 0; i < 10; i++)
	{
		cool[i] = (double)i / n_;
	}
    n = n_;
	a = cool;
	//throw gcnew System::NotImplementedException();
}

void rk::setdata(double _m0, double _m_fin, double _alpha, double _sq, double _c, double _f_traction, double _dt)
{
	m0 = _m0;
	m_fin = _m_fin;
	alpha = _alpha;
	sq = _sq;
	c = _c;
	f_traction = _f_traction;
	dt = _dt;
	//throw gcnew System::NotImplementedException();
}

bool rk::rungekutta(double eps, double *&v, double *&s, int &n_)
{
	//безразмерные величины
	//
	double vv = 7800.0; // первая космическая
	double tt = (m0 - m_fin) / alpha;
	double ss = 17000.0;
	double k = m_fin / m0;
	double e = (vv*tt) / ss;
	double pp = (0.5*c*rho*sq*vv*tt) / m0;
	double b = tt*g / vv;
	double a = (f_traction*tt) / (m0*vv);
	int nn = (int)(tt / dt);
	v = new double[nn + 5];
	s = new double[nn + 5];
	double *v_ = new double[nn + 5];
	double *s_ = new double[nn + 5];
	v[0] = 0;
	s[0] = 0;
	v_[0] = 0;
	s_[0] = 0;
	double tau = 0;
	double ah =  0;
	int count = 0;
	//double ma = m0;
	double phi[4]; double phi_[4];
	int i = 0;
	do
	{
		//do {
			phi[0] = (dt / tt)*fk(tau, s[i], v[i]);
			phi[1] = (dt / tt)*fk(tau + (dt / tt) / 2, s[i], v[i] + phi[0] / 2);
			phi[2] = (dt / tt)*fk(tau + (dt / tt) / 2, s[i], v[i] + phi[1] / 2);
			phi[3] = (dt / tt)*fk(tau + dt / tt, s[i], v[i] + phi[2]);

			v[i + 1] = v[i] + (1.0 / 6.0)*(phi[0] + 2 * phi[1] + 2 * phi[2] + phi[3]);
			s[i + 1] = s[i] + e*v[i] * dt / tt;
			//
			
		/*	phi_[0] = ((dt / tt)/2)*fk(tau, s_[i], v_[i]);
			phi_[1] = ((dt / tt)/2)*fk(tau + ((dt / tt)/2) / 2, s_[i], v_[i] + phi_[0] / 2);
			phi_[2] = ((dt / tt)/2)*fk(tau + ((dt / tt)/2) / 2, s_[i], v_[i] + phi_[1] / 2);
			phi_[3] = ((dt / tt)/2)*fk(tau + (dt / tt)/2, s_[i], v_[i] + phi_[2]);

			v_[i + 1] = v_[i] + (1.0 / 6.0)*(phi_[0] + 2 * phi_[1] + 2 * phi_[2] + phi_[3]);
			s_[i + 1] = s_[i] + e*v_[i] * (dt / tt)/2;*/
			//
		//dt = dt / 2.0;
			count++;

		//} while (abs((v[i + 1] - v_[i + 1]) / 15.0) >= eps);
		i++;
		tau += (dt / tt);
	} while (tau <= 1.);
	n_ = nn;
	dt = dt / tt;
	return true;
}

bool rk::euler(double eps, double h, double* &v, double* &s, int & n_)
{
	double tf = (m0 - m_fin) / alpha; //расчет времени работы двигателя из массы топлива и расхода
	double p = 0;
	double time = 0;
	int n = (int)(tf / dt);
	v = new double[n+3];
	s = new double[n+3];
	v[0] = 0;
	s[0] = 0;
	double ma = m0;
	int i = 0;
	while (ma > m_fin)
	{

		p = (f_traction - m(time)*g - 0.5*c*rho*pow(10, -betta*s[i])*sq*v[i]*v[i])/m(time);
		v[i + 1] = v[i] + p*dt;
		s[i + 1] = s[i] + v[i] * dt;
		i++;
		ma = m(time);
		time += dt;

	}
	n_ = n;
	return true;
}
// в безразмерных величинах

bool rk::euler_dim_less(double m0, double f_traction, double* &v_, double* &s_, int & n_)
{
	//безразмерные величины
	double vv = 7800.0; // первая космическая
	double tt = (m0 - m_fin) / alpha;
	double ss = 17000.0;
	double k = m_fin / m0;
	double e = (vv*tt) / ss;
	double pp = (0.5*c*rho*sq*vv*tt) / m0;
	double b = tt*g / vv;
	double a = (f_traction*tt) / (m0*vv);
	//double tf = (m0 - m_fin) / alpha; //расчет времени работы двигателя из массы топлива и расхода
	//
	double bar = 0;
	double tau = 0;
	int n = (int)(tt / dt)+1;

		double* v = new double[n];
		double* s = new double[n];
	
	v[0] = 0;
	s[0] = 0;
	//double ma = m0;
	int i = 0;
	while (tau<=1.)
	{

		bar = (1.0 / f(tau))*(a - b*f(tau) - pp*pow(10, -betta*ss*s[i])*v[i] * v[i]);
		v[i + 1] = v[i] + bar*dt/tt;
		s[i + 1] = s[i] + e*v[i] * dt/tt;
		i++;
		tau += (dt/tt);
	}
	n_ = n;
	v_ = v;
	s_ = s;
	
	dt = dt / tt;
	//delete[] v;
	//delete[] s;
	v = NULL;
	s = NULL;

	return true;
	
}

double rk::m(double t)
{
	return m0  - alpha*t;
}

double rk::f(double tau)
{
	//double res = 0;
	if (tau <= 1.0) {
		return (1. - (1. - m_fin / m0)*tau);
	}
	else return m_fin/m0;
}

double rk::fk(double x, double s, double v)
{
	double vv = 7800.0; // первая космическая
	double tt = (m0 - m_fin) / alpha;
	double ss = 17000.0;
	double k = m_fin / m0;
	double e = (vv*tt) / ss;
	double pp = (0.5*c*rho*sq*vv*tt) / m0;
	double b = tt*g / vv;
	double a = (f_traction*tt) / (m0*vv);

	double res = (1.0 / f(x))*(a - b*f(x) - pp*pow(10, -betta*ss*s)*v*v);
	
	return res;
}

double rk::fl(double v)
{
	double e = (vv*tt) / ss;
	return e*v;
}


