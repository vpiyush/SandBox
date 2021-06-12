#include <iostream>
#include <list>
#include <queue>

using namespace std;


class Graph {
    // number of vertexes
    int totV;
    // pointer to an array containing adjency list
   list<int> *adj;
    public:
   Graph(int ver):totV(ver) {
       adj = new std::list<int>[totV];
   }
   void addEdge(int a, int b) {
       adj[a].push_back(b);
       adj[b].push_back(a);
   }

   void BFS(int start) {

       // mark all nodes as not visited for now
       bool *visited = new bool[totV];
       for(int i =0; i <= totV; i++)
           visited[i] = false;

       // mark the current node as visited
       visited[start] = true;

       // create a queue for BFS
       queue<int> q;
       q.push(start);

       while (!q.empty()) {
           start = q.front();
           cout << start << " ";
           q.pop();

           for(int ver : adj[start]) {
               if(!visited[ver]) {
                   visited[ver] = true;
                   q.push(ver);
               }
           }
       }
        cout << endl;

   }

   void DFSUtil(int start, bool visited[]) {
       // mark the current node as visited
       visited[start] = true;
       cout << start << " ";

       for (int i: adj[start]) {
           if (!visited[i]) {
               DFSUtil(i, visited);
           }
       }
   }
   void DFS(int start) {
       // mark all nodes as not visited for now
       bool *visited = new bool[totV];
       for(int i =0; i <= totV; i++)
           visited[i] = false;

       DFSUtil(start, visited);
       cout << endl;
   }
};

int main () {
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(2,4);
    g.addEdge(4,3);
    g.addEdge(3,1);
    g.BFS(0);
    g.DFS(0);
    return 0;
}
