#include "SmartScheduler.h"
#include "SchedulingAlgorithms.h"
#include <iostream>

void SmartScheduler::generateSchedule(
    const std::vector<std::shared_ptr<StudyItem>>& tasks,
    int availableMinutes
) {
    scheduledTasks = SchedulingAlgorithms::greedySchedule(
        tasks,
        availableMinutes
    );

    std::cout << "Schedule generated successfully!\n";
}

void SmartScheduler::displaySchedule() const {
    if (scheduledTasks.empty()) {
        std::cout << "No tasks scheduled.\n";
        return;
    }

    int totalMinutes = 0;

    std::cout << "\n===== SMART STUDY SCHEDULE =====\n";

    for (std::size_t i = 0; i < scheduledTasks.size(); ++i) {
        std::cout << "\nScheduled Task " << i + 1 << ":\n";

        scheduledTasks[i]->displayDetails();

        totalMinutes += scheduledTasks[i]->getEstimatedMinutes();
    }

    std::cout << "\nTotal Study Time: "
              << totalMinutes << " minutes\n";
}

int SmartScheduler::getScheduledTaskCount() const {
    return static_cast<int>(scheduledTasks.size());
}