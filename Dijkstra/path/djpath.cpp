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
    int vertices = 14;
    int v_next;
    bool *selected;
    int *distances;
    int *previous;
    vector <int> path;

    void createGraph()
    {
        // ofstream outfile;
        // outfile.open("vertices.txt");
        // cout << "Enter number of vertices in the graph: ";
        // cin >> vertices;
        matrix = new int *[vertices];
        selected = new bool[vertices]{false};
        distances = new int[vertices];
        previous = new int[vertices];

        for (int i{};i<vertices;i++){
            distances[i] = numeric_limits<int>::max();
            previous[i] = -1;
        }
        // combine the loops up and below
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

    int find_minVertex(){
        int minVertex = -1;
        for (int i{}; i < vertices; i++){
            if (!selected[i] && (minVertex == -1 || distances[i] < distances[minVertex])){ // check if selected always 
            // then if -1 default then always replace with minVertex else check if lower then replace 
                minVertex = i;
            }
        }
        return minVertex;
    }

    void pathFunction(int j){
        //path.push_back(j);
        // while (j != s || j != 0){
        //     j = previous[j];
        //     path.push_back(j);
        // }
        if (j == -1){
            //cout << "j is source" << endl;
            return;
        }
        pathFunction(previous[j]);
        cout << j << " ";
        //path.push_back(s);
    }

    void dijkstra(int source){
        distances[source] = 0; // set the distance from source to itself to zero
        
        for (int i{}; i<vertices; i++){
            if (matrix[source][i] != 0)
                distances[i] = matrix[source][i];
        }

        for (int i{}; i < vertices-1; i++){
            int minVertex = find_minVertex();
            selected[minVertex] = true;
            int temp = 0;
            // exploring all of minimum vertex's neighbours 
            for (int j{}; j<vertices; j++){
                // edge exists (if neighbour) and not already visited
                if (matrix[minVertex][j] != 0 && !selected[j]){
                    // new distance from source to min vertex plus the distance from minVertex to the neighbour
                    int dist = distances[minVertex] + matrix[minVertex][j];
                    // now checking if the new link is shorter than previous distance before replacing (initially all distances are infinity)
                    if (dist < distances[j]){
                        distances[j] = dist;
                        previous[j] = minVertex;
                        temp = j;
                    }
                }
            }
            cout << temp << endl;
            //cout << "--------" << endl;
            if (temp == 6)
                pathFunction(minVertex);
            //for (int x{}; x<path.size(); x++){
                //cout << path.at(x) << ' ';
            //}
            cout << endl;
            //path.clear();
        }       
        // for (int i{}; i<vertices; i++){
        //     cout << i << " " << distances[i] << endl;
        // }
    }

    ~Graph()
    {
        for (int i{}; i < vertices; i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
        delete[] selected;
        delete[] distances;
    }
};

int main()
{
    Graph g;
    g.createGraph();
    g.adjacencyMatrix();
    g.dijkstra(0);
    return 0;
}