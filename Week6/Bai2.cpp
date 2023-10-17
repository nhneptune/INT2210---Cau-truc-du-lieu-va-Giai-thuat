#include <iostream>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

class Graph {
    bool** adjMatrix;
    int** weightMatrix;
    int numVertices;
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

    int dijkstra(int start, int end) {
        bool visited[numVertices + 1] = {false};
        int dist[numVertices + 1];
        for (int i = 1; i <= numVertices; i++) {
            dist[i] = INF;
        }
        dist[start] = 0;
        for (int i = 1; i <= numVertices - 1; i++) {
            int min = 1;
            for (int j = 2; j <= numVertices; j++) {
                if (!visited[j] && (dist[j] < dist[min])) {
                    min = j;
                }
            }
            visited[min] = true;
            for (int v = 0; v < numVertices; v++) {
                if (adjMatrix[min][v] == 1 && !visited[v] && dist[v] > dist[min] + weightMatrix[min][v]) {
                    dist[v] = dist[min] + weightMatrix[min][v];
                }
            }
        }
        return dist[end];
    }

    int shortestPath(int start, int end) {
        for (int i = 1; i <= numVertices; i++) {
            for (int j = 1; j <= numVertices; j++) {
                if (adjMatrix[i][j]) {
                    weightMatrix[i][j] = 1;
                }
            }
        }

        bool visited[numVertices + 1] = {false};
        int dist[numVertices + 1];
        for (int i = 1; i <= numVertices; i++) {
            dist[i] = INF;
        }
        dist[start] = 0;
        for (int i = 1; i <= numVertices - 1; i++) {
            int min = 0;
            for (int j = 1; j <= numVertices; j++) {
                if (!visited[j] && (min == 0 || dist[j] < dist[min])) {
                    min = j;
                }
            }
            visited[min] = true;
            for (int v = 1; v <= numVertices; v++) {
                if (adjMatrix[min][v] == 1 && !visited[v] && dist[v] > dist[min] + weightMatrix[min][v]) {
                    dist[v] = dist[min] + weightMatrix[min][v];
                }
            }
        }
        return dist[end];
    }
};

int main()
{
    int n, m, X, Y;
    cin >> n >> m >> X >> Y;
    Graph g(n);
    for (int i = 0;  i < m; i++) {
        int x, y;
        cin >> x >> y;
        g.addEdge(x, y);
    }
    cout << g.shortestPath(X, Y) << endl;

    return 0;
}