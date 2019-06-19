/* LUIS POZAS PALOMO - EDA - (A01).

	P{n}
		fun solve (n : entero) dev ( x : entero)
	Q{x = n + n}


*/

#include <iostream>
using namespace std;

int solve(int num) {
	return num + num;
}

int main(){
	int num;
	for ( ;cin >> num; ) {
		cout << solve(num) << endl;
	}
	return 0;
}
