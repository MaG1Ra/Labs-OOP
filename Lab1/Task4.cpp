#include <iostream>

int** allocateMatrix(int rows, int cols) {
    int** matrix = new int*[rows]{};
    for (int i = 0; i< rows; i++) {
        matrix[i] = new int[cols]{};
    }
    return matrix;
}

void fillMatrix(int** matrix, int rows, int cols) {
    srand(time(NULL));
    for (int i = 0; i < rows;i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 4 + 2;
        }
    }
}

void printMatrix(int** matrix, int rows, int cols, bool showBorders = true, std::string title = "Matrix"){
    std::cout << title << "\n";
    if(showBorders){
        for(int i = 0; i < cols + 5; i++){
            std::cout << "*";
        }
        std::cout << "\n";
    }

    for(int i = 0; i < rows; i++){
        if(showBorders){
            std::cout << "*";
        }
        for(int j = 0; j < cols; j++){
            std::cout << matrix[i][j];
            if(j != cols - 1){
                std::cout << " ";
            }
        }
        if(showBorders){
            std::cout << "*";
        }
        std::cout << "\n";
    }

    if(showBorders){
        for(int i = 0; i < cols + 5; i++){
            std::cout << "*";
        }
    }
}

int main() {
    int rows{4};
    int cols{4};
    int** Matrix{allocateMatrix(rows, cols)};
    fillMatrix(Matrix, rows, cols);
    printMatrix(Matrix, rows, cols, true, "Grades");
}