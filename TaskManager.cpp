#include "TaskManager.h"
#include <iostream>

bool TaskManager::addTask(const std::shared_ptr<StudyItem>& task) {
    if (!task) {
        std::cout << "Invalid task. Task not added.\n";
        return false;
    }

    tasks.push_back(task);

    std::cout << "Task added successfully!\n";
    return true;
}

void TaskManager::displayTasks() const {
    if (tasks.empty()) {
        std::cout << "No tasks available.\n";
        return;
    }

    for (std::size_t i = 0; i < tasks.size(); ++i) {
        std::cout << "\nTask " << i + 1 << ":\n";
        tasks[i]->displayDetails();
    }
}

int TaskManager::getTaskCount() const {
    return static_cast<int>(tasks.size());
}

std::vector<std::shared_ptr<StudyItem>> TaskManager::getTasks() const {
    return tasks;
}