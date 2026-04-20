#include <iostream>
#include <climits>
using namespace std;

#define V 5

// Function to find vertex with minimum distance
int minDistance(int dist[], bool visited[])
{
    int min = INT_MAX;
    int min_index = -1;

    for (int v = 0; v < V; v++)
    {
        if (visited[v] == false && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void dijkstra(int graph[V][V], int src)
{
    int dist[V];
    bool visited[V];

    // Initialize distances
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, visited);

        visited[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && graph[u][v] &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "Vertex   Distance from Source\n";
    for (int i = 0; i < V; i++)
        cout << i << " \t\t " << dist[i] << endl;
}

int main()
{
    int graph[V][V] = {
        {0, 4, 1, 0, 0},
        {4, 0, 2, 5, 0},
        {1, 2, 0, 3, 8},
        {0, 5, 3, 0, 6},
        {0, 0, 8, 6, 0}
    };

    dijkstra(graph, 0);

    return 0;
}