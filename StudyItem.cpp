#include "StudyItem.h"

StudyItem::StudyItem(
    const std::string& name,
    const std::string& subjectName,
    int taskPriority,
    int duration,
    int daysRemaining
)
    : taskName(name),
      subject(subjectName),
      priority(taskPriority),
      estimatedMinutes(duration),
      dueInDays(daysRemaining) {
}

int StudyItem::getPriority() const {
    return priority;
}

int StudyItem::getEstimatedMinutes() const {
    return estimatedMinutes;
}

int StudyItem::getDueInDays() const {
    return dueInDays;
}

const std::string& StudyItem::getTaskName() const {
    return taskName;
}

const std::string& StudyItem::getSubject() const {
    return subject;
}

bool StudyItem::operator<(const StudyItem& other) const {
    return priority < other.priority;
}