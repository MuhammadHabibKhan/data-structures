#include <iostream>
using namespace std;

int main() {
    // creating a dynamic jagged array
    int rows, cols;
    cout << "no. of rows: ";
    cin >> rows;
    cout << "no. of columns: ";
    cin >> cols;

    int size[] = {rows,cols};

    int** jagged_array = new int* [rows];
    for (int i=0; i<rows; i++){
        jagged_array[i] = new int[cols];
    }
    
    // goal is to make a contiguous non-jagged array on heap

    int count = 0;
    cout << "Jagged Array" << endl;
    for (int i=0; i<rows; i++){
        for (int j=0; j<cols; j++){
            jagged_array[i][j] = count;
            cout << jagged_array[i][j] << endl; 
            ++count;
        }
    }
    
    int linear_space = 1;
    for (int i=0; i<2; i++){
        linear_space = linear_space * size[i];
    };

    int* arr = new int[linear_space];

    int c = 0;
    cout << "Non-Jagged Array" << endl;
    for (int i=0; i<rows; i++){
        for (int j=0; j<cols; j++){
            arr[c] = jagged_array[i][j];
            cout << arr[c] << endl; 
            ++c;
        }

    }
    // deallocating
    for (int i=0; i<rows; i++){
        delete jagged_array[i];
    }

    delete[] jagged_array;
    jagged_array = NULL;

    return 0;
}