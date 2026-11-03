#include <iostream>
using namespace std;

int main() {
    const int rows = 3, cols = 4;
    int matrix[rows][cols] = {
        {5, 8, 2, 1},
        {9, 3, 9, 7},
        {4, 6, 0, 9}
    };

    int maxVal = matrix[0][0];
    int maxRow = 0, maxCol = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] > maxVal) {
                maxVal = matrix[i][j];
                maxRow = i;
                maxCol = j;
            }
        }
    }

    cout << "Max = " << maxVal 
         << " в строке " << maxRow << ", столбце " << maxCol << endl;
    return 0;
}