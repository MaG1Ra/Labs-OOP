#include <iostream>

void fillArray(int (&arr) [10]){
   for(int &element : arr){
    std::cin >> element;
   } 
}

void printArray(int (&arr) [10]){
    for(auto &element : arr){
        std::cout << element << " ";
    }
}

void swapElements(int &element1, int &element2){
    int temp = element1;
    element1 = element2;
    element2 = temp;
}

int main(){
    int arr[10]{};
    fillArray(arr);
    printArray(arr);
    swapElements(arr[0], arr[1]);
    printArray(arr);
    return 0;
}