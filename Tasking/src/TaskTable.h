#pragma once

#include <vector>
#include <string>
#include <cstdint>

enum class Day {
    MONDAY = 0,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};

struct Task {
    std::string _taskName;
    bool _isCompleted;
};

///////////////////////////////////

class TaskDay {
public:
    TaskDay() = default;

    void addTask(const std::string& taskName);
    void removeTask(const std::string& taskName);
    void tickTask(const std::string& taskName);
    bool checkTask(const std::string& taskName) const;

    float viewPercentFinished() const;
private:
    std::vector<Task> tasks;
};

///////////////////////////////////

class TaskTable {
public:
    TaskTable() = delete;
    TaskTable(uint64_t days = 7)
        : m_taskDays(days) {}

    [[nodiscard]] TaskDay& onDay(Day day);
    [[nodiscard]] TaskDay& onDay(unsigned int day);

private:
    std::vector<TaskDay> m_taskDays;
};

