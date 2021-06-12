
#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<list>
using namespace std;


int R,C;
// x axis
int dx[4] = {0,-1, 1, 0};
// y axis
int dy[4] = {1,0, 0, -1};
void floodfill( char mat[][50], int i, int j, char ch, char color) {
    // base condtion - we want to make sure we don't cross matric bounds
    if (i<0 or j <0 or i>=R or j>=C)
        return;

    // flood boundar condition - the boudary of area to be flooded is identified with char ch
    if (mat[i][j] != ch) {
        return;
    }

    mat[i][j] = color;
    // we need to now start calling in all four directions

    for (int k = 0; k <4; k++)
        floodfill(mat, i+dx[k], i+dy[k], ch, color);

}


int main() {
    cin >> R >>C;

    char input[15][50];

    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            cin >> input[i][j];
        }
    }
    floodfill(&input[0], 0, 0, 'a', 'R');
    cout << "floodfill done" << endl;
}
