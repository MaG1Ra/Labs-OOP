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

int main() {
    SafeArray MyArr;
    MyArr = createArray(5);
}