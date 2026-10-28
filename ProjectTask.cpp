#include "ProjectTask.h"

ProjectTask::ProjectTask(
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

void ProjectTask::displayDetails() const {
    std::cout << "\nTask Type: Project\n";
    std::cout << "Task Name: " << taskName << '\n';
    std::cout << "Subject: " << subject << '\n';
    std::cout << "Priority: " << priority << "/10\n";
    std::cout << "Estimated Time: "
              << estimatedMinutes << " minutes\n";
    std::cout << "Project Deadline: "
              << dueInDays << " day(s) remaining\n";
}