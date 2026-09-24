#pragma once

#include "repository/ITaskRepository.hpp"

#include <cstdint>
#include <optional>
#include <vector>
#include <string>


class InMemoryTaskRepository : public ITaskRepository{
    private:
        std::vector<Task> tasks;
        std::uint64_t nextId;

    public:
        //Default constructor
        InMemoryTaskRepository();

        // override all the methods from ITaskRepository
        Task create(std::string title) override;

        std::optional<Task> findById(std::uint64_t id) const override;

        std::vector<Task> findAll() const override;

        bool remove(std::uint64_t id) override;

        bool update(const Task& task) override;
};
