#include <iostream>

#include "domain/Task.hpp"

int main(){
    std::cout << " Task Manager App initialized ✅\n";

    Task task(1,"Learn C++", TaskStatus::TODO);

    std::cout << "Task ID: " << task.getId() << "\n";
    std::cout << "Task Name: " << task.getTitle() << "\n";
    std::cout << "Task Status: " << task.getStatus() << "\n";

    task.start();
    std::cout << "Task Status: " << task.getStatus() << "\n";

    task.complete();
    std::cout << "Task Status: " << task.getStatus() << "\n";

    try{
        task.complete();
    }catch(const std::exception& e){
        std::cout << e.what() << "\n";
    }

    return 0;
}
