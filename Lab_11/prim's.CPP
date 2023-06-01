#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

/* This function finds the minimum key vertex which is not yet included in MST */
int minKey(vector<int>& key, vector<bool>& mstSet, int V) {
    int min = INF, min_index;
    for (int v = 0; v < V; v++) {
        if (mstSet[v] == false && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

/* This function prints the MST */
void printMST(vector<int>& parent, vector<vector<int>>& graph, int V) {
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
}

/* This function finds the MST of a given graph using Prim's algorithm */
void primMST(vector<vector<int>>& graph, int V) {
    vector<int> parent(V); 
    vector<int> key(V, INF); // Key values used to pick minimum weight edge in cut
    vector<bool> mstSet(V, false); 

    // Initialize all keys as INFINITE
    for (int i = 0; i < V; i++)
        key[i] = INF;

    // remove comment mark to Choose Starting vertex
    /*
     cout << "Start vertex= ";
     int src;
     cin >> src;
     key[src] = 0;
     
     */
    //Starting vertex is 0
    key[0] = 0;
    

    
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex which is not yet included in MST
        int u = minKey(key, mstSet, V);

        // Add the picked vertex to the MST set
        mstSet[u] = true;

        /* Update key value and parent index of the adjacent vertices of the picked vertex.
           Consider only those vertices which are not yet included in MST */
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    printMST(parent, graph, V);
}

int main() {

    int V = 6;
    vector<vector<int>> graph = { 
                        { 0, 3, 0, 0, 0, 1 },
                        { 3, 0, 2, 1,10, 0 },
                        { 0, 2, 0, 3, 0, 5 },
                        { 0, 1, 3, 0, 5, 0 },
                        { 0,10, 0, 5, 0, 4 },
                        { 1, 0, 5, 0, 4, 0 } };
    

    primMST(graph, V);

    return 0;
}
