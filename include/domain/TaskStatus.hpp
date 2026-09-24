#pragma once
#include <ostream>

enum class TaskStatus{
    TODO,
    IN_PROGRESS,
    COMPLETED
};

std::ostream& operator<<(std::ostream& os, const TaskStatus& status);
