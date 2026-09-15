#include <iostream>

struct SafeArray {
    int* data;
    int size;
};

SafeArray createArray(int size) {
    int* data = new int[size]{};
    SafeArray sa;
    sa.data = data;
    sa.size = size;
    return sa;
}

int& getElement(SafeArray& arr, int index) {
    static int error = -1;
    if (index >= arr.size || index < 0) {
        std::cout << "Error";
        return error;
    }
    return arr.data[index];
}

void printSafe(const SafeArray& arr) {
    for (int i = 0; i < arr.size; i++) {
        std::cout << arr.data[i] << " | ";
    }
}

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