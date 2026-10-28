#ifndef SCHEDULING_ALGORITHMS_H
#define SCHEDULING_ALGORITHMS_H

#include <vector>
#include <memory>
#include "StudyItem.h"

class SchedulingAlgorithms {
public:
    static int calculatePriority(const StudyItem& task);

    static void sortByPriority(
        std::vector<std::shared_ptr<StudyItem>>& tasks
    );

    static void sortByDeadline(
        std::vector<std::shared_ptr<StudyItem>>& tasks
    );

    static std::vector<std::shared_ptr<StudyItem>> greedySchedule(
        const std::vector<std::shared_ptr<StudyItem>>& tasks,
        int availableMinutes
    );
};

#endif