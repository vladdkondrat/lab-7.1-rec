#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

void createMatrix(int** matrix, int rows, int cols, int low, int high) {
    srand(time(0));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = low + rand() % (high - low + 1);
        }
    }
}

void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
}

int countAndSumElements(int** matrix, int rows, int cols, int& sum) {
    int count = 0;
    sum = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if ((matrix[i][j] % 2 == 0) && !((i % 2 != 0) || (j % 2 != 0))) {
                ++count;
                sum += matrix[i][j];
                matrix[i][j] = 0;
            }
        }
    }
    return count;
}

void sortColumns(int** matrix, int rows, int cols) {
    for (int i = 0; i < cols - 1; ++i) {
        for (int j = i + 1; j < cols; ++j) {
            if (matrix[0][i] < matrix[0][j] ||
                (matrix[0][i] == matrix[0][j] && matrix[1][i] > matrix[1][j]) ||
                (matrix[0][i] == matrix[0][j] && matrix[1][i] == matrix[1][j] && matrix[2][i] < matrix[2][j])) {
                for (int k = 0; k < rows; ++k) {
                    swap(matrix[k][i], matrix[k][j]);
                }
            }
        }
    }
}

int main() {
    int rows = 9, cols = 7;
    int low = 4, high = 45;

    int** matrix = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }

    createMatrix(matrix, rows, cols, low, high);

    cout << "Original matrix:" << endl;
    printMatrix(matrix, rows, cols);

    int sum = 0;
    int count = countAndSumElements(matrix, rows, cols, sum);

    cout << "Number of elements satisfying the criterion: " << count << endl;
    cout << "Sum of elements satisfying the criterion: " << sum << endl;

    cout << "Modified matrix:" << endl;
    printMatrix(matrix, rows, cols);

    sortColumns(matrix, rows, cols);

    cout << "Sorted matrix:" << endl;
    printMatrix(matrix, rows, cols);

    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}

