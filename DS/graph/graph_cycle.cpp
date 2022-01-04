#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<list>
using namespace std;
std::map<int, vector<int> > graph;

void addEdge(int x, int y) {
    graph[x].push_back(y);
//    graph[y].push_back(x);
};

struct visit {
    bool visited;
    int visitedParent;
};
// if there ia no cycle in a grpah, it can be considered as tree.
//  - if there are more than one incoming path on a node - there is a cycle (except the path
//  should not be coming from it's child during traversal)
bool  is_tree(int src) {
    struct visit visitData[50] = {};
    for (int i=0; i<50; i ++) {
        visitData[i].visited = false;
        visitData[i].visitedParent = 0;
    }

    queue<int> q;
    visitData[src].visited = true;
    q.push(src);
    while(!q.empty()) {
        src = q.front();
        q.pop();
        for (auto node: graph[src]) {
            if(!visitData[node].visited) {
                cout << "visiting " << node << endl;
                // visit node
                q.push(node);
                visitData[node].visitedParent = src;
                visitData[node].visited = true;
            } else {
                if(visitData[node].visitedParent != src) {
                    return false;
                }

            }
        }
    }
    return true;
}

int main(){
    //each vertex will be the key
    //each key will have list of edges connected to it
    addEdge(2,3);
    addEdge(3,4);
    //addEdge(1,0);
//    addEdge(2,3);
 //   addEdge(3,4);
    //addEdge(4,0);

    /*
    addEdge(6,7);
    addEdge(5,6);

    addEdge(8,8);
    */
    /*

    for(auto mapObj : graph) {
        cout << mapObj.first << endl;
        for (auto neighbour : mapObj.second) {
            cout << neighbour << " ";
        }
        cout << endl;
    }*/
//    DFS_non_connected();
    cout << is_tree(2) << endl;
    return 0;
}
