#include <iostream>
#include <assert.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// [from] {{to, weight}, {to, weight}, ...}
// [from] .......


// routed tree representation:
// key: every node has one parent only
// node:   0 1 2 3 4  5  6
// parent: 5 5 5 2 1 -1  2
// -1 means does not have parent

typedef vector<vector<pair<int,int>>> GRAPH;

void add_directed_edge(GRAPH &graph, int from, int to, int weight)
{
    graph[from].push_back(make_pair(to, weight));
}

void add_undirected_edge(GRAPH &graph, int from, int to, int weight)
{
    graph[from].push_back(make_pair(to, weight));
    graph[to].push_back(make_pair(from, weight));
}

void print_adjaceny_graph(GRAPH &graph)
{
    int nodes = graph.size();
    for(int from = 0; from<nodes; ++from){
        cout<<" node from "<<from<<" has neighbours: ";
        for(int to; to<graph[from].size(); ++to){
            cout<<graph[from][to].first<<" "<<" weight: "<<graph[from][to].second;
        }
        cout<<endl;
    }
}

// homework
// 1.
// class Edge{
// public:
//     int weight;
//     int from;
//     int to;
//     Edge(int f, int t, int cost): weight(cost), from(f), to(t){}
//     bool operator <(const Edge valToComp){
//         return this->weight < valToComp.weight ? true : false;
//     }
// };

// typedef vector<Edge> GRAPH2;

// void add_edge(GRAPH2 &graph, int from, int to, int cost) {
//     graph.push_back(Edge(from, to, cost));
// }

// void print_adjaceny_matrix(GRAPH2 &graph) {
//     sort(graph.begin(), graph.end());
//     for(int i=0; i<graph.size(); ++i) {
//         cout<<" from "<<graph[i].from<<" to "<<graph[i].to<<" weight "<<graph[i].weight<<endl;
//     }
// }

// 2.
// typedef vector<unordered_set<int>> GRAPH3;

// void add_edge(GRAPH3 &graph, int from, int to) {
//     graph[from].insert(to);
// }

// bool is_edge_exist(GRAPH3 &graph, int from, int to) {
//     auto it = graph[from].find(to);
//     if(it!=graph[from].end()) {
//         cout<<" found "<<*it<<endl;
//         return true;
//     } else {
//         cout<<" not found "<<to<<endl;
//         return false;
//     }
// }

// void print_graph(GRAPH3 &graph) {
//     for (int from=0; from<graph.size();  ++from) {
//         for (auto it = graph[from].begin(); it!=graph[from].end(); it++) {
//             cout<<" from "<<from<<" to "<<*it<<endl;
//         }
//     }
// }

typedef vector<multimap<int, int>> GRAPH4;

void add_edge(GRAPH4 &graph, int from, int to, int cost) {
    graph[from].insert(make_pair(to, cost));
}

void print_graph(GRAPH4 &graph) {
    for(int from=0; from<graph.size(); ++from) {
        for(auto it = graph[from].begin(); it!=graph[from].end(); it++) {
            cout<<" from "<<from<<" to "<<it->first<<" costs "<<it->second<<endl;
        }
    }
}

int main(){

    // int nodes, edges, weight;
    // cin>>nodes>>edges;
    // GRAPH graph(nodes);
    // for(int e=0; e<edges; ++e)
    // {
    //     int from, to;
    //     cin>>from>>to>>weight;
    //     add_directed_edge(graph, from, to, weight);
    // }
    // print_adjaceny_graph(graph);


    // homework
    // 1.
    // int from, to, weight, edges;
    // cin>>edges;
    // GRAPH2 graph;
    // for (int e=0; e<edges; ++e) {
    //     cin>>from>>to>>weight;
    //     add_edge(graph, from, to, weight);
    // }
    // print_adjaceny_matrix(graph);

    // 2.
    // int from, to, edges;
    // cin>>edges;
    // GRAPH3 graph(edges);
    // for(int f=0; f<edges; ++f) {
    //     cin>>from>>to;
    //     add_edge(graph, from, to);
    // }
    // is_edge_exist(graph, 0, 2);
    // is_edge_exist(graph, 2, 3);

    // 3.
    
    int from, to, cost, edges;
    cin>>edges;
    GRAPH4 graph(edges);
    for(int f=0; f<edges; ++f) {
        cin>>from>>to>>cost;
        add_edge(graph, from, to, cost);
    }
    print_graph(graph);

    return 0;
}
