#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double a = 0.1;
    double b = 1.0;
    int k = 10;
    int n = 15;
    double eps = 0.0001;

    double h = (b - a) / k;

    cout << "|    X    |    SN    |   SE   |    Y    |" << endl;

    for (double x = a; x <= b + 0.0000001; x += h) {

        double SN = 0.0;
        double an = -2.0 * x * x;
        SN = SN + an;

        for (int i = 1; i < n; i++) {
            an = an * (-4.0 * x * x) / ((2.0*i + 1.0) * (2.0*i + 2.0));
            SN= SN + an;
        }

        double SE = 0.0;
        an = -2.0 * x * x;
        SE = SE + an;

        int i = 1;
        while (fabs(an) >= eps) {
            an = an * (-4.0 * x * x) / ((2.0*i + 1.0) * (2.0*i + 2.0));
            SE= SE + an;
            i++;
        }


        double Y = 2.0 * (pow(cos(x), 2.0) - 1.0);

        cout << "| " << setw(7) << fixed << setprecision(2) << x
             << " | " << setw(6) << setprecision(6) << SN
             << " | " << setw(5) << SE
             << " | " << setw(7) << Y << endl;
    }

    return 0;
}