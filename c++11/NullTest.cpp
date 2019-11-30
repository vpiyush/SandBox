#include <iostream>
using namespace std;

void func(const std::string& id) {
//    cout << id << endl;
}
int main () {
    try {
    const string &str = NULL;
    } catch (std::exception &ex) {
        cout << ex.what() << endl;
    } catch(...) {
    }
  //  func(NULL);
}
