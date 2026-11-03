#include <iostream>
using namespace std;

int main() {
    int a[] = {4, 7, 7, 2, 9, 9, 1, 9, 4, 2};
    int n = sizeof(a) / sizeof(a[0]);

    int maxVal = a[0], minVal = a[0];
    int maxIndex = 0, minIndex = 0;
    int countMax = 0, countMin = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] > maxVal) { maxVal = a[i]; maxIndex = i; }
        if (a[i] < minVal) { minVal = a[i]; minIndex = i; }
    }

    for (int i = 0; i < n; i++) {
        if (a[i] == maxVal) countMax++;
        if (a[i] == minVal) countMin++;
    }

    cout << "Max = " << maxVal << ", первый индекс = " << maxIndex 
         << ", количество = " << countMax << endl;
    cout << "Min = " << minVal << ", первый индекс = " << minIndex 
         << ", количество = " << countMin << endl;
    return 0;
}