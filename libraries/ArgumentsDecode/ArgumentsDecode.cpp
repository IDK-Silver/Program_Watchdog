//
// Created by idk on 2023/1/7.
//

#include "ArgumentsDecode.h"

bool ArgumentsDecode::decode(const std::shared_ptr<PID_Controller_Data>& data, const std::vector<std::string>& arguments) {

    /* if arguments is none is program is not arguments */
    if (arguments.empty())
        return false;

    /* to read each argument's index */
    int arguments_index = 0;
    
    /* read this program path */
    data->program_path = arguments.at(arguments_index++);

    /* read the option in arguments */
    while (arguments_index < arguments.size())
    {
        const std::string& argument = arguments.at(arguments_index++);

        auto is_num = [=](const std::string & input_string) {

            for (const auto& word : input_string)
                if (isdigit(word) == false)
                    return false;
            return true;
        };

        /* if argument is "-m" next arguments is the pid */
        if (argument == "-m")
        {
            /* get the pid number strint */
            const std::string& main_pid_str = arguments.at(arguments_index++);

            /* check the pid is a number type */
            if (!is_num(main_pid_str))
            {
                std::cerr << "The main program pid arguments (-m) must be a number\n";
                return false;
            }

            /* conversion string to int the value then, will storage to data */
            data->main_program_pid = std::stoi(main_pid_str);
        }

        /* if argument is  "-w" unit the another argument (ex -m ..), the value is the need watch */
        if (argument == "-w")
        {
            do
            {
                /* get the pid number strint */
                const std::string& watch_pid_string = arguments.at(arguments_index++);

                /* check the pid is a number type */
                if (!is_num(watch_pid_string))
                {
                    /* is another argument */
                    if (watch_pid_string.at(0) == '-')
                        break;

                    std::cerr << "The watch program pid arguments (-w) must be a number\n";
                    return false;
                }

                /* push the data */
                data->watch_pids.push_back(std::stoi(watch_pid_string));

            } while (arguments_index < arguments.size());
        }

    }
    return true;
}

void ArgumentsDecode::print_data(const PID_Controller_Data &data) {
    std::cout << "This Program Path : " << data.program_path << "\n";
    std::cout << "The main PID      : " << data.main_program_pid << "\n";
    std::cout << "The Watch PIDs    : ";
    for (const auto& pid : data.watch_pids)
        std::cout << pid << " ";
    std::cout << "\n";
}
