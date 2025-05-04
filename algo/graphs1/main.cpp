#include <iostream>
#include <assert.h>
#include <vector>
using namespace std;

typedef vector<vector<int>> GRAPH;

void add_directed_edge(GRAPH &graph, int from, int to, int cost)
{
    graph[from][to] = cost;
}

void add_undirected_edge(GRAPH &graph, int from, int to, int cost)
{
    graph[from][to] = graph[to][from] = cost;
}

void print_graph(GRAPH &graph)
{
    for(int from = 0; from<graph.size(); ++from)
    {
        for(int to = 0; to<graph[from].size(); ++to)
        {
            cout<<" from "<<from<<" to "<<to<<" edge "<<graph[from][to]<<endl;
        }
    }
}

int main(){

    int nodes, edges;
    cin>>nodes>>edges;
    GRAPH graph(nodes, vector<int>(nodes));

    for(int e=0; e<edges; ++e)
    {
        int from, to, cost;
        cin>>from>>to>>cost;
        add_undirected_edge(graph, from, to, cost);
    }

    print_graph(graph);

    return 0;
}
