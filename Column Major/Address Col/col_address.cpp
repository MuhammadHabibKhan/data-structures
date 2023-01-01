#include <iostream>
using namespace std;

// goal is to implement address finding algorithm
int main() {
    int arr [2][3][2];
    //int count = 0;
    // for (int i=0; i<2; i++){
    //     for (int j=0; j<3; j++){
    //         arr[i][j] = count;
    //         cout << arr[i][j] << endl; 
    //         ++count;
    //     }
    //}
    int* base_address = &(arr[0][0][0]);
    const int size_dt = sizeof(int); 
    int middle = 1;
    const int size[3] = {2,3,2};
    int input_row;
    int q = 0;
    // fix it to avoid cache miss, just change the order of the loops
    for (int x=0; x < sizeof(size)/sizeof(int); x++){
        for (int y=0; y <= x-1; y++){
            if (x-1 >= 0){ // avoids the empty product condition 
            middle = middle * (size[y]); 
        }
        }
        cout << "Enter index of address for dimension " << x+1 << ": " << endl;
        cin >> input_row;
        middle = middle * input_row;
        q = q + middle;
        middle = 1;
    }

    cout << "Middle part: " << q << endl;
    cout << "Base Address: " << int(base_address) << endl;
    int address;
    address = int(base_address) + (q * size_dt);
    cout << "Address of given indices: " << address << endl; 

    base_address = NULL;
    return 0;
}

// summation [Ii * Product ( Sj)]