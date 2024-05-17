#include <iostream>
#include <queue>
using namespace std;
#define MAX 10

void dfs(int graph[MAX][MAX], int v, bool visited[MAX], int numver)
{
    visited[v] = true;
    cout << v << " ";

    for (int i = 0 ; i < numver; i++)
    {
        if (graph[v][i] == 1 && !visited[i])
        {
            dfs(graph, i, visited, numver);
        }
    }
}

int main()
{
    int numver = 6;        // Number of vertices in the graph
    int graph[MAX][MAX] = {// Adjacency matrix representation of the graph
                           {0, 1, 1, 0, 0, 0},
                           {1, 0, 1, 1, 0, 0},
                           {1, 1, 0, 0, 1, 0},
                           {0, 1, 0, 0, 1, 1},
                           {0, 0, 1, 1, 0, 1},
                           {0, 0, 0, 1, 1, 0}};

    bool visited[MAX] = {false};
    int str = 0;

    cout << "DFS" << str << ";";
    dfs(graph, str, visited, numver);
    return 0;
}