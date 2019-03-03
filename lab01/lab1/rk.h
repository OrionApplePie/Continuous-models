#pragma once
#include <vector>

ref class rk
{
private:
	//нач. масса, кон. масса, 
	//m0 - нач. масса
	//m_fin  - кон. масса
	//alpha - расход топлива
	//sq - площадь поперечного сечени€ ракеты
	//c - коэфф. сопротивл.
	//f_traction -  т€га
	//dt - шаг по времени
	double  m_fin, alpha, sq, c;
	const double rho = 1.2041; // при температуре 20 град
	const double betta = 5.6e-5;
	const double  g = 9.8;
	
	//
	double vv = 7800.0; // перва€ космическа€
	double tt = (m0 - m_fin) / alpha;
	double ss = 17000.0;
	double k = m_fin / m0;
	double e = (vv*tt) / ss;
	double pp = (0.5*c*rho*sq*vv*tt) / m0;
	double b = tt*g / vv;
	double a = (f_traction*tt) / (m0*vv);

	//
public:
	double m0, f_traction;
	const double MAXmass = 3e7;
	const double MAXforce = 5e8;
	double* v; // массив дл€ скорости
	double* s; // массив дл€ высоты
	int n = 0; // размер массива
	double dt = 0;
	//
	rk();
	int cool(int i);
	void foo(int i, double* &a, int &n);
	//чтение и задание входных данных
	void setdata(double _m0, double _m_fin, double _alpha, double _sq, double _c, double _f_traction, double _dt);
	//метод рунге-кутта
	bool rungekutta(double eps, double * &v, double * &s, int &n );
	//метод эйлера
	bool euler(double eps, double h, double* &v, double* &s, int &n_);
	bool euler_dim_less(double, double,double*&, double*&, int &);

	//масса от времени
	double m(double t);
	double f(double tau);
	double fk(double, double, double);
	double fl(double);

};

