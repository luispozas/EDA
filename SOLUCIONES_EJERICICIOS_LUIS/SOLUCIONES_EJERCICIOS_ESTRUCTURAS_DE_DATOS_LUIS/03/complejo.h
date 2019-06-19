//LUIS POZAS PALOMO - EDA - 03
#ifndef _COMPLEJO
#define _COMPLEJO

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class complejo {
private:
	float _real;
	float _imaginaria;
public:
	complejo(float r = 0, float i = 0) {
		_real = r; _imaginaria = i;
	}

	// observadoras
	float real() { return _real; }
	float imaginaria() { return _imaginaria; }

	complejo operator + (complejo const& p) {
    float r, i;
    r = p._real + _real;
    i = p._imaginaria + _imaginaria;
		return complejo(r,i);
	}

  complejo operator * (complejo const& p) {
    float r, i;
    r = p._real * _real - p._imaginaria * _imaginaria;
    i = _real * p._imaginaria + p._real * _imaginaria;
    return complejo(r,i);
  }

	float module() {
		return sqrt(_real*_real + _imaginaria*_imaginaria);
	}
};

#endif
