#include <iostream>
#include <cmath>

using namespace std;
int main() {
int m,n,result;

cout << "Enter m" << endl;
cin >> m;

cout << "Enter n" << endl;
cin >> n;
	result = ++n*++m ;
    result =	m++<n;
result = 	n++>m;
cout << "Result is  " << result << endl;

return 0;
}