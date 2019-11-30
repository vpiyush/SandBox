//
//  main.cpp
//  STLTest
//
//  Created by piyush vijay on 09/09/19.
//  Copyright © 2019 piyush vijay. All rights reserved.
//

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
class  myObj {
    int i = 10;
public:
    myObj() {
        
    }
    
};

template <typename T>
class myTemplate {
    T t;
public:
    myTemplate(T val):t(val) {
        std::cout << "my Integer" << std::to_string(t) << std::endl;
    }
};

using namespace std;
int main(int argc, const char * argv[]) {
    
    std::unique_ptr<int> intPointer = std::make_unique<int>(10);
    std::shared_ptr<int> makeShared = std::make_shared<int>(10);
   // std::weak_ptr<int> makeShared = std::make_shared<int>(10);
    
  
    
    std::vector<int> myVec;
    myTemplate<int> myVar(10);
    
    std::map<int,int> myMap;
    myMap[10] = 20;
    
    std::unordered_map<int,int> hashMap;
    hashMap[10] = 20;
    
    myVec.reserve(10);
    myVec.push_back(10);
    myVec.push_back(20);
    myVec.push_back(30);
    myVec.push_back(40);
    
 //  auto it = myVec.begin();
    //myVec.begin();
    //auto it =
    for (auto it= myVec.begin(); it != myVec.end(); ) {
        if(*it == 20) {
            cout << "printing v " << *it << endl;
            it = myVec.erase(it);
            it--;
            // break;
        } else {
            it++;
        }
    }
    
    for(auto& v: myVec) {
      //  v = 12;
        cout << "printing v " << v << endl;
    }
   // myVec.erase();


    std::list<int> myList;
    myList.push_back(10);
    myList.push_back(10);
    myList.push_back(10);
    myList.push_back(10);
    
    

    myTemplate<int> my(10);
    
    myTemplate<double> myDouble(10.0);
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
