//LUIS POZAS PALOMO - EDA - 04
#ifndef _MONOMIO
#define _MONOMIO

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <cmath>
using namespace std;

class monomio {
private:
	int _coeficiente;
	int _exponente;
public:
	monomio(int c = 0, int e = 0) {
		_coeficiente = c; _exponente = e;
	}

	// observadoras
	int coeficiente() { return _coeficiente; }
	int exponente() { return _exponente; }

	// operador de comparacion
	bool operator<(monomio const& p) const {
		return _exponente < p._exponente;
	}

	int operator + (monomio const& p) {
		return p._coeficiente + _coeficiente;
	}

	int calculate(int n) {
		if (_exponente % 2 == 0) return _coeficiente * pow(abs(n), _exponente);
		else return _coeficiente * pow(n, _exponente);
	}

};

#endif
