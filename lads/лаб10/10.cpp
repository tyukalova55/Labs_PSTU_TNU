
#include <iostream>
#include <string>
#include <limits>

using namespace std;

void createArray(string*& a, int& n)
{
    cout << "Введите количество строк: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Неправильный размер массива!\n";
        n = 0;
        a = nullptr;
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    a = new string[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Введите строку " << i + 1 << ": ";
        getline(cin, a[i]);
    }
}

void printArray(string* a, int n)
{
    if (n == 0)
    {
        cout << "Массив пустой.\n";
        return;
    }

    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ". " << a[i] << endl;
    }
}

void deleteDuplicates(string*& a, int& n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] == a[j])
            {
                for (int k = j; k < n - 1; k++)
                {
                    a[k] = a[k + 1];
                }

                n--;
                j--;
            }
        }
    }

    string* b = nullptr;

    if (n > 0)
    {
        b = new string[n];

        for (int i = 0; i < n; i++)
        {
            b[i] = a[i];
        }
    }

    delete[] a;
    a = b;
}

void deleteLast(string*& a, int& n, int k)
{
    if (k < 0)
    {
        k = 0;
    }

    if (k > n)
    {
        k = n;
    }

    n = n - k;

    string* b = nullptr;

    if (n > 0)
    {
        b = new string[n];

        for (int i = 0; i < n; i++)
        {
            b[i] = a[i];
        }
    }

    delete[] a;
    a = b;
}

void deleteArray(string*& a)
{
    delete[] a;
    a = nullptr;
}

int main()
{
    system("chcp 65001 > nul");

    string* a = nullptr;
    int n;
    int k;

    createArray(a, n);

    cout << "\nИсходный массив:\n";
    printArray(a, n);

    deleteDuplicates(a, n);

    cout << "\nМассив без одинаковых строк:\n";
    printArray(a, n);

    cout << "\nВведите K - количество последних строк "
         << "для удаления: ";
    cin >> k;

    deleteLast(a, n, k);

    cout << "\nМассив после удаления K последних строк:\n";
    printArray(a, n);

    deleteArray(a);

    return 0;
}
