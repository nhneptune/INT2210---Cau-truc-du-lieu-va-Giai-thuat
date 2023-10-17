#include <iostream>

using namespace std;

class Graph {
    bool** adjMatrix;
    int** weightMatrix;
    int numVertices;
    void DFS(int v, bool visited[]) {
        visited[v] = true;
        for (int i = 1; i <= numVertices; i++) {
            if (adjMatrix[v][i] && !visited[i]) {
                DFS(i, visited);
            }
        }
    }
public:

    Graph(int numVertices) {
        this->numVertices = numVertices;
        numVertices++;
        adjMatrix = new bool*[numVertices];
        weightMatrix = new int*[numVertices];
        for (int i = 0; i < numVertices; i++) {
            adjMatrix[i] = new bool[numVertices];
            weightMatrix[i] = new int[numVertices];
            for (int j = 0; j < numVertices; j++) {
                adjMatrix[i][j] = false;
                weightMatrix[i][j] = 0;
            }
        }
    }

    void addEdgeWithWeight(int i, int j, int weight) {
        adjMatrix[i][j] = true;
        weightMatrix[i][j] = weight;
    }

    void addEdge(int i, int j) {
        adjMatrix[i][j] = true;
    }

    int numberOfConnectedComponents() {
        bool* visited = new bool[numVertices];
        for (int i = 1; i <= numVertices; i++) {
            visited[i] = false;
        }
        int count = 0;
        for (int i = 1; i <= numVertices; i++) {
            if (!visited[i]) {
                DFS(i, visited);
                count++;
            }
        }
        return count;
    }

};

int main()
{
    int n, m;
    cin >> n >> m;
    Graph g(n);
    for (int i = 0;  i < m; i++) {
        int x, y;
        cin >> x >> y;
        g.addEdge(x, y);
    }
    cout << g.numberOfConnectedComponents() << endl;
    return 0;
}