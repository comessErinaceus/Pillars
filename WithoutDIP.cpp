#include <iostream>
#include <string>

//Example file logger
class FileLogger{
public:
    void log(const std::string& message){
        std::cout << "Logging to a file: " << message << std::endl;
    }
};

// User service depends on the file logger
class UserService{
private:
    FileLogger log; // Directly depends on ^^ FileLogger

public:
    void createUser(const std::string& username){
        // Business logic creates user
        log.log("User created: " + username);
    }
};

int main(){
    UserService US;

    US.createUser("PhilBat");
    return 0;
}

