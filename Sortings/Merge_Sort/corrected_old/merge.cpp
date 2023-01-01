#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

class Merge{
private:
    int *array;
    int *sortedArray;
    int mid{};
public:
    int size{};
    Merge(int s);
    void merge(int lb, int m, int ub); 
    void mergeSort(int lb, int ub); 
    void printSorted();
    ~Merge();
};

Merge::Merge(int s){
    size = s;
    array = new int[size];
    sortedArray = new int[size]{};
    unsigned seed = time(0);
    srand(seed);
    // array[0] = 2;
    // array[1] = 4;
    // array[2] = 5;
    // array[3] = 7;
    // array[4] = 8;
    // array[5] = 1;
    // array[6] = 3;
    // array[7] = 9;
    // array[8] = 12;
    // array[9] = 14;
    cout << "-------------Unsorted Array--------------" << endl;
    for (int i{}; i<size; i++){
        array[i] = rand()%100;
        cout << "| " << array[i] << " |";
    }
    cout << endl;
}

void Merge::mergeSort(int lb, int ub){
    // splits the data until each sub-list only has one element 
    if (lb < ub){
        //(left no more is less than right as its equal to right)
        int m = (lb+ub)/2;
        // cout<<m<<endl;
        //cout << lb << " " << ub << " " << mid << endl; 
        mergeSort(lb, m); //first right side of the recursion will complete, breaking down the left side of the array into single element sub-lists
        //cout << lb << " " << ub << " " << mid << endl; 
        mergeSort(m+1, ub); // then left side will be broken down into single element list, (will start from bottom??)
        merge(lb, m, ub); // now merge function will crawl backwards, merging the single elements first, then 2, then 3 and till n times.
    }
}

void Merge::merge(int lb, int m, int ub){
    int i = lb;
    int j = m+1;
    int k = lb; //index to put elements in the sortedArray. Starts with lowest of that current merge.
    while (i <= m && j <= ub){ // loop still i reaches mid and j(mid+1) reaches the end
        // compare the elements in right and left half of the mid and run 3 counters to put elements 
        // in the sorted array (i,j,k).
        if (array[i] <= array[j]){
            // cout<<array[i]<<" - "<<array[j]<<endl;
            sortedArray[k] = array[i];
            // cout<<sortedArray[k]<<endl;
            i++;
        }
        else{
            // cout<<array[i]<<" - "<<array[j]<<endl;
            sortedArray[k] = array[j];
            // cout<<sortedArray[k]<<endl;
            j++;
        }
        k++;
    }
    // since the above while loop runs on the condition that both halfes must not reach their limit
    // so if any of the half reaches their limit and the other one still has elements, the following lines
    // places the values of the half with the remaining elements into the sorted array. 
    // Since each sub-list merged is always done in sorted in its own right(starting from single elements compared with each other),
    // then when merging at each step till last, two sorted sub-list always result in a sorted list using this algo since each element is compared.
    
    // if (i > m){ // if i reached the limit and crossed mid, hence j has elements left
    //     while (j <= ub){ // until j reaches the end
    //         sortedArray[k] = array[j]; // put elements into sorted array from j
    //         j++;
    //         k++;
    //     }
    // }
    // else{ // if j reached its limit so put elements from i into sorted array
    //     while (i <= m){
    //         sortedArray[k] = array[i]; 
    //         i++;
    //         k++;
    //     }
    // }
    while (i <= m)
    {
        sortedArray[k] = array[i];
        k++, i++;
    }
    while (j <= ub)
    {
        sortedArray[k] = array[j];
        k++, j++;
    }
    for (int c = lb; c <= ub; c++){
        array[c] = sortedArray[c];
    }
}

void Merge::printSorted(){
    cout << "-------------Sorted Array--------------" << endl;
    for (int i{}; i < size; i++){
        cout << "| " << sortedArray[i] << " |";
    }
}

Merge::~Merge(){
    delete[] array;
    delete[] sortedArray;
}

int main(){
    Merge m(10);
    m.mergeSort(0, m.size-1);
    m.printSorted();
    return 0;
}
