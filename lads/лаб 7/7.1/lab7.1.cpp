#include <iostream>
using namespace std;

void shiftArray(int a[], int n)
{
    if (n <= 0)
        return;

    // Проверяем, что первое число четное
    if (a[0] % 2 != 0)
    {
        cout << "Первый массив должен начинаться "
             << "с четного числа!" << endl;
        return;
    }

    int k = a[0] % n;

    // Циклический сдвиг влево
    for (int j = 0; j < k; j++)
    {
        int temp = a[0];

        for (int i = 0; i < n - 1; i++)
        {
            a[i] = a[i + 1];
        }

        a[n - 1] = temp;
    }

    cout << "Массив после сдвига влево: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << endl;
}


void shiftArray(double a[], int n)
{
    if (n <= 0)
        return;

    // Проверяем, что первое число нечетное
    if ((int)a[0] % 2 == 0)
    {
        cout << "Второй массив должен начинаться "
             << "с нечетного числа!" << endl;
        return;
    }

    int k = (int)a[n - 1] % n;

    for (int j = 0; j < k; j++)
    {
        double temp = a[n - 1];

        for (int i = n - 1; i > 0; i--)
        {
            a[i] = a[i - 1];
        }

        a[0] = temp;
    }

    cout << "Массив после сдвига вправо: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << endl;
}

int main()
{
     system("chcp 65001 > nul");

    int a[] = {2, 4, 6, 8, 10};
    double b[] = {3, 5, 7, 9, 2};

    int n = 5;

    cout << "Первый массив: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << endl;

    shiftArray(a, n);

    cout << endl;

    cout << "Второй массив: ";
    for (int i = 0; i < n; i++)
        cout << b[i] << " ";

    cout << endl;

    shiftArray(b, n);

    return 0;
}