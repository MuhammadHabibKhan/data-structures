#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Graph
{
public:
    int **matrix;
    string c_data;
    int vertices = 6;
    int v_next;
    // int *indegrees = new int [vertices];
    // vector<int> zero_indegree;
    vector<int> sorted_array;
    vector<int> indegrees;
    bool *visited = new bool[vertices]{false};

    // methods
    void createGraph()
    {
        // ofstream outfile;
        // outfile.open("vertices.txt");
        // cout << "Enter number of vertices in the graph: ";
        // cin >> vertices;

        matrix = new int *[vertices];
        for (int i{}; i < vertices; i++)
        {
            matrix[i] = new int[vertices];
        }

        //     for (int i{}; i < vertices; i++){
        //         cout << "Enter info for VERTEX " << i+1 << endl;
        //         //outfile << i+1;
        //         for (int j{}; j < vertices; j++){
        //             cout << "Edge with vertex " << j+1 << " exists? (1/0): ";
        //             cin >> v_next;
        //             outfile << v_next;
        //             if (i == vertices-1 && j == vertices-1){
        //                 continue;
        //             }
        //             outfile << ",";
        //         }
        //         if (i != vertices-1){
        //             outfile << endl;
        //         }
        //     }
        //     outfile.close();
    }

    void adjacencyMatrix()
    {
        ifstream infile;
        infile.open("vertices1.txt");

        cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
        cout << "---------ADJACENCY MATRIX-------" << endl;
        for (int i{}; i < vertices; i++)
        {
            for (int j{}; j < vertices; j++)
            {
                cout << "| ";
                getline(infile, c_data, ',');
                int x = stoi(c_data);
                matrix[i][j] = x;
                cout << matrix[i][j] << " |";
            }
            cout << endl;
        }
        infile.close();
        cout << "-------------------------------" << endl;
    }

    void calculateIndegree()
    {
        indegrees.clear();
        cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
        cout << "----------INDEGREE ARRAY--------" << endl;
        for (int j{}; j < vertices; j++)
        {
            int counter{};
            for (int i{}; i < vertices; i++)
            {
                if (matrix[j][i] != 0)
                {
                    counter++;
                }
            }
            indegrees.push_back(counter);
            cout << "| " << counter << " |";
        }
        cout << endl;
        cout << "-------------------------------" << endl;

        // cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
        // cout << "-----ZERO INDEGREE VERTICES-----" << endl;
        // for (int i{}; i < vertices; i++)
        // {
        //     if (indegrees[i] == 0)
        //     {
        //         zero_indegree.push_back(i);
        //         cout << "| " << i << " |";
        //     }
        // }
        // cout << endl;
        // cout << "-------------------------------" << endl;
    }

    void topologicalSort()
    {
        int i{};
        this->calculateIndegree();
        while (i < vertices)
        {
            if (indegrees[i] == 0 && visited[i] == false)
            {
                visited[i] = true;
                sorted_array.push_back(i);
                for (int j{}; j < vertices; j++)
                {
                    matrix[j][i] = 0;
                }
                for (int k{}; k < vertices; k++)
                {
                    for (int l{}; l < vertices; l++){
                        cout << "| ";
                        cout << matrix[k][l] << " |";
                    }
                    cout << endl;
                }
            }
            i++;
        }
        bool check = checkVisited();
        if (check == true)
            topologicalSort();
    }

    bool checkVisited()
    {
        for (int x{}; x < vertices; x++)
        {
            if (visited[x] == false)
                return true;
        }
        return false;
    }

    void printTopological()
    {
        cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
        cout << "-------TOPOLOGICAL SORTED-------" << endl;
        for (int i{}; i < sorted_array.size(); i++)
        {
            cout << "| " << sorted_array[i] << " |";
        }
        cout << endl;
        cout << "--------------------------------" << endl;
    }

    ~Graph()
    {
        for (int i{}; i < vertices; i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
        // delete[] indegrees;
    }
};

int main()
{
    Graph g;
    g.createGraph();
    g.adjacencyMatrix();
    // g.calculateIndegree();
    g.topologicalSort();
    g.printTopological();

    return 0;
}