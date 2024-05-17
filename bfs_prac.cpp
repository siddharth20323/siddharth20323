#include <iostream>
#include <queue>
using namespace std;
#define MAX 10

void bfs(int graph[MAX][MAX],int start,int numver){
    bool visited[MAX]={false};
    queue<int>q;

    visited[start]=true;
    q.push(start);

    while(!q.empty()){
        int curr=q.front();
        q.pop();
        cout<<curr<<" ";

        for(int i=0;i<numver;i++){
            if(graph[curr][i]==1 && !visited[i]){
                visited[i]=true;
                q.push(i);
            }
        }

    }
}
int main() {
    int numver = 6; // Number of vertices in the graph
    int graph[MAX][MAX] = { // Adjacency matrix representation of the graph
        {0, 1, 1, 0, 0, 0},
        {1, 0, 1, 1, 0, 0},
        {1, 1, 0, 0, 1, 0},
        {0, 1, 0, 0, 1, 1},
        {0, 0, 1, 1, 0, 1},
        {0, 0, 0, 1, 1, 0}
    };

    int stv=0;
    cout<<"bfs"<<stv<<";";
    bfs(graph,stv,numver);
    return 0;
}