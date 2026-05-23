#include "TaskTable.h"

void TaskDay::addTask(const std::string& taskName) 
{
    tasks.push_back({ taskName, false });
}

void TaskDay::removeTask(const std::string& taskName) 
{
    for (int i = 0; i < tasks.size(); i++)
    {
        if (taskName == tasks[i]._taskName)
        {
            tasks.erase(tasks.begin() + i);
            return;
        }
    }
}

void TaskDay::tickTask(const std::string& taskName) 
{
    for (Task& task : tasks)
    {
        if (task._taskName == taskName && !task._isCompleted)
        {
            task._isCompleted = true;
            return;
        }
    }
}

bool TaskDay::checkTask(const std::string& taskName) const
{
    for (const Task& task : tasks)
    {
        if (task._taskName == taskName)
            return task._isCompleted;
    }
    return false;
}

float TaskDay::viewPercentFinished() const
{
    int totalTasks = 0;
    int finishedTasks = 0;
    for (const Task& task : tasks)
    {
        totalTasks++;
        if (task._isCompleted)
            finishedTasks++;
    }
    return static_cast<float>(finishedTasks) / static_cast<float>(totalTasks) * 100.0f;
}

///////////////////////////////////

[[nodiscard]] TaskDay& TaskTable::onDay(Day day)
{
    return m_taskDays[static_cast<int>(day)];
}

[[nodiscard]] TaskDay& TaskTable::onDay(unsigned int day) 
{
    return m_taskDays[day];
}


