#include <iostream>
#include <thread>
#include <mutex>
#include <future>

using namespace std;

std::mutex mtx;
/// initializer
void myFunc(int& k) {
    int i = 0;
    {
    while(k == 10) {}
    std::unique_lock<std::mutex> lk(mtx);
    cout << "thred func" <<  std::to_string(++(k)) << endl;
    }

}

void myFunc2(int& k) {
    int i = 0;
    {
    std::unique_lock<std::mutex> lk(mtx);
    cout << "thred func 1" <<  std::to_string(++(k)) << endl;
    }
}
int  myFuncAsync() {
    return 10;
}
int main () {
    int j = 10;
    int *k = new int();
    *k = 10;
    std::thread t1(myFunc, std::ref(j));
    cout << "main thread " <<  std::to_string(j) << endl;
    std::thread t2(myFunc, std::ref(j));
    cout << "main thread" <<  std::to_string(j) << endl;

    std::future<int> fut = std::async(myFuncAsync);
    cout << "future value " << std::to_string(fut.get()) << endl;


    t1.join();
    t2.join();

    return 0;
}

