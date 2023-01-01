#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

class Merge{
private:
    //int *array;
    //int *sortedArray;
    //int mid{};
public:
    int size{};
    Merge(int s);
    void merge(int* array, int lb, int m, int ub); 
    void mergeSort(int *array, int lb, int ub); 
    void printSorted();
    ~Merge();
};

Merge::Merge(int s){
    size = s;
    // array = new int[size];
    // sortedArray = new int[size]{};
    // unsigned seed = time(0);
    // srand(seed);
    // cout << "-------------Unsorted Array--------------" << endl;
    // for (int i{}; i<size; i++){
    //     array[i] = rand()%11;
    //     cout << "| " << array[i] << " |";
    // }
    // cout << endl;
}

void Merge::mergeSort(int *array, int lb, int ub){
    // splits the data until each sub-list only has one element 
    if (lb < ub){
        //(left no more is less than right as its equal to right)
        int mid = floor((lb+ub)/2);
        //cout << lb << " " << ub << " " << mid << endl; 
        mergeSort(array, lb, mid); //first right side of the recursion will complete, breaking down the left side of the array into single element sub-lists
        //cout << lb << " " << ub << " " << mid << endl; 
        mergeSort(array, mid+1, ub); // then left side will be broken down into single element list, (will start from bottom??)
        merge(array, lb, mid, ub); // now merge function will crawl backwards, merging the single elements first, then 2, then 3 and till n times.
    }
}

void Merge::merge(int *array, int lb, int m, int ub){
    int i = lb;
    int j = m+1;
    int k = 0; //index to put elements in the sortedArray. Starts with lowest of that current merge.
    int *sortedArray = new int[ub-lb+1];
    while (i <= m && j <= ub){ // loop still i reaches mid and j(mid+1) reaches the end
        // compare the elements in right and left half of the mid and run 3 counters to put elements 
        // in the sorted array (i,j,k).
        if (array[i] <= array[j]){
            sortedArray[k] = array[i];
            i++;
        }
        else{
            sortedArray[k] = array[j];
            j++;
        }
        k++;
    }
    // since the above while loop runs on the condition that both halfes must not reach their limit
    // so if any of the half reaches their limit and the other one still has elements, the following lines
    // places the values of the half with the remaining elements into the sorted array. 
    // Since each sub-list merged is always done in sorted in its own right(starting from single elements compared with each other),
    // then when merging at each step till last, two sorted sub-list always result in a sorted list using this algo since each element is compared.
    
    //if (i > m){ // if i reached the limit and crossed mid, hence j has elements left
        while (j <= ub){ // until j reaches the end
            sortedArray[k] = array[j]; // put elements into sorted array from j
            j++;
            k++;
        }
    //}
    //else{ // if j reached its limit so put elements from i into sorted array
        while (i <= m){
            sortedArray[k] = array[i]; 
            i++;
            k++;
        }
    //}
    for (int c = lb; c <= ub; c++){
        array[c] = sortedArray[c-lb];
    }
}

// void Merge::printSorted(){
//     cout << "-------------Sorted Array--------------" << endl;
//     for (int i{}; i < size; i++){
//         cout << "| " << sortedArray[i] << " |";
//     }
// }

Merge::~Merge(){
    //delete[] array;
    //delete[] sortedArray;
}

int main(){
    Merge m(10);
    int *a = new int[m.size];
    for (int i{}; i<10; i++){
        a[i] = rand()%11;
    }
    for (int i{}; i<10; i++){
        cout << a[i] << " " ;
    }
    cout << endl;

    m.mergeSort(a, 0, m.size-1);

    for (int i{}; i<10; i++){
        cout << a[i] << " " ;
    }
    //m.printSorted();
    return 0;
}
