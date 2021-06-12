
#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<list>
using namespace std;
class Graph {
    // number of vertexes
    int totV;
    // edge list representation
   list<pair<int, int> > edgelist;
    public:
   Graph(int ver):totV(ver) { }
   void addEdge(int a, int b) {
       edgelist.push_back(make_pair(a,b));
   }


   // find set root of the elem
   int findSetRoot(int elem, int parent[]) {
       if (parent[elem] == -1) {
           return elem;
       }
       // path comprestion optimization
       return parent[elem] = findSetRoot(parent[elem], parent);

   }

   // find union
   // union by rank => this will ensure connectivity happens based on the size of the sets.
   // this would help in creating perfect flattened out tree with the help of path compression algorithm
   void union_set(int x, int y, int parent[], int rank[]) {
       int s1root = findSetRoot(x, parent);
       int s2root = findSetRoot(y, parent);

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
   bool containsCyle() {
       // DSU => (disjoint set/union) logic to detect the cycle
       int *parent = new int[totV];
       int *rank = new int[totV];

       for (int i=0; i < totV; i++) {
           parent[i] = -1;
       }

       for (auto edge: edgelist){
           int i = edge.first;
           int j = edge.second;

           int s1 = findSetRoot(i, parent);
           int s2 = findSetRoot(j, parent);

           cout << s1 << " " << s2 << endl;
           if (s1 != s2) {
               // this union will connect the elements in the parent array if the edges are connectecd
               union_set(s1, s2, parent, rank);
           } else {
               return true;
           }
       }
       return false;
   }
};


int main(){
    //each vertex will be the key
    //each key will have list of edges connected to it
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,0);

    cout << g.containsCyle() << endl;

    return 0;
}
