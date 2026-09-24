#include "domain/Task.hpp"
#include <stdexcept>
#include <utility>

// parameterizes constructor
Task::Task(
    std::uint64_t id,
    std::string title,
    TaskStatus status
): id(id), title(std::move(title)), status(status){}

//=========  Getter methods start =========
std::uint64_t Task::getId() const{
    return id;
}

const std::string& Task::getTitle() const{
    return title;
}

TaskStatus Task::getStatus() const{
    return status;
}

//========== Getter methods end ==========

// function to change the task status to IN_PROGRESS
void Task::start(){
    if(status == TaskStatus::COMPLETED){
        throw std::runtime_error("Task Already Completed");
    }

    if(status == TaskStatus::IN_PROGRESS){
        throw std::runtime_error("Task Already In Progress");
    }

    status = TaskStatus::IN_PROGRESS;
}

// function to change the status to COMPLETED
void Task::complete(){
    if(status == TaskStatus::COMPLETED){
        throw std::runtime_error("Task Already Completed");
    }

    status = TaskStatus::COMPLETED;
}
