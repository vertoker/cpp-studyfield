// Typical simple logger with "Meyers singleton"
// Thread-safe and easy to use

#include <string>
#include <fstream>
#include <iostream>
#include <mutex>

class Logger
{
public:
    static Logger& getInstance(const std::string& filepath = "log.txt")
    {
        static Logger instance(filepath);
        return instance;
    }

    void log(const std::string& message)
    {
        std::lock_guard<std::mutex> lock(mtx);
        out << message << std::endl;
    }

private:
    explicit Logger(const std::string& filepath) : out(filepath, std::ios::app)
    {
        if (!out.is_open())
            throw std::runtime_error("Can't open log file: " + filepath);
    }
    ~Logger()
    {
        out.close();
    }

    std::ofstream out;
    std::mutex mtx;
};

int main()
{
    Logger::getInstance().log("log 1");
    Logger::getInstance().log("log 2");
}