//
// Created by idk on 2023/1/7.
//

#ifndef PROGRAM_WATCHDOG_ARGUMENTSDECODE_H
#define PROGRAM_WATCHDOG_ARGUMENTSDECODE_H

#include <PID_Controller/PID_Controller.h>
#include <string>
#include <memory>
#include <iostream>

namespace ArgumentsDecode {
    bool decode(const std::shared_ptr<PID_Controller_Data>& data, const std::vector<std::string>& arguments);
    void print_data(const PID_Controller_Data& data);
};


#endif //PROGRAM_WATCHDOG_ARGUMENTSDECODE_H
