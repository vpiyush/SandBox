#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<list>
using namespace std;


std::map<int, vector<int> > graph;

void addEdge(int x, int y) {
    graph[x].push_back(y);
    graph[y].push_back(x);
}


void DFS_recurse(int src, map<int, int>&visited) {
    cout << " "<< src;
    visited[src] = visited[src]+1;

    for (auto node : graph[src]) {
        if(!visited[node]) {
            DFS_recurse(node, visited);
        }
    }
}

void DFS_recurse(int src, map<int, int>&visited, list<int> &ordering) {
    cout << " "<< src;
    visited[src] = visited[src]+1;

    for (auto node : graph[src]) {
        if(!visited[node]) {
            DFS_recurse(node, visited, ordering);
        }
    }
    ordering.push_front(src);
}

void DFS_non_connected() {
    map<int, int> visited;
  //  visited[src] = 0;
    int count = 0;
    for (auto entry : graph) {
        auto node = entry.first;
        if(!visited[node]) {
            cout << "component " << count << " ==> ";
            DFS_recurse(node, visited);
            count ++;
            cout << endl;
        }
    }

}
void DFS(int src) {
    map<int, int> visited;
    visited[src] = 0;

    DFS_recurse(src, visited);

}

void DFS_topo_sort(int src) {
    map<int, int> visited;
    visited[src] = 0;

    list<int> ordering;
    DFS_recurse(src, visited, ordering);
    for (auto n : ordering) {
        cout << " " << n;
    }
    cout << endl;

}
void BFS(int src) {

    // store int, which represents the distance from the source node
    map<int, int> visited;
    queue<int> q;
    q.push(src);
    visited[src] = 0;

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << endl;
        for (auto n: graph[node]) {
            if(!visited[n]) {
                q.push(n);
                visited[n] = visited[n] + 1;
            }
        }
    }
}

int main(){
    //each vertex will be the key
    //each key will have list of edges connected to it
    addEdge(0,1);
    addEdge(1,2);
    addEdge(2,3);
    addEdge(3,4);

    addEdge(6,7);
    addEdge(5,6);

    addEdge(8,8);
    /*

    for(auto mapObj : graph) {
        cout << mapObj.first << endl;
        for (auto neighbour : mapObj.second) {
            cout << neighbour << " ";
        }
        cout << endl;
    }*/
//    DFS_non_connected();
    DFS_topo_sort(0);
    return 0;
}
