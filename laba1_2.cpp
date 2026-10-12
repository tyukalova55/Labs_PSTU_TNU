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
    cout << "Result is  ++n*++m =" << result << endl;
    result =	m++<n;
    cout << "Result is m++<n = " << result << endl;
result = n++>m;
cout << "Result is  n++>m =2" << result << endl;

return 0;
}