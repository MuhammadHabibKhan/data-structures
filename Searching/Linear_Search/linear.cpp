#include <iostream>
#include <ctime>
using namespace std;

class Linear{
public:
    int size;
    int *array;
    bool found;

    Linear(int s);
    void linearSearch(int d);
    ~Linear();
};

Linear::Linear(int s){
    size = s;
    array = new int[size];
    unsigned seed = time(0);
    srand(seed);
    for (int i{}; i<size; i++){
        array[i] = rand()%100;
        cout << "| " << array[i] << " |";
    }
    cout << endl;
    found = false;
}

void Linear::linearSearch(int d){
    found = false;
    for (int i{}; i<size; i++){
        if (array[i] == d){
            found = true;
            cout << "Element found at index: " << i << endl;
            break;
        }
    }
    if (found == false)
        cout << "Element not found" << endl;
}

Linear::~Linear(){
    delete[] array;
}

int main(){
    Linear l(10);
    l.linearSearch(0);
    return 0;
}