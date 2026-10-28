#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include <vector>
#include <memory>
#include "StudyItem.h"

class TaskManager {
private:
    std::vector<std::shared_ptr<StudyItem>> tasks;

public:
    bool addTask(const std::shared_ptr<StudyItem>& task);

    void displayTasks() const;

    int getTaskCount() const;

    std::vector<std::shared_ptr<StudyItem>> getTasks() const;
};

#endif