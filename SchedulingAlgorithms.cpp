#include "SchedulingAlgorithms.h"
#include <algorithm>

int SchedulingAlgorithms::calculatePriority(const StudyItem& task) {
    int priority = task.getPriority();
    int daysRemaining = task.getDueInDays();

    if (daysRemaining <= 1) {
        priority += 5;
    }
    else if (daysRemaining <= 3) {
        priority += 3;
    }
    else if (daysRemaining <= 7) {
        priority += 1;
    }

    return priority;
}

void SchedulingAlgorithms::sortByPriority(
    std::vector<std::shared_ptr<StudyItem>>& tasks) {

    std::stable_sort(
        tasks.begin(),
        tasks.end(),
        [](const std::shared_ptr<StudyItem>& a,
           const std::shared_ptr<StudyItem>& b) {

            if (!a) return false;
            if (!b) return true;

            return SchedulingAlgorithms::calculatePriority(*a) >
                   SchedulingAlgorithms::calculatePriority(*b);
        }
    );
}

void SchedulingAlgorithms::sortByDeadline(
    std::vector<std::shared_ptr<StudyItem>>& tasks) {

    std::stable_sort(
        tasks.begin(),
        tasks.end(),
        [](const std::shared_ptr<StudyItem>& a,
           const std::shared_ptr<StudyItem>& b) {

            if (!a) return false;
            if (!b) return true;

            return a->getDueInDays() < b->getDueInDays();
        }
    );
}

std::vector<std::shared_ptr<StudyItem>>
SchedulingAlgorithms::greedySchedule(
    const std::vector<std::shared_ptr<StudyItem>>& tasks,
    int availableMinutes) {

    std::vector<std::shared_ptr<StudyItem>> sortedTasks;
    std::vector<std::shared_ptr<StudyItem>> schedule;

    if (availableMinutes <= 0) {
        return schedule;
    }

    for (const auto& task : tasks) {
        if (task && task->getEstimatedMinutes() > 0) {
            sortedTasks.push_back(task);
        }
    }

    sortByPriority(sortedTasks);

    int usedMinutes = 0;

    for (const auto& task : sortedTasks) {
        int duration = task->getEstimatedMinutes();

        if (duration <= availableMinutes - usedMinutes) {
            schedule.push_back(task);
            usedMinutes += duration;
        }
    }

    return schedule;
}