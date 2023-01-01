#include <iostream>
#include <ctime>
using namespace std;

class Selection{
public:
    int *array;
    int temp{};
    int size{};

    Selection(int s);
    void selectionSort();
    void printSorted();
    ~Selection();
};

Selection::Selection(int s){
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

void Selection::selectionSort(){
    for (int i{}; i < size-1; i++){
        int min = i; // need to take min = i (the index not the value as in last line, 
        // we need to update the array using array[min] not just change the variable min. Else extra loop required to find the matching index.
        for (int j = i+1; j < size; j++){
            if (array[j] < array[min])
                min = j;
        }
        if (min != i){
            //cout << min << " / " ;
            //cout << array[i] << endl;
            // swap
            temp = array[i];
            array[i] = array[min];
            array[min] = temp;
        }
    }
}

void Selection::printSorted(){
    cout << "-------------Sorted Array--------------" << endl;
    for (int i{}; i < size; i++){
        cout << "| " << array[i] << " |";
    }
}

Selection::~Selection(){
    delete[] array;
}

int main(){
    Selection s(10);
    s.selectionSort();
    s.printSorted();
    return 0;
}