#include "domain/TaskStatus.hpp"

std::ostream& operator<<(std::ostream& os, const TaskStatus& status){
    switch(status){
        case TaskStatus::TODO: return  os << "TODO";
        case TaskStatus::IN_PROGRESS: return os << "IN_PROGRESS";
        case TaskStatus::COMPLETED: return os << "COMPLETED";
    }

    return os << "UNKNOWN";
}
