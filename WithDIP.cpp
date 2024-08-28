#include <iostream>
#include <string>
#include <typeinfo>


//Abstract logger functions like an (interface)
class Logger{
public:
    virtual void log(const std::string&message) = 0; // virtual fuction, to be implemented
    
    virtual ~Logger() = default; // Virtual destructor
};

//Example file logger
class FileLogger : public Logger{
public:
    void log(const std::string& message){
        std::cout << "Logging to a file: " << message << std::endl;
    }
};

//Added DB Logger
class DatabaseLogger : public Logger{
public: 
    void log(const std::string& message) override{
        std::cout << "Logging to a database: " << message <<std::endl;
    }
};

//Can add new logger without changing the ..

// User service depends on the file logger
class UserService{
private:
/**
 * Depends on Logger "interface" instead of File or  DB logger
 * meaning this code does not change however many Loggers
 * we wish to implement.
 */
    Logger& log;

public:
    //Constructor Injection
    UserService(Logger& logger) : log(logger){
        //Constructed obj has access to the logger 
    }

    void createUser(const std::string& username){
        // Business logic creates user
        log.log("User created: " + username);
    }
    void swapLogger(Logger& logger){
        log = logger;
        std::cout << "Logger swapped" << std::endl;
    }
    void reportLogger(){
        std::cout << "Logger type: " << typeid(log).name() << std::endl <<std::endl;
    }
};

//User service is tightly coupled in this example.
int main(){
    FileLogger fileLogger;
    UserService US(fileLogger);
    US.createUser("PhilBat");
    US.reportLogger();
    //Here we can switch to a different logger
    DatabaseLogger dbLogger;
    UserService userWithDbLogger(dbLogger);
    userWithDbLogger.createUser("BrittnyRob");
    userWithDbLogger.reportLogger();

    US.swapLogger(dbLogger);
    US.reportLogger();

    //Slightly more complicated code, trades for more extensibility.
    //Dont feel like demangling typeid
    return 0;
}

