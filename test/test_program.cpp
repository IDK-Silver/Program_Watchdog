//
// Created by idk on 2023/1/11.
//
#include <thread>
#include <chrono>

int main()
{
    printf("PID : %d", _getpid());

    while (true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    return 0;
}
