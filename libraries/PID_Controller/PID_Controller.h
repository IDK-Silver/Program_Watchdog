//
// Created by idk on 2023/1/6.
//

#ifndef PROGRAM_WATCHDOG_PID_CONTROLLER_H
#define PROGRAM_WATCHDOG_PID_CONTROLLER_H

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <processthreadsapi.h>
#include <string>
#include <vector>

struct PID_Controller_Data {
    std::string program_path;
    int main_program_pid;
    std::vector<int> watch_pids;
};

class PID_Controller {
public:
    PID_Controller() = default;
    ~PID_Controller();
    void SetPID(int pid);
    bool Terminate();
    bool IsProcess();
private:
    DWORD pid_value{};
    HANDLE h_process = nullptr;
};


#endif //PROGRAM_WATCHDOG_PID_CONTROLLER_H
