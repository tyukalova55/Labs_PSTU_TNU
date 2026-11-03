#include <iostream>
using namespace std;

int main() {
    system("chcp 65001 > nul");
    int n;
    cout << "Введите высоту ромба: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) cout << " ";
        cout << "*";
        if (i > 0) {
            for (int j = 0; j < 2 * i - 1; j++) cout << " ";
            cout << "*";
        }
        cout << "\n";
    }
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < n - i - 1; j++) cout << " ";
        cout << "*";
        if (i > 0) {
            for (int j = 0; j < 2 * i - 1; j++) cout << " ";
            cout << "*";
        }
        cout << "\n";
    }

 cout << "  ";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) cout << " ";
        for (int j = 0; j < 2 * i + 1; j++) cout << "*";
        cout << "\n";
    }
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < n - i - 1; j++) cout << " ";
        for (int j = 0; j < 2 * i + 1; j++) cout << "*";
        cout << "\n";
    }

    return 0;
}