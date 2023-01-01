#include <iostream>
using namespace std;

int main() {
    int arr[10];
    for (int i=0;i<10;i++){
        cout << int(&arr[i]) << endl;
    }
    // int* p;
    // cout << *p << endl;
    // cout << &p << endl;
    // int a;
    // p = &a;
    // cout << *p << endl;
    // cout << &p << endl;

    return 0;
}