#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Structure to represent a node and its distance from the source node
struct Node {
    int vertex;
    int dist;
};

// Comparison function for the priority queue
struct CompareNode {
    bool operator()(Node const& n1, Node const& n2) {
        return n1.dist > n2.dist; // Min heap based on distance
    }
};

void dijkstra(vector<vector<int>>& graph, int source) {
    int num_vertices = graph.size();
    
    // Create a vector to store the distance of each vertex from the source node
    vector<int> dist(num_vertices, INT_MAX);
    
    // Mark the distance of the source node as 0
    dist[source] = 0;
    
    // Create a priority queue to store the nodes to be processed
    priority_queue<Node, vector<Node>, CompareNode> pq;
    
    // Add the source node to the priority queue
    pq.push({source, 0});
    
    // Process the nodes until the priority queue is empty
    while (!pq.empty()) {
        // Get the node with minimum distance from the priority queue
        int u = pq.top().vertex;
        pq.pop();
        
        // Iterate through all the adjacent vertices of the current node
        for (int v = 0; v < num_vertices; ++v) {
            // If there is an edge between the current node and the adjacent node
            if (graph[u][v]) {
                // Calculate the distance of the adjacent node from the source through the current node
                int new_dist = dist[u] + graph[u][v];
                
                // If the new distance is less than the current known distance of the adjacent node from the source
                if (new_dist < dist[v]) {
                    // Update the distance of the adjacent node in the vector
                    dist[v] = new_dist;
                    
                    // Add the adjacent node to the priority queue along with its updated distance
                    pq.push({v, new_dist});
                }
            }
        }
    }
    
    // Print the distances of all the vertices from the source
    cout<< "From City "<< source<<" => "<<endl;
    for (int i = 0; i < num_vertices; ++i) {
        cout << "City " << i << ": " << dist[i] << endl;
    }
    cout<<endl;
}

int main() {

    //adajaceny matrix of the problem
    int V = 6;
    vector<vector<int>> graph = {
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };
    

    
    // Run Dijkstra's Algorithm on the graph from vertex i
    for (int i =0;i<V; ++i){
       dijkstra(graph, i);
    }
    
    
    return 0;
}
