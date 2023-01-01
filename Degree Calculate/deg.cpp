#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
using namespace std;

class Graph{
    public:
        int** matrix;
        string c_data;
        int vertices{};
        int v_next;
    // methods
        void createGraph(){
            ofstream outfile;
            outfile.open("vertices.txt");
            cout << "Enter number of vertices in the graph: ";
            cin >> vertices;

            matrix = new int* [vertices];
            for (int i{}; i<vertices; i++){
                matrix[i] = new int [vertices];
            }

            for (int i{}; i < vertices; i++){
                cout << "Enter info for VERTEX " << i+1 << endl;
                //outfile << i+1;
                for (int j{}; j < vertices; j++){
                    cout << "Edge with vertex " << j+1 << " exists? (1/0): ";
                    cin >> v_next;
                    outfile << v_next;
                    if (i == vertices-1 && j == vertices-1){
                        continue;
                    }
                    outfile << ",";
                }
                if (i != vertices-1){
                    outfile << endl;
                }
            }
            outfile.close();
        }

        void adjacencyMatrix(){
            ifstream infile;
            infile.open("vertices.txt");

            for (int i{}; i < vertices; i++){
                for (int j{}; j < vertices; j++){
                    cout << "| ";
                    getline(infile, c_data, ',');
                    //cout << c_data << endl;
                    int x = stoi(c_data);
                    matrix[i][j] = x;
                    cout << matrix[i][j] << " |";
                }
                cout << endl;
            }
            infile.close();
        }       

        void calculateIndegree(int v){
            int counter{};
            for (int i{}; i<vertices; i++){
                if (matrix[v-1][i] != 0){
                    counter++;
                }
            }
            cout << "Indegree of vertex " << v << " : " << counter << endl;
        }

        void calculateOutdegree(int v){
            int counter{};
            for (int i{}; i<vertices; i++){
                if (matrix[i][v-1] != 0){
                    counter++;
                }
            }
            cout << "Outdegree of vertex " << v << " : " << counter << endl;
        }

        ~Graph(){
            for (int i{}; i<vertices; i++){
                delete[] matrix[i];
            }
            delete[] matrix;
        }
};

int main(){
    Graph g;
    g.createGraph();
    g.adjacencyMatrix();
    g.calculateIndegree(1);
    g.calculateOutdegree(2);
    return 0;
}