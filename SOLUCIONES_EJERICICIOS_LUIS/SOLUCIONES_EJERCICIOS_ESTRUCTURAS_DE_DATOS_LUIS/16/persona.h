//LUIS POZAS PALOMO - EDA - 16
#ifndef _PERSONA
#define _PERSONA

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>
using namespace std;

class persona {
private:
	int _edad;
	string _nombre;
	
public:
	persona(int edad = 0, string nombre = "") {
		_edad = edad;
		_nombre = nombre;
	}
	// observadoras
	int edad() const { return _edad; }
	string nombre() const { return _nombre; }

	void read(istream & i = cin) {
		int e; string n;
		i >> e;
		i.ignore();
		getline(i, n);
		*this = persona(e, n);
	}

	void print(ostream& o = cout) const {
		o << _nombre;
	}
};


inline ostream & operator<<(ostream & salida, persona const& p) {
	p.print(salida);
	return salida;
}

inline istream & operator>>(istream & entrada, persona & p) {
	p.read(entrada);
	return entrada;
}


template <class Predicate>
class predicado {

private:
  int _min;
  int _max;

public:

  predicado(int min = 0, int max = 0){
    _min = min;
    _max = max;
  }

  bool operator()(const int elem){
    return !(elem >= _min && elem <= _max);
  }  
};

#endif
