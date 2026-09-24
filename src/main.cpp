#include "domain/Task.hpp"
#include "repository/InMemoryTaskRepository.hpp"

#include <iostream>

int main()
{
    std::cout << "Task Manager App initialized\n";

    InMemoryTaskRepository repository;

    // CREATE
    repository.create("Learn C++");
    repository.create("Learn Java");
    repository.create("Learn CMake");

    // FIND ALL
    std::cout << "\nAll Tasks:\n";

    for (const Task& task : repository.findAll())
    {
        std::cout
            << task.getId()
            << " -- "
            << task.getTitle()
            << " -- "
            << task.getStatus()
            << '\n';
    }

    // FIND BY ID
    auto task = repository.findById(1);

    if (task)
    {
        std::cout << "\nFound Task:\n";
        std::cout
            << task->getId()
            << " -- "
            << task->getTitle()
            << " -- "
            << task->getStatus()
            << '\n';

        // MODIFY LOCAL COPY
        task->start();
        task->complete();

        // UPDATE REPOSITORY
        if (repository.update(*task))
        {
            std::cout << "Task updated successfully\n";
        }
    }
    else
    {
        std::cout << "Task not found\n";
    }

    // VERIFY UPDATE
    auto updatedTask = repository.findById(1);

    if (updatedTask)
    {
        std::cout << "\nAfter Update:\n";
        std::cout
            << updatedTask->getId()
            << " -- "
            << updatedTask->getTitle()
            << " -- "
            << updatedTask->getStatus()
            << '\n';
    }

    // REMOVE
    if (repository.remove(1))
    {
        std::cout << "\nTask removed successfully\n";
    }

    // VERIFY REMOVE
    auto deletedTask = repository.findById(1);

    if (!deletedTask)
    {
        std::cout << "Confirmed: Task no longer exists\n";
    }

    return 0;
}
