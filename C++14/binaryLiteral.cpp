#include<iostream>
using namespace std;

int main () {
    int x= 0b101;
        switch (x)
        {
            case 0B100:
                //...
                break;
            case 0B101:
                std::cout << x << endl;
                //...
                break;
                //...
        }
    return 0;
}

