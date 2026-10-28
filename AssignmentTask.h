#ifndef ASSIGNMENT_TASK_H
#define ASSIGNMENT_TASK_H

#include "StudyItem.h"

class AssignmentTask : public StudyItem {
public:
    AssignmentTask(
        const std::string& name,
        const std::string& subjectName,
        int taskPriority,
        int duration,
        int daysRemaining
    );

    void displayDetails() const override;
};

#endif