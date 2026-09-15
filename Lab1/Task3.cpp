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
        std::cout << arr.data[i];
    }
}

int main() {
    SafeArray MyArr;
    MyArr = createArray(5);
    getElement(MyArr, 2) = 999;
    std::cout << MyArr.data[2] << "\n";
    printSafe(MyArr);
    return 0;
}