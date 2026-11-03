#include <iostream>

using namespace std;

int main()
{
    system("chcp 65001 > nul");

    int h1, m1, h2, m2;
    cout << "введите t1 = ";
    cin >> h1 >> m1;

    cout << "введите t2 = ";
    cin >> h2 >> m2;

    int t1_min = h1 * 60 + m1;
    int t2_min = h2 * 60 + m2;

    int dt = t2_min - t1_min;
    if (dt < 0)
    {
        dt += 1440;
    }
    int dh = dt / 60;
    int dm = dt % 60;

    cout << "промежуток :  " << dh << "ч" << dm << "мин" << endl;
    return 0;
}