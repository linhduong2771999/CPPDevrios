#include <iostream>

using namespace std;

int *store_array(const int array_1[], const size_t arr1_size ,const int array_2[],const size_t arr2_size);

int main(){

    // Store 2 array to one array on the heap
    int array_1 [4] = {1, 4, 6, 22};
    int array_2 [6] = {5, 10, 0 ,23 ,63, 2};
    size_t arr1_size = sizeof(array_1)/sizeof(int);
    size_t arr2_size = sizeof(array_2)/sizeof(int);
    
    int *return_arr = store_array(array_1, arr1_size ,array_2 ,arr2_size);

    for (size_t i = 0; i < arr1_size*arr2_size; i++)
    {
        cout << return_arr[i] << " ";
    }
    

    delete [] return_arr;
    return 0;
}

int *store_array(const int array_1[], const size_t arr1_size ,const int array_2[],const size_t arr2_size){
    int *store_array = new int[arr1_size*arr2_size];
    int count = 0;
    for (size_t i = 0; i < arr1_size; i++)
    {
        for (size_t j = 0; j < arr2_size; j++)
        {
            store_array[count] = array_1[i]*array_2[j];
            count++;
        }
    }
    
    return store_array;
}