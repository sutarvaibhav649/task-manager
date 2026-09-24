#pragma once

#include "domain/Task.hpp"

#include <cstdint>
#include <optional>
#include <vector>
#include <string>

class ITaskRepository{
    public:

        virtual ~ITaskRepository() = default;

        virtual Task create(std::string title) = 0;
        
        virtual std::optional<Task> findById(std::uint64_t id) const = 0;
        
        virtual std::vector<Task> findAll() const = 0;

        virtual bool remove(std::uint64_t id) = 0;

        virtual bool update(const Task& task) = 0;
};
