#include <iostream>
#include <cmath>

using namespace std;
int main() {
	double a = 100;
	double b = 0.001;



	double top = pow(a - b, 4) - (pow(a, 4) - 4 * pow(a, 3) * b);
	double bottom = 6 * pow(a, 2) * pow(b, 2) - 4 * a * pow(b, 3) + pow(b, 4);
   double result = top / bottom;

	cout << "Result:  " << result << endl;


	return 0;
}

int main1(){
int m,n,result;

cout << "Enter m" << endl;
cin >> m;

cout << "Enter n" << endl;
cin >> n;
	result = ++n*++m ;
cout << "Result is" << result << endl;

return 0;
}