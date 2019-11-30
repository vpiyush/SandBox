#include <iostream>
#include <thread>
#include <chrono>

void foo()
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

int main()
{
    std::thread *t;
    std::cout << "before starting, joinable: " << std::boolalpha << t.joinable()
              << '\n';

    t = new std::thread(foo);
    std::cout << "after starting, joinable: " << t.joinable()
              << '\n';

	sleep(2);
    std::cout << "after joining, joinable: " << t.joinable()
              << '\n';
   return 0;
}
