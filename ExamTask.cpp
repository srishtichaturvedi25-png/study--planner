#include "ExamTask.h"

ExamTask::ExamTask(
    const std::string& name,
    const std::string& subjectName,
    int taskPriority,
    int duration,
    int daysRemaining
)
    : StudyItem(
          name,
          subjectName,
          taskPriority,
          duration,
          daysRemaining
      ) {
}

void ExamTask::displayDetails() const {
    std::cout << "\nTask Type: Exam Revision\n";
    std::cout << "Task Name: " << taskName << '\n';
    std::cout << "Subject: " << subject << '\n';
    std::cout << "Priority: " << priority << "/10\n";
    std::cout << "Estimated Time: "
              << estimatedMinutes << " minutes\n";
    std::cout << "Exam Deadline: "
              << dueInDays << " day(s) remaining\n";
}