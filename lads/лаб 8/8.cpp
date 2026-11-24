
#include <iostream>
#include <cstdio>
#include <cstring>
#include <limits>

using namespace std;

struct Stadium
{
    char name[50];
    int year;
    int count;
    char sports[100];
};

void inputStadium(Stadium &s)
{
    cout << "Название стадиона: ";
    cin.getline(s.name, 50);

    cout << "Год постройки: ";
    cin >> s.year;

    cout << "Количество площадок: ";
    cin >> s.count;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Виды спорта: ";
    cin.getline(s.sports, 100);
}


void createFile()
{
    FILE *f;
    Stadium s;
    int n;

    cout << "Введите количество стадионов (не менее 5): ";
    cin >> n;

    if (n < 5)
    {
        cout << "Количество должно быть не меньше 5!\n";
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    f = fopen("stadium.dat", "wb");

    if (f == NULL)
    {
        cout << "Ошибка открытия файла!\n";
        return;
    }

    for (int i = 0; i < n; i++)
    {
        cout << "\nСтадион №" << i + 1 << endl;

        inputStadium(s);

        if (fwrite(&s, sizeof(Stadium), 1, f) != 1)
        {
            cout << "Ошибка записи!\n";
            fclose(f);
            return;
        }
    }

    fclose(f);

    cout << "\nФайл успешно создан!\n";
}

// Печать содержимого файла
void printFile()
{
    FILE *f;
    Stadium s;
    int i = 1;

    f = fopen("stadium.dat", "rb");

    if (f == NULL)
    {
        cout << "Ошибка открытия файла!\n";
        return;
    }

    cout << "\nСписок стадионов:\n";

    while (fread(&s, sizeof(Stadium), 1, f) == 1)
    {
        cout << "\nСтадион №" << i << endl;
        cout << "Название: " << s.name << endl;
        cout << "Год постройки: " << s.year << endl;
        cout << "Количество площадок: " << s.count << endl;
        cout << "Виды спорта: " << s.sports << endl;

        i++;
    }

    fclose(f);
}

bool findForDelete(Stadium s, int year)
{
    if (s.year < year)
        return true;

    return false;
}

void deleteStadiums()
{
    FILE *f;
    FILE *temp;
    Stadium s;
    int year;
    int deleted = 0;

    cout << "Введите год постройки: ";
    cin >> year;

    f = fopen("stadium.dat", "rb");

    if (f == NULL)
    {
        cout << "Ошибка открытия исходного файла!\n";
        return;
    }

    temp = fopen("temp.dat", "wb");

    if (temp == NULL)
    {
        cout << "Ошибка открытия временного файла!\n";
        fclose(f);
        return;
    }

    while (fread(&s, sizeof(Stadium), 1, f) == 1)
    {
        if (findForDelete(s, year))
        {
            deleted++;
        }
        else
        {
            fwrite(&s, sizeof(Stadium), 1, temp);
        }
    }

    fclose(f);
    fclose(temp);

    remove("stadium.dat");
    rename("temp.dat", "stadium.dat");

    cout << "Удалено стадионов: " << deleted << endl;
}

void addStadiums()
{
    FILE *f;
    FILE *temp;
    Stadium s;
    Stadium newS;
    int number;
    int i = 1;
    bool added = false;

    f = fopen("stadium.dat", "rb");

    if (f == NULL)
    {
        cout << "Ошибка открытия файла!\n";
        return;
    }

    cout << "Перед каким номером добавить стадионы? ";
    cin >> number;

    if (number < 1)
    {
        cout << "Неправильный номер!\n";
        fclose(f);
        return;
    }

    temp = fopen("temp.dat", "wb");

    if (temp == NULL)
    {
        cout << "Ошибка открытия временного файла!\n";
        fclose(f);
        return;
    }

    while (fread(&s, sizeof(Stadium), 1, f) == 1)
    {
        if (i == number && !added)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "\nВведите первый новый стадион:\n";
            inputStadium(newS);
            fwrite(&newS, sizeof(Stadium), 1, temp);

            cout << "\nВведите второй новый стадион:\n";
            inputStadium(newS);
            fwrite(&newS, sizeof(Stadium), 1, temp);

            added = true;
        }

        fwrite(&s, sizeof(Stadium), 1, temp);
        i++;
    }

    if (!added)
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "\nВведите первый новый стадион:\n";
        inputStadium(newS);
        fwrite(&newS, sizeof(Stadium), 1, temp);

        cout << "\nВведите второй новый стадион:\n";
        inputStadium(newS);
        fwrite(&newS, sizeof(Stadium), 1, temp);
    }

    fclose(f);
    fclose(temp);

    remove("stadium.dat");
    rename("temp.dat", "stadium.dat");

    cout << "\nСтадионы добавлены!\n";
}

int main()
{
    system("chcp 65001 > nul");
    int choice;

    do
    {
        cout << "\n===== МЕНЮ =====\n";
        cout << "1. Создать файл\n";
        cout << "2. Вывести файл\n";
        cout << "3. Удалить стадионы\n";
        cout << "4. Добавить 2 стадиона\n";
        cout << "Ваш выбор: ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            createFile();
            break;

        case 2:
            printFile();
            break;

        case 3:
            deleteStadiums();
            break;

        case 4:
            addStadiums();
            break;


        default:
            cout << "Неправильный выбор!\n";
        }

    } while (choice != 0);

    return 0;
}