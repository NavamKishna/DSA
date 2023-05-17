
#include <iostream>
#include<list>
using namespace std;

struct Node{
    int label; // A node will have a data type int called label
    list<int> neighbours; // and a int type list called neighbours
};

struct Graph{
    int n=8;
    Node * nodes = new Node[n]; // Graph will have an array of type "node" with length specified by n

    void intializenodes(){
        for(int i=0;i<n;i++){
            nodes[i].label=i+1; // Iterate through the nodes and assign labels
        }
    }

    void addedge(int u, int v){
        nodes[u-1].neighbours.push_back(v); // Select node u and push v into u's neighbour
        nodes[v-1].neighbours.push_back(u); // Select node v and push u into v's neighbour
    }

    void print(){
        for(int i=0;i<n;i++){
            cout << "Node " << nodes[i].label << " has neighbours: ";
            for(auto it=nodes[i].neighbours.begin(); it!=nodes[i].neighbours.end(); it++){
                cout << *it << " "; // Print each node's neighbours
            }
            cout << endl;
        }
    }
};

int main() {
    Graph * g = new Graph;
    g->intializenodes();
    g->addedge(1,2);
    g->addedge(3,1);
    g->addedge(1,4);
    g->addedge(1,5);
    g->addedge(6,2);
    g->addedge(2,3);
    g->addedge(4,6);
    g->addedge(7,4);
    g->addedge(4,8);
    g->addedge(5,6);
    g->addedge(5,7);
    g->addedge(8,5);
    g->print(); // Print the graph adjacency list
}
