#include <utility>

#include "repository/InMemoryTaskRepository.hpp"

InMemoryTaskRepository::InMemoryTaskRepository(): nextId(1){}

Task InMemoryTaskRepository::create(
    std::string title
){
    Task task(nextId++, std::move(title));

    tasks.push_back(task);

    return task;
}


// returns task by id
std::optional<Task> InMemoryTaskRepository::findById(
    std::uint64_t id
) const {
    for( const Task& task : tasks){
        if(task.getId() == id){
            return task;
        }
    }

    return std::nullopt;
}

//returns all the tasks
std::vector<Task> InMemoryTaskRepository::findAll() const{
    return tasks;
}

//remove the task
bool InMemoryTaskRepository::remove(
    std::uint64_t id
){
    for(auto it = tasks.begin(); it != tasks.end(); ++it){
        if(it->getId() == id){
            tasks.erase(it);
            return true;
        }
    }

    return false;
}

// update task
bool InMemoryTaskRepository::update(
    const Task& task
){
    for(Task& existingTask : tasks){
        if(existingTask.getId() == task.getId()){
            existingTask = task;
            return true;
        }
    }
    return false;
}
