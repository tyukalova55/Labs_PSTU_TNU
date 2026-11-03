#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "введите кол-во элементов";
    cin >> n;

    int x;
    int min = 0;
    int max = 0;
    bool first = true;

    for (int i = 0; i < n; i++)
    {
        cin >> x;

        if (first)
        {
            min = x;
            max = x;
            first = false;
        }
        else
        {
            if (x < min)
            {
                min = x;
            }
            if (x > max)
            {
                max = x;
            }
        }
    }
    cout << "min " << min << endl;
    cout << "max " << max << endl;

    return 0;
}