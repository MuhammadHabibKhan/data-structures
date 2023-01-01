#include <iostream>
#include <ctime>
using namespace std;

class Bubble{
public:
    int *array;
    bool flag;
    int temp{};
    int size{};

    Bubble(int s);
    void bubbleSort();
    void printSorted();
    ~Bubble();
};

Bubble::Bubble(int s){
    size = s;
    flag = false;
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

void Bubble::bubbleSort(){
    for (int i{}; i < size-1; i++){
        flag = false;
        for (int j{}; j<size-1-i; j++){ // -i because the elements keep bubbling up the end and gets sorted (if sorting in ascending order, 
        //largest goes at the end, then at second pass second largest goes to second last position) so no need to go through them again.
            if (array[j] >array[j+1]){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                flag = true;
            }
        }
        if (flag == false) // one entire pass without swap means sorted fully so stop the loop
            break;
    }
}

void Bubble::printSorted(){
    cout << "-------------Sorted Array--------------" << endl;
    for (int i{}; i < size; i++){
        cout << "| " << array[i] << " |";
    }
}

Bubble::~Bubble(){
    delete[] array;
}

int main(){
    Bubble b(10);
    b.bubbleSort();
    b.printSorted();
    return 0;
}