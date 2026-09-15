#include <iostream>

/**
 * @brief Заполняет массив.
 *
 * Функция считывает 10 чисел и записывает их в переданный массив.
 *
 * @param arr Массив из 10 чисел, который можно заполнить.
 */
void fillArray(int (&arr)[10]){
    for (int &element : arr) {
        std::cin >> element;
    }
}

/**
 * @brief Выводит массив.
 *
 * Элементы массива выводятся через пробел, в конце будет
 * переход на новую строку.
 *
 * @param arr Массив из 10 чисел которые нужно вывести.
 */
void printArray(int (&arr)[10]){
    for (auto &element : arr) {
        std::cout << element << " ";
    }
    std::cout << "\n";
}

/**
 * @brief Меняет местами два элемента.
 *
 * Использует временную переменную для обмена значениями двух
 * элементов.
 *
 * @param element1 Первый элемент.
 * @param element2 Второй элемент.
 */
void swapElements(int &element1, int &element2){
    int temp = element1;
    element1 = element2;
    element2 = temp;
}

/**
 * @brief Умножает каждый элемент массива на 2.
 *
 * Проходит по всем элементам массива и умножает каждый
 * элемент на 2.
 *
 * @param arr Массив из 10 чисел.
 */
void multiplyByTwo(int (&arr)[10]){
    for (int &x : arr) {
        x *= 2;
    }
}

/**
 * @brief Основная функция.
 *
 * Создаёт массив из 10 чисел, заполняет его,
 * выводит его, меняет местами первые два элемента,
 * а в конце умножает все элементы на 2.
 *
 */
int main(){
    int arr[10]{};
    fillArray(arr);
    printArray(arr);
    swapElements(arr[0], arr[1]);
    printArray(arr);
    multiplyByTwo(arr);
    printArray(arr);
    return 0;
}