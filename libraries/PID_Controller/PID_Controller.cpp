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
    this->h_process = OpenProcess(PROCESS_TERMINATE, FALSE, this->pid_value);
    if (this->h_process == nullptr)
        return false;
    return true;
}


