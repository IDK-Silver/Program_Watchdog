//
// Created by idk on 2023/1/6.
//

#include "PID_Controller.h"

void PID_Controller::SetPID(int pid) {
    this->pid_value = pid;
    this->h_process = OpenProcess(PROCESS_TERMINATE, FALSE, this->pid_value);
}

bool PID_Controller::Terminate() {
    TerminateProcess(this->h_process, 0);
    return false;
}

bool PID_Controller::IsProcess() {
    HANDLE process = OpenProcess(SYNCHRONIZE, FALSE, this->pid_value);
    DWORD ret = WaitForSingleObject(process, 0);
    CloseHandle(process);
    return ret == WAIT_TIMEOUT;
}

PID_Controller::~PID_Controller() {
    CloseHandle(h_process);
}


