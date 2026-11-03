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
    }
    for (int i = 0; i < N; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
        cout << "После вставки " << key << " :";

        for (int k = 0; k < N; k++)
        {
            cout << a[k] << "";
        }
        cout << '\n';
    }
    cout << "Отсортированный массив ";
    for (int i = 0; i < N; i++)
    {
        cout << a[i] << "";
    }
    cout << '\n';
    return 0;
}
