#include <iostream>

/**
 * @brief Обрабатывает динамический массив до первого отрицательного элемента.
 *
 * Функция ищет первый отрицательный элемент в массиве,
 * затем если отрицательный элемент найден, создаётся новый массив,
 * в котором находятся элементы до отрицательного,
 * Старый массив освобождается, а указатель arr переходит на новый массив.
 *
 * @param arr Ссылка на указатель на динамический массив целых чисел.
 * @param size Размер массива.
 */
void process(int*& arr, int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            int* arr_all_positive = new int[i]{};
            std::copy(arr, arr+i, arr_all_positive);
            delete[] arr;
            arr = arr_all_positive;
            for (int j = 0; j < i; j++) {
                std::cout << arr[j] << " ";
            }
            std::cout << "\n";
            break;
        }
    }
}

/**
 * @brief Основная функция.
 *
 * Считывает размер массива и его элементы,
 * передаёт массив в process(), после чего освобождает
 * выделенную память. Потом проверяет память.
 *
 */
int main() {
    int N;
    std::cin >> N;
    int* arr = new int[N]{};
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }
    process(arr, N);
    delete[] arr;
    arr = nullptr;
    if (arr == nullptr) {
        std::cout << "Error";
    }
    else {
        std::cout << *arr;
    }
    return 0;
}