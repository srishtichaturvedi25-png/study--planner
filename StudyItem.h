#ifndef STUDY_ITEM_H
#define STUDY_ITEM_H

#include <iostream>
#include <string>

class StudyItem {
protected:
    std::string taskName;
    std::string subject;
    int priority;
    int estimatedMinutes;
    int dueInDays;

public:
    StudyItem(
        const std::string& name,
        const std::string& subjectName,
        int taskPriority,
        int duration,
        int daysRemaining
    );

    virtual ~StudyItem() = default;

    virtual void displayDetails() const = 0;

    int getPriority() const;
    int getEstimatedMinutes() const;
    int getDueInDays() const;

    const std::string& getTaskName() const;
    const std::string& getSubject() const;

    bool operator<(const StudyItem& other) const;
};

#endif