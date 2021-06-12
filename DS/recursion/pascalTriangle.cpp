#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    static vector<vector<int>> generate(int numRows) {
        vector<vector<int>> myVecArray;
        if (numRows == 1) {
            myVecArray.push_back({1});
            return myVecArray;
        }
        myVecArray = generate(numRows-1);
        if (numRows > 1) {
            vector <int> myNewVec;
            myNewVec.push_back({1});
            for (int i=0; i <numRows-2; i++) {
                myNewVec.push_back(myVecArray[numRows-2][i] + myVecArray[numRows-2][i+1]);
            }
           myNewVec.push_back({1});
           myVecArray.push_back(myNewVec);
        }


        return myVecArray;

    }
};

int main () {
    vector<vector<int>> myVecArray = Solution::generate(5);
    for (auto vec : myVecArray) {
        for (int i : vec) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
