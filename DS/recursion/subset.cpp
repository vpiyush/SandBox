// generate all possible subset of a given string 2 raiseto n ., possiblities
#include <iostream>
#include <vector>

using namespace std;

void generateSubset(vector<string>& subsetVec, string input) {
    if(input.empty()) {
        // process subset
        std::string mysubSet;
        for (auto i: subsetVec) {
            mysubSet += i;
        }
        cout << mysubSet << endl;
        return;
    }

       // include element one in subset
        std::string temp = input.substr(0,1);
        subsetVec.push_back(temp);
        generateSubset(subsetVec, input.substr(1));

       // don't include first element and generate
        subsetVec.pop_back();
        generateSubset(subsetVec, input.substr(1));

}
int main () {

    string input;
    cin >> input;

    std::vector<string> subsetVec;
    generateSubset(subsetVec, input);
}
