#include <iostream>

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