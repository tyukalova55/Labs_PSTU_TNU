#include <iostream>
using namespace std;

int main() {
    int a[] = {1, 2, 3, 5, 4, 6, 7};
    int n = sizeof(a) / sizeof(a[0]);
    bool sorted = true;  

    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            sorted = false;
            break;  
        }
    }

    if (sorted)
        cout << "Массив упорядочен по возрастанию" << endl;
    else
        cout << "Массив НЕ упорядочен по возрастанию" << endl;
    return 0;
}