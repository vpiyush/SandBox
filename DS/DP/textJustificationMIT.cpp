#include<iostream>
#include<vector>
#include<sstream>
using namespace std;


int badness() {

}
int main () {
    int pageWidth;
    std::string wordLine;
    cout << "provide pagewidth" << endl;
    cin >> pageWidth;
    cout << "provide a paragraph" << endl;
    getline(cin, wordLine);

    std::istringstream iss(wordLine);
    std::vector<std::string> wordVector(std::istream_iterator<std::string>{iss},
                                 std::istream_iterator<std::string>());
    for(auto str : wordVector) {
        //badness(str,);
    }


}
