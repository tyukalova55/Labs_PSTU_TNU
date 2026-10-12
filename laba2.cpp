#include <iostream>
#include <cmath>

using namespace std;
int main() {
	double sum = 0;
	double an;
	for (int n = 2; n <= 16; n++) {
		double ln_n = log((double)n);
		an = pow((double)n, ln_n) / pow(ln_n, (double)n);
		sum = sum + an;
		cout << "n = " << n << "   an = " << an << "   sum = " << sum << endl;
	}

