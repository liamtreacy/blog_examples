// Program which logs a random number every 5 seconds to a specified file

#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <chrono>
#include <thread>

const static std::string LOG_PREFIX = "Generated: ";

class Logger
{
    public:
    Logger(const std::string& file_name)
    {
        log_file.open(file_name, std::ios::app);
    }

    ~Logger()
    {
        log_file.close();
    }

    void log(const std::string& log_line)
    {
        log_file << log_line << std::endl;
    }

    private:
    std::ofstream log_file;
};

int generateRandomNumber(int max, int min)
{
    int range = max - min + 1;
    return rand() % range + min;
}

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        std::cout << "Error, usage: <exe> <log_file>\n";
        return 1;
    }

    Logger logger(argv[1]);

    while(1)
    {
        logger.log(LOG_PREFIX + std::to_string(generateRandomNumber(10,1)));
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }

    return 0;
}