#pragma once

#include <vector>
#include <string>
#include <cstdint>

enum class Day {
    Monday = 0,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

struct Task {
    std::string taskName;
    bool isCompleted;
};

///////////////////////////////////

class TaskDay {
public:
    TaskDay() = default;

    void AddTask(const std::string& taskName);
    void RemoveTask(const std::string& taskName);
    void TickTask(const std::string& taskName);
    bool CheckTask(const std::string& taskName) const;

    float ViewPercentFinished() const;
private:
    std::vector<Task> m_tasks;
};

///////////////////////////////////

class TaskTable {
public:
    TaskTable() = delete;
    TaskTable(uint64_t days = 7)
        : m_taskDays(days) {}

    [[nodiscard]] TaskDay& OnDay(Day day);
    [[nodiscard]] TaskDay& OnDay(unsigned int day);

private:
    std::vector<TaskDay> m_taskDays;
};

