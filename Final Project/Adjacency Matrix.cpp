#include <iostream>
using namespace std;

class Graph {
   private:
  bool** adjMatrix;
  int numVertices;

   public:
  // Initialize the matrix to zero
  Graph(int numVertices) {
    this->numVertices = numVertices;
    adjMatrix = new bool*[numVertices];
    for (int i = 0; i < numVertices; i++) {
      adjMatrix[i] = new bool[numVertices];
      for (int j = 0; j < numVertices; j++)
        adjMatrix[i][j] = false;
    }
  }

  // Add edges
  void addEdge(int i, int j) {
    adjMatrix[i][j] = true;
    adjMatrix[j][i] = true;
  }

  // Remove edges
  void removeEdge(int i, int j) {
    adjMatrix[i][j] = false;
    adjMatrix[j][i] = false;
  }

  // Print the martix
  void toString() {
    for (int i = 0; i < numVertices; i++) {
      cout << i << "\t: ";
      for (int j = 0; j < numVertices; j++)
        cout << adjMatrix[i][j] << " ";
      cout << "\n";
    }
  }

  ~Graph() {
    for (int i = 0; i < numVertices; i++)
      delete[] adjMatrix[i];
    delete[] adjMatrix;
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

  g.toString();
}
