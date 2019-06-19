//LUIS POZAS PALOMO - EDA - 02
#ifndef _PELICULAS
#define _PELICULAS

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <locale>
using namespace std;

#include "Horas.h"

class peliculas {
private:
	horas _hora;
	string _titulo;

	string toLowerMy(string const str){
		string str2 = str;
		for(int i = 0; i < str2.length(); i++) str2[i] = tolower(str2[i]);
		return str2;
	}

public:
	peliculas(horas h = horas(), string s = "") {
			_hora = h; _titulo = s;
	}

	// observadoras
	string titulo(){return _titulo;} //como devolverias la hora ??
	horas hora(){return _hora;} //asi??

	// operador de comparacion
	bool operator < (peliculas const& p) {
		int h_izq, h_dcha;
		h_izq = 3600 * _hora.hora() + 60 * _hora.minuto() + _hora.segundo();
		h_dcha = 3600 * p._hora.hora() + 60 * p._hora.minuto() + p._hora.segundo();
		if(h_izq < h_dcha) return true;
		else if(h_dcha == h_izq){
			if(toLowerMy(p._titulo) > toLowerMy(_titulo)) return true;
			else return false;
		}
		else return false;
	}
};

#endif
