#include "TaskTable.h"

void TaskDay::AddTask(const std::string& taskName) 
{
    m_tasks.push_back({ taskName, false });
}

void TaskDay::RemoveTask(const std::string& taskName) 
{
    for (size_t i = 0; i < m_tasks.size(); i++)
    {
        if (taskName == m_tasks[i].taskName)
        {
            m_tasks.erase(m_tasks.begin() + i);
            return;
        }
    }
}

void TaskDay::TickTask(const std::string& taskName) 
{
    for (Task& task : m_tasks)
    {
        if (task.taskName == taskName && !task.isCompleted)
        {
            task.isCompleted = true;
            return;
        }
    }
}

bool TaskDay::CheckTask(const std::string& taskName) const
{
    for (const Task& task : m_tasks)
    {
        if (task.taskName == taskName)
            return task.isCompleted;
    }
    return false;
}

float TaskDay::ViewPercentFinished() const
{
    int finishedTasks = 0;
    for (const Task& task : m_tasks)
    {
        if (task.isCompleted)
            finishedTasks++;
    }
    return static_cast<float>(finishedTasks) / static_cast<float>(m_tasks.size()) * 100.0f;
}

///////////////////////////////////

[[nodiscard]] TaskDay& TaskTable::OnDay(Day day)
{
    return m_taskDays[static_cast<int>(day)];
}

[[nodiscard]] TaskDay& TaskTable::OnDay(unsigned int day) 
{
    return m_taskDays[day];
}


