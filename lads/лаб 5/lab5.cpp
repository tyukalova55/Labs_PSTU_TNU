
#include <iostream>
#include <clocale>
using namespace std;

const int MAX = 100;

// Функция для создания матрицы
void form(int n, int b[], int a[][MAX])
{

    for (int j = 0; j < n; j++)
    {
        // Заполняем столбец единицами
        for (int i = 0; i < n - 1; i++)
        {
            a[i][j] = 1;
        }

        // Последний элемент столбца
        a[n - 1][j] = b[j] - (n - 1);

        // Если получился ноль, меняем два элемента
        if (a[n - 1][j] == 0)
        {
            a[0][j] = 2;
            a[n - 1][j] = -1;
        }
    }
}

int main()
{
        system("chcp 65001 > nul");

    int n;
    int b[MAX];
    int a[MAX][MAX];

    cout << "Введите количество элементов: ";
    cin >> n;

    if (n < 1 || n > MAX)
    {
        cout << "Ошибка! Неправильное количество элементов.";
        return 1;
    }

    cout << "Введите элементы массива:" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];

        if (b[i] == 0)
        {
            cout << "Элемент не должен быть равен нулю!";
            return 1;
        }
    }

    form(n, b, a);

    cout << "Полученная матрица:" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << "\t";
        }

        cout << endl;
    }

    return 0;
}
