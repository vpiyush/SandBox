// dijkastra single source shortest path
// find shortest path in a wighted graph
// we will define a graph which would store all the nodes and edges with their wiegths
#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<list>
#include<set>
using namespace std;


// map (node, list of neighpors<nodeid, dist>)
std::map<int, vector<std::pair<int, int>> > graph;

void addEdge(int x, int y, int dist, bool bidir=true) {
    graph[x].push_back(std::make_pair(y, dist));
    if (bidir)
        graph[y].push_back(std::make_pair(x, dist));
}

void BFS_SSSP(int source) {
    // unordred map for each dist from a given source
    map<int, int> dist;
    for (auto i: graph) {
        dist[i.first] = INT_MAX;
    }

    std::set<std::pair<int, int>> visitedSet;

    dist[source] = 0;
    visitedSet.insert(make_pair(0, source));

    while(!visitedSet.empty()) {

        auto p = *(visitedSet.begin());
        auto node = p.second;

        int nodeDist = p.first;
        visitedSet.erase(visitedSet.begin());
        for (auto nbr : graph[node]) {
            cout << node << " " <<nbr.second << endl;
            if(nodeDist + nbr.second < dist[nbr.first]) {
               auto newdist =  nodeDist + nbr.second;
               // remove the esiting node
               cout << newdist << endl;
               auto f = visitedSet.find(make_pair(dist[nbr.first], nbr.first));
               if (f != visitedSet.end()) {
                   visitedSet.erase(f);
               }
               // update the existing distance
               dist[nbr.first] = newdist;
               // create new node
               visitedSet.insert(make_pair(newdist, nbr.first));
            }
        }
    }

    for (auto j : dist) {
        cout << "dist from source to current node " << j.first << " is "<<j.second << endl;
    }

}


int main() {
    addEdge(1,2, 1);
    addEdge(2,3, 4);
    addEdge(3,4, 2);
    addEdge(1,4, 1);
    /*
    addEdge(1,2, 1);
    addEdge(1,3, 4);
    addEdge(2,3, 1);
    addEdge(3,4, 2);
    addEdge(1,4, 7);
    */

    BFS_SSSP(1);
}

