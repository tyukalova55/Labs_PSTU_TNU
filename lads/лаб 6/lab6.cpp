#include <iostream>
#include <cstring>
#include <cstdio>
#include <clocale>

using namespace std;

int main()
{

    system("chcp 65001 > nul");

    char str[256];
    cout << "Введите строку для шифрования (в конце поставьте точку):\n";

    gets_s(str, 256);

    cout << "Зашифрованная строка: ";

    bool first = true;

    for (int i = 0; i < strlen(str); i++)
    {
        unsigned char c = str[i];
        int letter = 0;

        if (c >= 192 && c <= 223)
        {
            letter = c - 192 + 1;
        }
        else if (c >= 224 && c <= 255)
        {
            letter = c - 224 + 1;
        }

        else if (c == 168 || c == 184)
        {
            letter = 7;
        }

        if (letter > 0)
        {
            if (!first)
            {
                cout << "-";
            }
            cout << letter;
            first = false;
        }
    }

    cout << endl;
    return 0;
}