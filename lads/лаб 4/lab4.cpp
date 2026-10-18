
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <clocale>

using namespace std;

int main()
{
    system("chcp 65001 > nul");
    srand(time(0));

    const int N = 100;
    int a[N];
    int n, k;

    cout << "Введите количество элементов массива: ";
    cin >> n;

    if (n < 1 || n > N)
    {
        cout << "Неправильный размер массива!" << endl;
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 100;
    }

    cout << "Исходный массив: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    cout << "Введите номер K от 1 до " << n << ": ";
    cin >> k;

    if (k < 1 || k > n)
    {
        cout << "Неправильный номер K!" << endl;
        return 0;
    }

    k--;

    cout << "Обход кольца влево: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[(k - i + n) % n] << " ";
    }
    cout << endl;

    int maxEl = a[0];

    for (int i = 1; i < n; i++)
    {
        if (a[i] > maxEl)
        {
            maxEl = a[i];
        }
    }

    cout << "Максимальный элемент: " << maxEl << endl;

    int i = 0;

    while (i < n)
    {
        if (a[i] == maxEl)
        {
            for (int j = i; j < n - 1; j++)
            {
                a[j] = a[j + 1];
            }
            n--;
        }
        else
        {
            i++;
        }
    }

    cout << "Массив после удаления максимальных элементов: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    if (n > 0)
    {
        k = k % n;

        cout << "Обход кольца вправо: ";
        for (int i = 0; i < n; i++)
        {
            cout << a[(k + i) % n] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Массив пуст." << endl;
    }

    return 0;
}
