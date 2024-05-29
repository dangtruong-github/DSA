#include<iostream>

using namespace std;

int main() {
    cout << "\n\n";
    /*
        Declare arrays:
        - First way: declare array of size 4 with predefined elements
        - Second way: allocate memories to array of size 3
    */
    int numbers1[] = {11, 12, 13, 14};
    int numbers2[3];

    /* 
        Get length of array
    */
    int len_arr_1 = sizeof(numbers1) / sizeof(int);
    int len_arr_2 = sizeof(numbers2) / sizeof(int);

    cout << "Length of array 1: " << len_arr_1 << "\n";
    cout << "Length of array 2: " << len_arr_2 << "\n";


    /*
        Access elements of array + Loop through an array
    */
    for (int i = 0; i < 4; i++) {
        cout << numbers1[i] << " ";
    }
    cout << "\n";

    for (int i = 0; i < 3; i++) {
        cout << numbers2[i] << " ";
    }
    cout << "\n";
}