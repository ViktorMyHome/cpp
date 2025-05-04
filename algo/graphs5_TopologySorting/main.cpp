#include <iostream>
#include <assert.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// Topology Sorting
typedef vector<vector<int>> GRAPH;

// Returns list containing vertices in topological order
// v - vertex
vector<int> topologicalSort(vector<vector<int>> &adj, int v) {
    // vector to store indegree of each vertex
    vector<int> indegree(v);
    for(auto v : adj) {
        for(int i = 1; i<v.size(); i++) {
            indegree[v[i]]++;
        }
    }
    queue<int> q;
    for(int i=0; i<v; ++i) {
        if(indegree[i] == 0)
            q.push(i);
    }

    vector<int> result;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);

        indegree[node]--;

        for(auto it : adj[node]) {
            indegree[it]--;
        
            if(indegree[it] == 0)
                q.push(it);
        }
    }
    return result;
}


int main(){
    int N = 6;
    // edges
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {4, 5}, {5, 1}, {5, 2}};

    vector<int> result = topologicalSort(edges, N);

    for(int r : result) {
        cout<<r<<" ";
    }


    return 0;
}
