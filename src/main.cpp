#include "input_handler.cpp"

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        std::ostringstream oss;
        for (int i = 1; i < argc; ++i)
        {
            oss << argv[i] << " ";
        }
        std::string command = oss.str();
        process_input(command);
    }
    else
    {
        while (true)
        {
            std::cout << "Enter shape (or 'exit'): ";
            std::string line;
            std::getline(std::cin, line);

            if (line == "exit" || line == "q")
                break;
            process_input(line);
        }
    }
    return 0;
}
