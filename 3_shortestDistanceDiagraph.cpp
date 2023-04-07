/*
A digraph G(V,E) is given below where the vertices mark various cities and the edges mark the distances between cities. Indian railways plans to send trains between every pair of cities in the digraph following the shortest distance between them. Write a C program to find the shortest distance between all-pairs of cities in the digraph. The output should be printed in a matrix form.
*/

#include <bits/stdc++.h>
using namespace std;

#define INF 99999
#define V 4

void print(int dist[][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF "
                     << " ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

void floyd(int dist[][V]) {
    int i, j, k;

    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j] && (dist[k][j] != INF && dist[i][k] != INF))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    print(dist);
}

int main() {
    int x;
    int graph[V][V];

    cin >> x;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            cin >> graph[i][j];
        }
    }

    floyd(graph);

    return 0;
}