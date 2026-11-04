#include <iostream>
using namespace std;

int main()
{
    system("chcp 65001 > nul");

    const int N = 7;
    int a[N] = {5, 2, 7, 1, 4, 3, 6};

    cout << "Исходный массив: ";
    for (int i = 0; i < N; i++)
        cout << a[i] << " ";
    cout << '\n';

    for (int gap = N / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < N; i++)
        {
            int temp = a[i];
            int j = i;

            while (j >= gap && a[j - gap] > temp)
            {
                a[j] = a[j - gap];
                j -= gap;
            }
            a[j] = temp;
        }

        cout << "После прохода (gap = " << gap << "): ";
        for (int k = 0; k < N; k++)
            cout << a[k] << " ";
        cout << '\n';
    }

    cout << "Отсортированный массив: ";
    for (int i = 0; i < N; i++)
        cout << a[i] << " ";
    cout << '\n';

    return 0;
}