#include <iostream>
using namespace std;

void SelectionSort(int* array, int array_size){
  int min_index;
  for(int i = 0; i < array_size; i++){
    min_index = i;
    for(int j = i; j < array_size; j++){
      if(array[min_index] > array[j]){
        min_index = j;
      }
    }
    swap(array[i], array[min_index]);
  }
}

void BubbleSort(int* array,int array_size){
  bool swapped = true;
  while(swapped){
    swapped = false;
    for (int i = 0; i < array_size - 1; i++){
      if(array[i] > array[i+1]){
        swap(array[i], array[i+1]);
        swapped = true;
      }
    }
  }
}

int main(){
  int numbers[] = {3,42,25,72,17,80,5};

  //SelectionSort(numbers, 7);
  BubbleSort(numbers, 7);

  for(int i = 0; i < 7; i++){
      cout << numbers[i] << endl;
  }
  return 0;
}
