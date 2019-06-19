//LUIS POZAS PALOMO - EDA - 04
#ifndef _POLINOMIO
#define _POLINOMIO

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <vector>
using namespace std;

#include "monomio.h"

class polinomio {
private:
	vector <monomio> pol;

public:
	void add(monomio & m) {
		int k = 0;
		bool enc = false;
		try {
			if (m.coeficiente() == 0) throw invalid_argument("Error: no puede haber coeficientes con valor 0.");
			while (k < pol.size() && !enc) {
				if (pol[k].exponente() >= m.exponente()) enc = true;
				else k++;
			}
			if (k == pol.size()) pol.push_back(monomio(m.coeficiente(), m.exponente()));
			else if (pol[k].exponente() == m.exponente()) pol[k] = monomio(m + pol[k], m.exponente());
			else {
				pol.push_back(pol[pol.size()-1]);
				for (int i = pol.size()-1; i > k; i--) pol[i] = pol[i - 1];
				pol[k] = m;
			}
		}
		catch (invalid_argument ex) {

		}
	}

	int calculatePol(int val) {
		int sum = 0;
		for (int i = 0; i < pol.size(); i++) sum += pol[i].calculate(val);
		return sum;
	}
};


#endif
