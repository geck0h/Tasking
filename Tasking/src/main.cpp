#include <iostream>

#include "TaskTable.h"
#include "GLFW/glfw3.h"

int main()
{
	TaskTable tasktable(7);
	tasktable.onDay(0).addTask("Task name");
	tasktable.onDay(0).addTask("Task name 2");

	tasktable.onDay(0).tickTask("Task name");

	std::cout << tasktable.onDay(0).checkTask("Task name") << std::endl;
    
	//tasktable.onDay(Day::MONDAY).removeTask("Task name");

	std::cout << tasktable.onDay(0).viewPercentFinished();

	std::cin.get();
}