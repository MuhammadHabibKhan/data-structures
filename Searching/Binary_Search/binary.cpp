#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

class Binary{
public:
    int *array;
    int left{};
    int right{};
    int mid{};
    int size{};
    bool found;

    Binary(int s);
    void binarySearch(int d);
    ~Binary();
};

Binary::Binary(int s){
    found = false;
    size = s;
    array = new int[size];
    for (int i{}; i<size; i++){
        int p = i*2;
        array[i] = p;
        cout << "| " << array[i] << " |";
    }
    cout << endl;
}

void Binary::binarySearch(int d){
    found = false;
    left = 0;
    right = size - 1;
    mid = 0;
    while (left <= right){
        mid = floor((left+right)/2);
        if (d == array[mid]){
            found = true;
            cout << "Element found at index: " << mid << endl;
            break;
        }
        else if (d < array[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    if (found == false)
        cout << "Element not found!" << endl;
}

Binary::~Binary(){
    delete[] array;
}

int main(){
    Binary b(10);
    b.binarySearch(20);
    return 0;
}