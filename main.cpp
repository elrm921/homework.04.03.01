#include <iostream>
#include <fstream>

class LogCommand {
public:
    LogCommand() = default;
    virtual ~LogCommand() = default;
    virtual void print(const std::string& message) = 0;
};

class LogConsole : public LogCommand
{
public:
    LogConsole() {}
    void print(const std::string& message) override
    {
        std::cout << message << std::endl;
    }
private:
    std::ostream* out_;
};

class LogFile : public LogCommand
{
public:
    LogFile(const std::string path) {
        out_ = new std::ofstream(path);
    }
    void print(const std::string& message) override
    {
        *(out_) << message << std::endl;
    }
private:
    std::ofstream* out_;
};

void print(LogCommand& cmd, const std::string& message)
{
    cmd.print(message);
};

int main()
{
    auto console_logger = LogConsole();
    auto file_logger = LogFile("log.txt");

    print(console_logger, "Logging in console");
    print(file_logger, "Logging in file");

    return 0;
}