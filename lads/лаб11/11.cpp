
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Node
{
    string key;
    Node* next;
    Node* prev;
};

void createList(Node*& first, Node*& last, int n)
{
    first = NULL;
    last = NULL;

    for (int i = 0; i < n; i++)
    {
        Node* p = new Node;

        cout << "Введите строку: ";
        getline(cin, p->key);

        p->next = NULL;
        p->prev = last;

        if (first == NULL)
        {
            first = p;
        }
        else
        {
            last->next = p;
        }

        last = p;
    }
}

void printList(Node* first)
{
    if (first == NULL)
    {
        cout << "Список пустой!\n";
        return;
    }

    Node* p = first;

    while (p != NULL)
    {
        cout << p->key << endl;
        p = p->next;
    }
}

Node* findNode(Node* first, string key)
{
    Node* p = first;

    while (p != NULL)
    {
        if (p->key == key)
        {
            return p;
        }

        p = p->next;
    }

    return NULL;
}

void deleteNode(Node*& first, Node*& last, string key)
{
    Node* p = findNode(first, key);

    if (p == NULL)
    {
        cout << "Элемент не найден!\n";
        return;
    }

    if (p->prev != NULL)
    {
        p->prev->next = p->next;
    }
    else
    {
        first = p->next;
    }

    if (p->next != NULL)
    {
        p->next->prev = p->prev;
    }
    else
    {
        last = p->prev;
    }

    delete p;

    cout << "Элемент удален.\n";
}

void addAfter(Node*& first, Node*& last, string key, int k)
{
    Node* p = findNode(first, key);

    if (p == NULL)
    {
        cout << "Элемент не найден!\n";
        return;
    }

    for (int i = 0; i < k; i++)
    {
        Node* q = new Node;

        cout << "Введите новую строку: ";
        getline(cin, q->key);

        q->prev = p;
        q->next = p->next;

        if (p->next != NULL)
        {
            p->next->prev = q;
        }
        else
        {
            last = q;
        }

        p->next = q;

        p = q;
    }

    cout << "Элементы добавлены.\n";
}

void saveList(Node* first)
{
    ofstream f("list.txt");

    if (!f)
    {
        cout << "Ошибка открытия файла!\n";
        return;
    }

    Node* p = first;

    while (p != NULL)
    {
        f << p->key << endl;
        p = p->next;
    }

    f.close();

    cout << "Список записан в файл.\n";
}

void destroyList(Node*& first, Node*& last)
{
    Node* p = first;

    while (p != NULL)
    {
        Node* q = p;
        p = p->next;
        delete q;
    }

    first = NULL;
    last = NULL;
}

void loadList(Node*& first, Node*& last)
{
    ifstream f("list.txt");

    if (!f)
    {
        cout << "Ошибка открытия файла!\n";
        return;
    }

    destroyList(first, last);

    string line;

    while (getline(f, line))
    {
        Node* p = new Node;

        p->key = line;
        p->next = NULL;
        p->prev = last;

        if (first == NULL)
        {
            first = p;
        }
        else
        {
            last->next = p;
        }

        last = p;
    }

    f.close();

    cout << "Список восстановлен.\n";
}

int main()
{
    system("chcp 65001 > nul");

    Node* first = NULL;
    Node* last = NULL;

    int n;
    int k;
    string key;

    cout << "Введите количество элементов: ";
    cin >> n;
    cin.ignore();

    createList(first, last, n);

    cout << "\nИсходный список:\n";
    printList(first);

    cout << "\nВведите ключ для удаления: ";
    getline(cin, key);

    deleteNode(first, last, key);

    cout << "\nСписок после удаления:\n";
    printList(first);

    cout << "\nВведите ключ, после которого "
         << "добавить элементы: ";
    getline(cin, key);

    cout << "Введите количество элементов K: ";
    cin >> k;
    cin.ignore();

    addAfter(first, last, key, k);

    cout << "\nСписок после добавления:\n";
    printList(first);

    saveList(first);

    destroyList(first, last);

    cout << "\nПосле уничтожения списка:\n";
    printList(first);

    loadList(first, last);

    cout << "\nВосстановленный список:\n";
    printList(first);

    destroyList(first, last);

    return 0;
}
