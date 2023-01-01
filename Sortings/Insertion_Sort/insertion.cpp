#include <iostream>
#include <ctime>
using namespace std;

class Insertion{
public:
    int *array;
    int temp{};
    int size{};

    Insertion(int s);
    void insertionSort();
    void printSorted();
    ~Insertion();
};

Insertion::Insertion(int s){
    size = s;
    array = new int[size];
    unsigned seed = time(0);
    srand(seed);
    cout << "-------------Unsorted Array--------------" << endl;
    for (int i{}; i<size; i++){
        array[i] = rand()%100;
        cout << "| " << array[i] << " |";
    }
    cout << endl;
}

// | sorted array | unsorted array| ==> structure
void Insertion::insertionSort(){
    for (int i = 1; i<size; i++){ // starts from 1 as first element is taken as sorted array
        temp = array[i];
        int j = i-1;
        while (j >= 0 && array[j] > temp){  //starts from right most of sorted array and goes to left. 
        //Compares element of unsorted array stored in temp with sorted array through the J loop. 
        //Will only advance if the element starting from right to left (decrement order for J loop) is greater than the temp as it is already sorted so if not larger encountered, don't right shift.
        array[j+1] = array[j]; // right shift
        j--; // decrement
        }
        array[j+1] = temp; // +1 as decrements first then condition checked for while loop. 
        // puts value after right shifting all the elements so that new value is in correct ordered position
    }
}

void Insertion::printSorted(){
    cout << "-------------Sorted Array--------------" << endl;
    for (int i{}; i < size; i++){
        cout << "| " << array[i] << " |";
    }
}

Insertion::~Insertion(){
    delete[] array;
}

int main(){
    Insertion i(10);
    i.insertionSort();
    i.printSorted();
    return 0;
}

