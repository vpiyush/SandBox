#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<list>
using namespace std;
class DSU {
    public:
    int * parent;
    int * rank;
    DSU(int totV) {
        parent = new int[totV];
        rank = new int[totV];
        for (int i=0; i < totV; i++) {
            parent[i] = -1;
        }
    }
   // find set root of the elem
   int findSetRoot(int elem) {
       if (parent[elem] == -1) {
           return elem;
       }
       // path comprestion optimization
       return parent[elem] = findSetRoot(parent[elem]);
   }
   // find union
   // union by rank => this will ensure connectivity happens based on the size of the sets.
   // this would help in creating perfect flattened out tree with the help of path compression algorithm
   void union_set(int x, int y) {
       int s1root = findSetRoot(x);
       int s2root = findSetRoot(y);
       if (s1root != s2root) {
           if (rank[s1root] > rank[s2root]) {
               // since the rank of s1 is more than rank of s2, s1 will become the parent of s2
                parent[s2root] = s1root;
                // update rank of s1 now
                rank[s1root] += rank[s2root];
           } else {
                parent[s1root] = s2root;
                rank[s2root] += rank[s1root];
           }
       }
   }
};

class Graph {
    // number of vertexes
    int totV;
    // edge list representation
   map<int, pair<int, int> > weightedEdgelist;
    public:
   Graph(int ver):totV(ver) { }
   void addEdge(int a, int b, int w) {
      weightedEdgelist.insert(make_pair(w, make_pair(a,b)));
   }

   // return the minimum weight
   int kruksal_mst() {
       DSU s(totV);
       int ans = 0;
       for (auto wEdge: weightedEdgelist) {
           int w = wEdge.first;
           auto edge = wEdge.second;

           if (s.findSetRoot(edge.first) != s.findSetRoot(edge.second) ) {
               s.union_set(edge.first, edge.second);
               ans += w;
           }
       }
       return ans;
   }
};


int main () {
    Graph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 3, 3);
    g.addEdge(3, 2, 3);
    g.addEdge(2, 0, 2);
    g.addEdge(0, 3, 2);
    g.addEdge(1, 2, 2);

    // createSpanningTree
    std::cout << g.kruksal_mst() << std::endl;

}
