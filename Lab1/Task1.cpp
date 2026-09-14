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

int main(){
    int arr[10]{};
    fillArray(arr);
    printArray(arr);
    return 0;
}