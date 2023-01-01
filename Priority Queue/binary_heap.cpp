#include <iostream>
#include <cmath>
using namespace std;
// max heap

//int arr[11] = {10, 3, 15, 7, 2, 12, 18, 20, -1, 9, -2};
int PQ[8] = {}; 
int c = 1;
int i;
void enqueue(int value)
{
    PQ[c] = value;
    i = c; 
    c = c + 1;
    while (i != 1){
        if (PQ[i] > PQ[int(i/2)]){
            swap(PQ[i],PQ[int(i/2)]);
            i = int(i/2);
        }
        else{
            break;
        }
    }
}
int n = 1;

void dequeue(){
    if (PQ[2*n] > PQ[(2*n)+1]){
        PQ[n] = PQ[2*n];
        n = 2*n;
        dequeue();
    }
    else if (PQ[2*n] < PQ[(2*n)+1]){
        PQ[n] = PQ[(2*n)+1];
        n = (2*n)+1;
        dequeue();
    }
    else{ // need to test this properly for last element acc to breadfirst having the bubble
    // current scenario does not utilize the code for that 
         PQ[n] = PQ[7];
    }
    PQ[n] = 0; // should be n = 1? 
}

int main()
{
    int x;
    for (int i=0; i<7; i++){
        //cout << "Enter number to add into the heap" << endl;
        //cin >> x;
        int arr[11] = {28,77,50,99,41,81,73};
        enqueue(arr[i]);
    }
    cout << "xxxxxxxxxxxxxxxxxxx" << endl;
    for (int j=1; j<8; j++){
        cout << PQ[j] << " ";
    }
    cout<<endl;
    dequeue();
    cout << "-----------------------" << endl;
    for (int j=1; j<8; j++){
        cout << PQ[j] << " ";
    }
    return 0;
}
