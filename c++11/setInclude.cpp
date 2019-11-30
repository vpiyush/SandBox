#include <iostream>
#include <algorithm>
#include <cctype>
#include <set>
using namespace std;


bool isSubSetOfFirst(std::set<int> v1, std::set<int> v2) {
	bool ret =	std::includes(v1.begin(), v1.end(), v2.begin(), v2.end());
    if (ret && (v1.size() != v2.size())) {
        return true;
    }
    return false;
}


bool isSuperSetOfFirst(std::set<int> v1, std::set<int> v2) {
	bool ret =	std::includes(v2.begin(), v2.end(), v1.begin(), v1.end());
    if (ret && (v1.size() != v2.size())) {
        return true;
    }
    return false;
}

bool isDisjoint(std::set<int> v1, std::set<int> v2) {
    bool ret =	std::includes(v1.begin(), v1.end(), v2.begin(), v2.end());
    if (!ret) {
        if(!std::includes(v2.begin(), v2.end(), v1.begin(), v1.end())) return true;
    }
    return false;
}

int main()
{
	std::set<int> v1 {1, 5};
	std::set<int> v2 {1, 2};

    for (auto i : v1) std::cout << i  <<  " " ;
    std::cout << endl;
    for (auto i : v2) std::cout << i  <<  " " ;
    std::cout << endl;

	std::cout << ": " << isSubSetOfFirst(v1, v2) << '\n';
	std::cout << ": " << isSuperSetOfFirst(v1, v2) << '\n';
	std::cout << ": " << isDisjoint(v1, v2) << endl;

	return 0;

}
