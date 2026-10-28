#ifndef EXAM_TASK_H
#define EXAM_TASK_H

#include "StudyItem.h"

class ExamTask : public StudyItem {
public:
    ExamTask(
        const std::string& name,
        const std::string& subjectName,
        int taskPriority,
        int duration,
        int daysRemaining
    );

    void displayDetails() const override;
};

#endif
