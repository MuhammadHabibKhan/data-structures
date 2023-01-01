#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

# define edge pair<int, int>

// works on Union find algorithm which puts vertices forming a
// a loop in a cluster so if some vertex is in the same vertex as
// its predecessor, it does not add as loop is formed.
// https://www.youtube.com/watch?v=ayW5B2W9hfo 
// see this explanation on Union Find

// code based on code from 'Programiz.com'


class graph{
private:
    vector <pair <int, edge> > g; // weight , edge (Graph)
    vector <pair <int, edge> > t; // Minimum Spanning Tree
    int *parent; // array to hold parent of each element
    int vertices; // number of vertices in the graph
public:
    graph(int v);
    void add_WeightedEdge(int u, int v, int w);
    int find_set(int i); // returns the cluster to whcih the edge belongs to
    void union_set(int u, int v); // put the vertex in the same cluster after addition
    void kruskal(); //generates minimum spanning tree
    void printMST(); //prints MST
    ~graph();
};

graph::graph(int v){
    parent = new int [v];
    // each vertex first has itself as its parent
    for (int i{}; i<v; i++){
        parent[i] = i; 
    }
    g.clear();
    t.clear(); 
    // clear the graphs and the MST's vector just in case
}

void graph::add_WeightedEdge(int u, int v, int w){
    g.push_back(make_pair(w, edge(u,v)));
}

int graph::find_set(int i){
    if (i == parent[i])
        return i;
    else
        return find_set(parent[i]);
        // if i not the root of cluster, then call function again on the vertex's 
        // parent and traverse up till the root is found. See union_find video.
}

void graph::union_set(int u, int v) {
  parent[u] = parent[v];
}

void graph::kruskal(){
    int i, uParent, vParent;
    sort(g.begin(), g.end()); // sort the vertices in increasing order of their weights
    for (int i{}; i<g.size(); i++){
        uParent = find_set(g[i].second.first); // as [w, (u,v)] so second.first for u
        vParent = find_set(g[i].second.second); // accessing v now so second.second
        if (uParent != vParent){
            //if both parents are not equal, hence the original vertices do not belong to
            // to the same cluster, hence we push the edge to the MST
            t.push_back(g[i]);
            union_set(uParent, vParent); // once edges are formed, the clusters are connected
            // (union_set) so that further vertices do not form a cycle
        }
    }
}

void graph::printMST(){
    cout << "Edge :"
     << " Weight" << endl;
    for (int i = 0; i < t.size(); i++) {
        cout << t[i].second.first << " - " << t[i].second.second << " : "
        << t[i].first;
        cout << endl;
    }
}

graph::~graph(){
    delete[] parent;
}

int main(){
    graph g1(6);
    g1.add_WeightedEdge(0, 1, 5);
    g1.add_WeightedEdge(0, 2, 3);
    g1.add_WeightedEdge(0, 5, 7);
    g1.add_WeightedEdge(1, 0, 5);
    g1.add_WeightedEdge(1, 2, 6);
    g1.add_WeightedEdge(1, 3, 2);
    g1.add_WeightedEdge(1, 4, 4);
    g1.add_WeightedEdge(2, 0, 3);
    g1.add_WeightedEdge(2, 1, 6);
    g1.add_WeightedEdge(2, 3, 3);
    g1.add_WeightedEdge(2, 5, 8);
    g1.add_WeightedEdge(3, 1, 2);
    g1.add_WeightedEdge(3, 2, 3);
    g1.add_WeightedEdge(3, 4, 2);
    g1.add_WeightedEdge(4, 1, 4);
    g1.add_WeightedEdge(4, 3, 2);
    g1.add_WeightedEdge(5, 0, 7);
    g1.add_WeightedEdge(5, 2, 8);
    
    g1.kruskal();
    g1.printMST();
    return 0;
}