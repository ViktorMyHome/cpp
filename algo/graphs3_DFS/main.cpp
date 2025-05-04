#include <iostream>
#include <assert.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// DFS - Depth First Search

typedef vector<vector<int>> GRAPH;

void add_edge(GRAPH &graph, int from, int to)
{
    graph[from].push_back(to);
}

void print_adjaceny_graph(GRAPH &graph)
{
    int nodes = graph.size();
    for(int from = 0; from<nodes; ++from){
        cout<<" node from "<<from<<" has neighbours: ";
        for(int to=0; to<graph[from].size(); ++to){
            cout<<graph[from][to]<<" ";
        }
        cout<<endl;
    }
}

void dfs(GRAPH &graph, int node, vector<bool> &visited) {
    visited[node] = true;
    for(int neighbour : graph[node]) {
        if(!visited[neighbour]) {
            cout<<" we can reach "<<neighbour<<endl;
            dfs(graph, neighbour, visited);
        }
    }
}

void reachability(GRAPH &graph) {
    int nodes = graph.size();
    for(int i=0; i<nodes; ++i) {
        vector<bool> visited(nodes);
        cout<<" Reachable set of node "<<i<<endl;
        dfs(graph, i, visited);
    }
}


// homework
// 1.
// LeetCode 582
// typedef map<int, vector<int>> Graph;
// void DFS(Graph &graph, int node, vector<int> &toRemove) {
//     toRemove.push_back(node);
//     for(int neighbour : graph[node]) {
//         if(count(toRemove.begin(), toRemove.end(), neighbour) == 0)
//             DFS(graph, neighbour, toRemove);
//     }
// }
// vector<int> killProcess(Graph &graph, int kill) {
//     vector<int> returned_vector;
//     DFS(graph, kill, returned_vector);
//     return returned_vector;
// }

// 2. LeetCode 690
struct Employee {
    int id;
    int importance;
    vector<int> subordinates;
    Employee(int id_, int importance_, vector<int> *array):id{id_}, importance{importance_} {
        for(int i=0; i<array->size(); ++i){
            subordinates.push_back(array->at(i));
        }
    }
    void print() {
        cout<<" id = "<<id<<endl;
        cout<<" importance = "<<importance<<endl;
        for(int i : subordinates) {
            cout<<i;
        }
        cout<<endl;
    }
};

void DFS(vector<Employee*> employees, int id, int &sum, vector<int> &nodes) {

    for(int i=0; i< employees.size(); ++i) {
        if(employees[i]->id == id && count(nodes.begin(), nodes.end(), id)==0) {
            nodes.push_back(id);
            //cout<<"id = "<<id<<endl;
            sum += employees[i]->importance;
            for(int j : employees[i]->subordinates) {
                //cout<<" subordinates = "<<j<<endl;
                DFS(employees, j, sum, nodes);
            }
        }
    }
}

int getImportance(vector<Employee*> employees, int id) {
    int sum=0;
    vector<int> visited_id;
    DFS(employees, id, sum, visited_id);
    return sum;
}


int main(){

    // int nodes, edges;
    // cin>>nodes>>edges;
    // GRAPH graph(nodes);
    // for(int e=0; e<edges; ++e)
    // {
    //     int from, to;
    //     cin>>from>>to;
    //     add_edge(graph, from, to);
    // }
    // print_adjaceny_graph(graph);
    // reachability(graph);

    // 1.
    // int pid[]={1, 3, 10, 5};
    // int ppid[]={3, 0, 5, 3};
    // Graph graph;
    // for(int i=0; i<sizeof(pid)/sizeof(int); i++) {
    //     graph[ppid[i]].push_back(pid[i]);
    // }
    // vector<int> ret = killProcess(graph, 3);
    // for(int i : ret)
    //     cout<<i<<endl;

    // 2.
    vector<Employee*> employees;
    vector<int> empl_;
    int size, id_, imp_, size_, val_;
    cin>>size;
    for(int i=0; i<size; i++) {
        cin>>id_>>imp_>>size_;
        for(int j=0; j<size_; j++) {
            cin>>val_;
            empl_.push_back(val_);
        }
        employees.push_back(new Employee(id_, imp_, &empl_));
        while(!empl_.empty())
            empl_.pop_back();
    }
    for(Employee *e : employees)
        e->print();
    int id;
    cin>>id;
    int importance = getImportance(employees, id);
    cout<<" importance = "<<importance<<endl;

    for(int i=0; i<size; i++) {
        delete(employees[i]);
    }



    return 0;
}
