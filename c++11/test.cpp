#include <iostream>
using namespace std;

int main() {
    uint8_t t = 255;
    int i = t >> 8 & 0xFF;
    std::cout << i <<endl;
}
