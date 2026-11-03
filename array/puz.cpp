#include <iostream>
using namespace std;

int main()
{

    system("chcp 65001 > nul");

    const int N = 7;
    int a[N] = {5, 2, 7, 1, 4, 3, 6};

    cout << "Исходный массив: ";

    for (int i = 0; i < N; i++)
    {
        cout << a[i] << " ";
        cout << '\n';

        for (int i = 0; i < N - 1; i++)
        {
            for (int j = 0; i < N - 1 - i; i++)
            {
                if (a[j] > a[j + 1])
                {
                    int temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
            cout << "После прохода " << i + 1 << " :";
            for (int j = 0; j < N; j++)
            {
                cout << a[j] << "";
                cout << '\n';
            }
            cout << "Отсортированный массив: ";
            for (int i = 0; i < N; i++)
            {
                cout << a[i] << " ";
                cout << '\n';

                return 0;
            }
        }
    }
}