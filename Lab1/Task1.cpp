#include <iostream>

void fillArray(int (&arr) [10]){
   for(int &element : arr){
    std::cin >> element;
   } 
}

int main(){
    int arr[10]{};
    fillArray(arr);
    return 0;
}