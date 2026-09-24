#pragma once

#include <string>
#include <cstdint>

#include "domain/TaskStatus.hpp"

class Task{
    private:
            std::uint64_t id;
            std::string title;
            TaskStatus status;

    public:
            // Constructor
            Task(std::uint64_t id, std::string title, TaskStatus status = TaskStatus::TODO);

            // getter methods
            std::uint64_t getId() const;
            const std::string& getTitle() const;   
            TaskStatus getStatus() const;

            // Task Operations
            void start();
            void complete();
};
