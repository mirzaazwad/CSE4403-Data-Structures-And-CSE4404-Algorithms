#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> graph(10); // Adjacency list representation of the graph
vector<int> sorted; // Resulting topologically sorted order

void topological_sort(int n) {
    queue<int> q;
    //find inorder
    vector<int> indegree(n,0); // Indegree of each node
    for( int i = 0 ; i < n ; i++){
        for (int j = 0; j< graph[i].size(); j++) {
            int neighbor = graph[i][j];
            indegree[neighbor]++;
        }
    }
    // Enqueue all nodes with indegree 0
    for (int i = 0; i < indegree.size(); i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        sorted.push_back(current);

        // Decrement indegree of neighbors
        for (int i = 0; i < graph[current].size(); i++) {
            int neighbor = graph[current][i];
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
}

int main() {
    // Initialize graph, indegree, and sorted vectors
    // ...
    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(3);
    graph[2].push_back(3);
    topological_sort(4);

    // Print the sorted order
    for (int i = 0; i < sorted.size(); i++) {
        cout << sorted[i] << " ";
    }

    return 0;
}