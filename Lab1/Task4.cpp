#include <iostream>

int** allocateMatrix(int rows, int cols) {
    int** matrix = new int*[rows]{};
    for (int i = 0; i< rows; i++) {
        matrix[i] = new int[cols]{};
    }
    return matrix;
}



int main() {
    int rows{};
    int cols{};
}