#include <iostream>
#include <string>

/**
 * @brief Выделяет память для двумерного динамического массива.
 *
 * Создаёт матрицу с указанным количеством строк и столбцов
 * и инициализирует все её элементы нулевыми значениями.
 *
 * @param rows Кол-во строк.
 * @param cols Кол-во столбцов.
 * @return matrix Указатель на созданную матрицу.
 */
int** allocateMatrix(int rows, int cols) {
    int** matrix = new int*[rows]{};
    for (int i = 0; i< rows; i++) {
        matrix[i] = new int[cols]{};
    }
    return matrix;
}

/**
 * @brief Заполняет матрицу случайными цифрами.
 *
 * Каждый элемент матрицы получает случайное значение от 2 до 5.
 *
 * @param matrix Указатель на матрицу.
 * @param rows Кол-во строк.
 * @param cols Кол-во столбцов.
 */
void fillMatrix(int** matrix, int rows, int cols) {
    srand(time(NULL));
    for (int i = 0; i < rows;i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 4 + 2;
        }
    }
}

/**
 * @brief Выводит матрицу.
 *
 * Выводит название матрицы и её элементы.
 * При включённом showBorders дополнительно
 * отображает границы матрицы.
 *
 * @param matrix Указатель на матрицу.
 * @param rows Кол-во строк.
 * @param cols Кол-во столбцов.
 * @param showBorders Определяет, нужно ли отображать границы матрицы.
 * @param title Заголовок перед матрицей.
 */
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

/**
 * @brief Освобождает память, выделенную для матрицы.
 *
 * Сначала освобождает память каждой строки матрицы,
 * после чего освобождает память самого массива указателей.
 *
 * @param matrix Указатель на матрицу.
 * @param rows Кол-во строк.
 */
void freeMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

/**
 * @brief Основная функция.
 *
 * Создаёт матрицу 4x4, заполняет её случайными цифрами
 * и выводит её в 3 вариантах.
 * После завершения освобождает выделенную память.
 *
 */
int main() {
    int rows{4};
    int cols{4};
    int** Matrix{allocateMatrix(rows, cols)};
    fillMatrix(Matrix, rows, cols);
    printMatrix(Matrix, rows, cols, true, "Grades");
    std::cout << "\n";
    printMatrix(Matrix, rows, cols, false, "Grades");
    std::cout << "\n";
    printMatrix(Matrix, rows, cols);
    freeMatrix(Matrix, rows);
}