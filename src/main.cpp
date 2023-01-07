#include <iostream>
#include <PID_Controller/PID_Controller.h>

int main(int argc, char *argv[])
{
    int count;

    // Display each command-line argument.
    std::cout << "\nCommand-line arguments:\n";
    for( count = 0; count < argc; count++ )
        std::cout << "  argv[" << count << "]   "
             << argv[count] << "\n";

//    PID_Controller process_watchdog;
//    process_watchdog.SetPID(22584);
//
//    if (process_watchdog.IsProcess())
//    {
//        std::cout << "Terminate Process";
//        process_watchdog.Terminate();
//    }
//    else
//    {
//        std::cout << "Can't Terminate Process";
//    }
    return 0;
}