
#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

void createFile()
{
    FILE* file = fopen("F1.txt", "w");

    if (file == NULL)
    {
        cout << "Ошибка создания файла F1!\n";
        return;
    }

    fputs("Математика\n", file);
    fputs("Я изучаю программирование на C++\n", file);
    fputs("Информатика\n", file);
    fputs("Студент первого курса\n", file);
    fputs("Алгоритм\n", file);
    fputs("Университет\n", file);
    fputs("Компьютер\n", file);
    fputs("Программа\n", file);
    fputs("Массив\n", file);
    fputs("Функция\n", file);
    fputs("Файл\n", file);
    fputs("Строка\n", file);

    fclose(file);

    cout << "Файл F1.txt создан.\n";
}

void printFile(const char name[])
{
    FILE* file = fopen(name, "r");

    if (file == NULL)
    {
        cout << "Не удалось открыть файл!\n";
        return;
    }

    char line[1000];

    while (fgets(line, 1000, file) != NULL)
    {
        cout << line;
    }

    fclose(file);
}

int countConsonants(string word)
{
    string consonants[] = {
        "б", "в", "г", "д", "ж", "з", "й", "к", "л",
        "м", "н", "п", "р", "с", "т", "ф", "х", "ц",
        "ч", "ш", "щ",
        "Б", "В", "Г", "Д", "Ж", "З", "Й", "К", "Л",
        "М", "Н", "П", "Р", "С", "Т", "Ф", "Х", "Ц",
        "Ч", "Ш", "Щ"
    };

    int count = 0;

    for (int i = 0; i < word.length();)
    {
        if ((unsigned char)word[i] >= 192)
        {
            string letter = word.substr(i, 2);

            for (int j = 0; j < 42; j++)
            {
                if (letter == consonants[j])
                {
                    count++;
                    break;
                }
            }

            i += 2;
        }
        else
        {
            char letter = tolower((unsigned char)word[i]);

            if (letter >= 'b' && letter <= 'z' &&
                letter != 'e' && letter != 'i' &&
                letter != 'o' && letter != 'u')
            {
                count++;
            }

            i++;
        }
    }

    return count;
}

void task()
{
    FILE* in = fopen("F1.txt", "r");
    FILE* out = fopen("F2.txt", "w");

    if (in == NULL || out == NULL)
    {
        cout << "Ошибка открытия файлов!\n";

        if (in != NULL)
            fclose(in);

        if (out != NULL)
            fclose(out);

        return;
    }

    char line[1000];

    while (fgets(line, 1000, in) != NULL)
    {
        string text = line;
        stringstream ss(text);

        string word;
        int words = 0;

        while (ss >> word)
        {
            words++;
        }

        if (words == 1)
        {
            fputs(line, out);
        }
    }

    fclose(in);
    fclose(out);

    cout << "\nФайл F2.txt сформирован.\n";

    in = fopen("F2.txt", "r");

    if (in == NULL)
    {
        cout << "Ошибка открытия F2.txt!\n";
        return;
    }

    int number = 0;
    int maxConsonants = -1;
    int resultNumber = 0;

    while (fgets(line, 1000, in) != NULL)
    {
        string text = line;
        stringstream ss(text);

        string word;

        while (ss >> word)
        {
            number++;

            int consonants = countConsonants(word);

            if (consonants > maxConsonants)
            {
                maxConsonants = consonants;
                resultNumber = number;
            }
        }
    }

    fclose(in);

    cout << "\nНомер слова с наибольшим количеством "
         << "согласных: " << resultNumber << endl;

    cout << "Количество согласных: "
         << maxConsonants << endl;
}

int main()
{
    system("chcp 65001 > nul");

    createFile();

    cout << "\nСодержимое файла F1.txt:\n";
    printFile("F1.txt");

    task();

    cout << "\nСодержимое файла F2.txt:\n";
    printFile("F2.txt");

    return 0;
}
