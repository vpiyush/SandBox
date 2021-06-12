#include<iostream>
#include<map>
#include<vector>
#include<queue>
using namespace std;


// find the minimum number of dice throw required to reach from start to end in a snake/ladder game
// (shortest path problem)
std::map<int, vector<int> > graph;

void addEdge(int x, int y) {
    graph[x].push_back(y);
}

void BFS(int src) {

    int visited[50] = {INT_MAX};
    for (int i =0; i <= 36; i ++) {
        visited[i] = INT_MAX;
    }
    visited[src] = 0;

    std::queue<int> q;
    q.push(src);

    while (!q.empty()) {
        auto node = q.front();
        q.pop();

        for (auto nbr : graph[node]) {
            if(visited[nbr] == INT_MAX) {
                q.push(nbr);
                visited[nbr] = visited[node] + 1;
            }
        }
    }

    for (int i =0; i <= 36; i ++) {
    cout << "total distance " << visited[i] << endl;
    }


}

int main () {
    // add path for all snakes and ladders
    int board[50] = {};
    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = 10;
    board[32] = -2;
    board[34] = -22;


    for (int i=0; i<=36; i++) {
        for (int dice=1; dice<=6; dice++) {
            int j = i + dice;
            j += board[j];
            if (j <= 36) {
                addEdge(i,j);
            }
        }
    }
    BFS(0);
}
