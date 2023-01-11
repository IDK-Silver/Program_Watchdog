#include <PID_Controller/PID_Controller.h>
#include <ArgumentsDecode/ArgumentsDecode.h>
#include <string>
#include <vector>
#include <memory>
#include <thread>
#include <chrono>

int main(int argc, char *argv[])
{
    /* the program arguments */
    std::vector<std::string> arguments;

    /* the pid data */
    auto data = std::make_shared<PID_Controller_Data>();

    /* the controller */
    PID_Controller controller;

    /* copy argv to arguments */
    for (int count = 0; count < argc; count++)
        arguments.emplace_back(argv[count]);

    /* decode the arguments */
    ArgumentsDecode::decode(data, arguments);

    /* set the main program pid */
    controller.SetPID(data->main_program_pid);

    ArgumentsDecode::print_data(*data);

    /* sleep program unit the main program is not running */
    while (controller.IsProcess())
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    /* print message */
    std::cout << "The main program is not running\n";

    /* terminate all watch program */
    for (const auto& pid : data->watch_pids)
    {
        std::cout << "terminate pid : " << pid << "\n";
        PID_Controller terminate_controller;
        terminate_controller.SetPID(pid);
        terminate_controller.Terminate();
    }

    return 0;
}