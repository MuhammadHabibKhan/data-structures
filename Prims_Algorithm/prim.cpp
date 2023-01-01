#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
#include <limits>

using namespace std;

class Graph
{
public:
    int **matrix;
    string c_data;
    int vertices = 6;
    int v_next;
    int *selected;

    void createGraph()
    {
        //ofstream outfile;
        //outfile.open("vertices.txt");
        //cout << "Enter number of vertices in the graph: ";
        //cin >> vertices;
        matrix = new int *[vertices];
        selected = new int[vertices]{false};
        for (int i{}; i < vertices; i++)
        {
            matrix[i] = new int[vertices];
        }

        // for (int i{}; i < vertices; i++)
        // {
        //     cout << "Enter info for VERTEX " << i + 1 << endl;
        //     // outfile << i+1;
        //     for (int j{}; j < vertices; j++)
        //     {
        //         cout << "Weighted Edge with vertex " << j + 1 << " exists? (w/0): ";
        //         cin >> v_next;
        //         outfile << v_next;
        //         if (i == vertices - 1 && j == vertices - 1)
        //         {
        //             continue;
        //         }
        //         outfile << ",";
        //     }
        //     if (i != vertices - 1)
        //     {
        //         outfile << endl;
        //     }
        // }
        // outfile.close();
    }

    void adjacencyMatrix()
    {
        ifstream infile;
        infile.open("vertices.txt");

        for (int i{}; i < vertices; i++)
        {
            for (int j{}; j < vertices; j++)
            {
                cout << "| ";
                getline(infile, c_data, ',');
                // cout << c_data << endl;
                int x = stoi(c_data);
                matrix[i][j] = x;
                cout << matrix[i][j] << " |";
            }
            cout << endl;
        }
        infile.close();
    }

    void prim(){
        int edge_number = 0;
        selected[0] = true;
        int x; // row
        int y; // col
        cout << "Edge"
             << " : "
            << "Weight";
        cout << endl;
        while (edge_number < vertices - 1){
            int min = numeric_limits<int>::max();
            x = 0;
            y = 0;
            for (int i{}; i < vertices; i++){
                if (selected[i]){ // check for those which are true 
                    for (int j{}; j < vertices; j++){
                        if (!selected[j] && matrix[i][j]){ // if other vertex is not already selected and 
                        // an edge between the upper vertex and this one exist in the adjacency matrix. If not, zero will be there which is FALSE, 
                        // else weight of the edge will make it TRUE
                            if (min > matrix[i][j]){ 
                                min = matrix[i][j]; // swap the minimum if lower weighted edge found
                                x = i; // to keep track of the latest lowest
                                y = j; // so to use it after the for loop
                            }
                        }
                    }
                }
            }
            cout << x << " - " << y << " : " << matrix[x][y]; // lowest weight  
            cout << endl;
            selected[y] = true; // y used here because it represents each edge in each row or edge with respect to other edges while keeping the number correct as x changes
            edge_number++;
        }
    }

    ~Graph()
    {
        for (int i{}; i < vertices; i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
        delete[] selected;
    }
};

int main()
{
    Graph g;
    g.createGraph();
    g.adjacencyMatrix();
    g.prim();
    return 0;
}