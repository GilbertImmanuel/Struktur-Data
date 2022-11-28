#include<bits/stdc++.h>
using namespace std;

class Graph {
private:
    int V;
    vector<list<int>> adj;
public:
    Graph(int V){
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    void toPrint() {
    for (int i = 0; i < V; i++) {
      cout << i << " --> ";
      for (auto adjecent: adj[i]) {
          cout << adjecent << " ";
      }
      cout << "/\n";
    }
  }
};


 
int main() {
    Graph g(22);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(0, 6);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.addEdge(3, 13);
    g.addEdge(4, 5);
    g.addEdge(5, 3);
    g.addEdge(6, 7);
    g.addEdge(7, 8);
    g.addEdge(7, 9);
    g.addEdge(7, 17);
    g.addEdge(9, 7);
    g.addEdge(9, 10);
    g.addEdge(9, 11);
    g.addEdge(10, 11);
    g.addEdge(11, 12);
    g.addEdge(13, 14);
    g.addEdge(13, 16);
    g.addEdge(13, 17);
    g.addEdge(14, 15);
    g.addEdge(15, 16);
    g.addEdge(16, 15);
    g.addEdge(17, 13);
    g.addEdge(17, 18);
    g.addEdge(17, 19);
    g.addEdge(19, 20);
    g.addEdge(19, 21);
    g.addEdge(20, 21);

    g.toPrint();
 
    return 0;
}
