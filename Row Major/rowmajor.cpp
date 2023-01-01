// #include <iostream>
// using namespace std;

// int main() {
//     int dim;
//     cout << "Enter number of dimensions: " << endl;
//     cin >> dim;

//     int* size = new int[dim];
//     for (int i=0; i<dim; i++){
//         cout << "Enter size for each dimension in ascending order" << endl;
//         cin >> size[i];
//     }

//     int linear_space = 1;
//     for (int i=0; i<dim; i++){
//         linear_space = linear_space * size[i];
//     };

//     int* arr = new int[linear_space];  

//     delete[] size;
//     delete[] arr;
//     size = NULL;
    
//     return 0;
// }