#ifndef WORKOUTSESSION_H
#define WORKOUTSESSION_H

#include "Exercise.h"
#include <vector>
#include <string>

class WorkoutSession {
public:
    // Add an exercise to the workout session
    void addExercise(const Exercise& exercise);

    // Adjust the workout after fatigue based on total completed sets
    void adjustAfterFatigue(int totalCompletedSets, double reductionRatio);

    // Display the workout session
    void displaySession() const;

    // Save and load the workout session
    void saveSession(const std::string& filename) const;
    void loadSession(const std::string& filename);

private:
    std::vector<Exercise> exercises;
};

#endif // WORKOUTSESSION_H
