#include <iostream>

/**
 * @brief Структура безопасного динамического массива.
 *
 * Хранит указатель на динамический массив чисел
 * и его текущий размер.
 */
struct SafeArray {
    int* data;
    int size;
};

/**
 * @brief Создаёт динамический массив определенного размера.
 *
 * Выделяет память под массив и инициализирует все его элементы нулями.
 *
 * @param size Размер массива.
 * @return SafeArray Структура с указателем на массив и его размер.
 */
SafeArray createArray(int size) {
    int* data = new int[size]{};
    SafeArray sa;
    sa.data = data;
    sa.size = size;
    return sa;
}

/**
 * @brief Возвращает ссылку на элемент массива по индексу.
 *
 * Проверяет, находится ли индекс в допустимых пределах.
 * Если индекс неправильный, выводит ошибку
 * и возвращает ссылку на статическую переменную error.
 *
 * @param arr Ссылка на безопасный массив.
 * @param index Индекс элемента массива.
 * @return arr.data[index] Ссылка на найденный элемент или на переменную error
 */
int& getElement(SafeArray& arr, int index) {
    static int error = -1;
    if (index >= arr.size || index < 0) {
        std::cout << "Error";
        return error;
    }
    return arr.data[index];
}

/**
 * @brief Выводит все элементы массива.
 *
 * Элементы массива выводятся через разделитель |.
 *
 * @param arr Константная ссылка на безопасный массив.
 */
void printSafe(const SafeArray& arr) {
    for (int i = 0; i < arr.size; i++) {
        std::cout << arr.data[i] << " | ";
    }
}

/**
 * @brief Изменяет размер динамического массива.
 *
 * Создаёт новый массив определенного размера, копирует в него
 * элементы прошлого массива и освобождает старую память.
 * При уменьшении размера выводит удаленные элементы.
 *
 * @param N Текущий размер массива.
 * @param M Новый размер массива.
 * @param arr Ссылка на безопасный массив.
 */
void reSizeArray(int N, int M, SafeArray& arr) {
    if (N == M) {
        return;
    }
    int* new_data = new int[M]{};
    if (N > M) {
        for (int i = M; i < N; i++) {
            std::cout << arr.data[i] << " | ";
        }
        std::copy(arr.data, arr.data + M, new_data);
        delete[] arr.data;
        arr.data = new_data;
        arr.size = M;
    }
    if (N < M) {
        std::copy(arr.data, arr.data + N, new_data);
        delete[] arr.data;
        arr.data = new_data;
        arr.size = M;
    }
}

/**
 * @brief Основная функция.
 *
 * Создаёт безопасный массив, изменяет его элементы и размер,
 * выводит содержимое массива и освобождает выделенную память.
 *
 */
int main() {
    SafeArray MyArr;
    MyArr = createArray(5);
    getElement(MyArr, 2) = 999;
    std::cout << MyArr.data[2] << "\n";
    printSafe(MyArr);
    reSizeArray(5, 10, MyArr);
    std::cout << "\n";
    getElement(MyArr, 6) = 666;
    printSafe(MyArr);
    std::cout << "\n";
    reSizeArray(10, 3, MyArr);
    std::cout << "\n";
    printSafe(MyArr);
    delete[] MyArr.data;
    MyArr.data = nullptr;
    return 0;
}