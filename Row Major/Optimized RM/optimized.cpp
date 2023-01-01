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
    int temp = 1;
    const int size[3] = {2,3,2};
    int input_row;
    int q = 0;

    for (int x = sizeof(size)/sizeof(int) -1; x >= 0; x--){
        // dimensions entered in reverse order
        cout << "Enter index of address for dimension " << x+1 << ": " << endl;
        cin >> input_row;
        if (x == sizeof(size)/sizeof(int)-1){
            q += input_row;
        }
        else{
            if (x==0){

            }
            temp = temp * size[x+1];
            int middle = input_row * temp;
            q += middle;
        }
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