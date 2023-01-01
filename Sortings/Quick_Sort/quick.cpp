// ------time complexity-----------------
// best case: O(n logn) as divide and conquer
// worst case: O(n^2)
// ------space complexity-----------------
// why O(nlogn)?? when no extra temp are created for recursion. They all use the same temp. 
//https://en.wikipedia.org/wiki/Quicksort#:~:text=The%20space%20used%20by%20quicksort,requires%20O(1)%20space.
//https://cs.stackexchange.com/questions/138335/what-is-the-space-complexity-of-quicksort
// these articles mention the use of local variables at each recursive step which leads to O(nlogn) but my class implementation 
// does not seem to use any extra space. It remains constant through out O(1). Ask Sir about this and this algo's stack space usage.
// Muhammad Habib Khan - B20102088

#include <iostream>
#include <ctime>
using namespace std;

class Quick{
private:
    int *array;
    int pivot{};
    int start{};
    int end{};
    int temp{};

public:
    int size{};
    Quick(int s);
    int partitionArray(int lb, int ub);
    void quickSort(int lb, int ub);
    void printSorted();
    ~Quick();
};

Quick::Quick(int s){
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

int Quick::partitionArray(int lb, int ub){
    pivot = array[lb]; // choosing pivot as first element (one of many techniques, can choose last, middle ..)
    start = lb; // upper bound
    end = ub; // lower bound
    while (start < end){ // till start does not goes beyond end
        while (array[start] <= pivot){
            start++; //equal condition here so elements get shifted right
            // if it was below,then equal would've shifted to left since its decrement there
        }
        while (array[end] > pivot){
            end--; // end gets reduced and start gets increased to meet the pivot
        }
        if (start < end){ // check and swap only if start was less than end
            temp = array[start];
            array[start] = array[end];
            array[end] = temp;
        }
    }
    // as start looks for lower values than the pivot, hence if the start passes the end
    // that means end has a lower value than the pivot so we swap pivot and end 
    // this results in the correct position of pivot in the array, then we call the function
    // recursively in quickSort using partitions and end returned through this function
    temp = array[lb];
    array[lb] = array[end];
    array[end] = temp;
    return end;
}

void Quick::quickSort(int lb, int ub){
    if (lb < ub){
        int location = partitionArray(lb,ub);
        quickSort(lb, location-1);
        quickSort(location+1, ub);
    }
}

void Quick::printSorted(){
    cout << "-------------Sorted Array--------------" << endl;
    for (int i{}; i < size; i++){
        cout << "| " << array[i] << " |";
    }
}

Quick::~Quick(){
    delete[] array;
}

int main(){
    Quick q(10);
    q.quickSort(0, q.size-1);
    q.printSorted();
    return 0;
}