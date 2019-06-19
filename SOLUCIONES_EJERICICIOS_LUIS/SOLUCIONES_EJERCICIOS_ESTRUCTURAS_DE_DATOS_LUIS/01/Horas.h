//LUIS POZAS PALOMO - EDA - 01
#ifndef _HORAS
#define _HORAS

#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;

class horas {
private:
	int _hora;
	int _minuto;
	int _segundo;
	bool check(int h, int m, int s) {
		return 0 <= h && h < 24 && 0 <= m && m < 60 && 0 <= s && s < 60;
	}
public:
	horas(int h = 0, int m = 0, int s = 0) {
		if (check(h, m, s)) {
			_hora = h; _minuto = m; _segundo = s;
		}
		else throw invalid_argument("esto no es una hora");
	}
	// observadoras
	int hora() const { return _hora; }
	int minuto() const { return _minuto; }
	int segundo() const { return _segundo; }

	// operador de comparacion
	bool operator<(horas const& h) const {
		return 3600 * _hora + 60 * _minuto + _segundo <
			3600 * h._hora + 60 * h._minuto + h._segundo;
	}

	void read(istream & i = cin) {
		int h, m, s; char c;
		i >> h >> c >> m >> c >> s;
		*this = horas(h, m, s);
	}
	void print(ostream& o = cout) const {
		o << setfill('0') << setw(2) << _hora << ':'
			<< setfill('0') << setw(2) << _minuto << ':'
			<< setfill('0') << setw(2) << _segundo;
	}
};

inline ostream & operator<<(ostream & salida, horas const& h) {
	h.print(salida);
	return salida;
}

inline istream & operator>>(istream & entrada, horas & h) {
	h.read(entrada);
	return entrada;
}

#endif
