#ifndef PROJECT_TASK_H
#define PROJECT_TASK_H

#include "StudyItem.h"

class ProjectTask : public StudyItem {
public:
    ProjectTask(
        const std::string& name,
        const std::string& subjectName,
        int taskPriority,
        int duration,
        int daysRemaining
    );

    void displayDetails() const override;
};

#endif