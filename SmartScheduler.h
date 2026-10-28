#ifndef SMART_SCHEDULER_H
#define SMART_SCHEDULER_H

#include <vector>
#include <memory>
#include "StudyItem.h"

class SmartScheduler {
private:
    std::vector<std::shared_ptr<StudyItem>> scheduledTasks;

public:
    void generateSchedule(
        const std::vector<std::shared_ptr<StudyItem>>& tasks,
        int availableMinutes
    );

    void displaySchedule() const;

    int getScheduledTaskCount() const;
};

#endif