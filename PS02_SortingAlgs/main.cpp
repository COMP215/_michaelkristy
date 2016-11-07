#include <stdio.h>
#include <iostream>

using namespace std;
void MergeFunction(int* left_array,int* right_array, int* array);

int* MergeSort(int *array){

    int array_size = sizeof(array)/sizeof(array[0]);
    int midSize = array_size/2;
    int left_array[midSize];
    int right_array_size = array_size - midSize;
    int right_array[right_array_size];

    if(array_size < 2){
        return array;
    }

    for(int i = 0; i < midSize - 1; i++){
        left_array[i] = array[i];
    }
    for(int j = midSize; j < array_size - 1; j++){
        right_array[j-midSize] = array[j];
    }

    MergeSort(left_array);
    MergeSort(right_array);
    MergeFunction(left_array, right_array, array);
    return array;
}

void MergeFunction(int* left_array,int* right_array, int* array){

    int i = 0;
    int k = 0;
    int j = 0;

    int left_array_size = sizeof(left_array)/sizeof(left_array[0]);
    int right_array_size = sizeof(right_array)/sizeof(right_array[0]);

    while(i < left_array_size && j < right_array_size){
        if(left_array[i] <= right_array[j]){
            array[k] = left_array[i];
            k++;
            i++;
        }
        else{
            array[k] = right_array[j];
            j++;
        }
        k++;
    }
    while(i < left_array_size){
        array[k] = left_array[i];
        i++;
        k++;
    }
    while(j < right_array_size){
        array[k] = right_array[j];
        j++;
        k++;
    }
}

int main(){

    int random_number_array[] = {8,1,4,576,3,2,6,8};

    int size_of_array = sizeof(random_number_array)/sizeof(random_number_array[0]);
    cout << "Your unsorted array sir/maddam:" << endl;
    for(int j = 0; j < size_of_array; j++){
        cout << random_number_array[j] << " ";
    }

    cout << endl << "Your sorted array sir/maddam:" << endl;

    MergeSort(random_number_array);
    for(int i = 0; i < size_of_array; i++){
        cout << random_number_array[i] << " ";
    }
    cout << endl;

    return 0;
}
