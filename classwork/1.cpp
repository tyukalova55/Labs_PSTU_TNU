#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    int a, b, x, y;

    cout << "enter a,b,x = ";
    cin >> a >> b >> x;

    if (x < 0)
    {
        y = a * pow(x, 2) + b;
    }
    else if (x <= 10)
    {
        y = (a + b) * x;
    }
    else if (x > 10)
    {
        y = pow(a, 2) + pow(b, 2) + 1;
    }
    cout << "result y  = " << y << endl;
    return 0;
}