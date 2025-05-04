#include <iostream>
#include <assert.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// BFS - Breadth First Search
typedef vector<vector<int>> GRAPH;

const int OO = 10000000; // a big value expressing infinity

void add_undirected_edge(GRAPH &graph, int from, int to) {
    graph[from].push_back(to);
    graph[to].push_back(from);
}

vector<int> BFS_v1(GRAPH &adjList, int start) {
    vector<int> len(adjList.size(), OO);
    queue<pair<int, int>> q;
    q.push({start, 0});
    len[start]=0;
    while(!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        int cur = p.first, level = p.second;

        for(int neighbour : adjList[cur])
            if(len[neighbour] == OO) { // never visited
                q.push({neighbour, level + 1});
                len[neighbour] = level + 1;
            }
    }
    return len;
}

vector<int> BFS_v2(GRAPH &adjList, int start) {
    vector<int> len(adjList.size(), OO);
    queue<int> q;
    q.push(start);
    len[start]=0;

    for(int level=0, sz=1; !q.empty(); ++level, sz = q.size()) {
        while(sz--) {
            int cur = q.front();
            q.pop();
            for(int neighbour : adjList[cur])
                if(len[neighbour] == OO) { // never visited
                    q.push(neighbour);
                    len[neighbour] = level + 1;
                }
        }
    }
    return len;
}


int main(){


    return 0;
}
