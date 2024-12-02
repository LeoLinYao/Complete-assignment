#include "WorkoutSession.h"
#include <iostream>
#include <fstream>

void WorkoutSession::addExercise(const Exercise& exercise) {
    exercises.push_back(exercise);
}

void WorkoutSession::adjustAfterFatigue(int totalCompletedSets, double reductionRatio) {
    int accumulatedSets = 0;
    bool fatigueReached = false;
    std::string fatigueMuscleGroup;

    for (auto& exercise : exercises) {
        int totalSets = exercise.getTotalSets();
        if (!fatigueReached) {
            if (accumulatedSets + totalSets > totalCompletedSets) {
                // Fatigue occurs during this exercise
                int startSetIndex = totalCompletedSets - accumulatedSets;
                fatigueMuscleGroup = exercise.getMuscleGroup();
                exercise.adjustParametersFromSet(startSetIndex, reductionRatio, reductionRatio);
                fatigueReached = true;
            }
            accumulatedSets += totalSets;
        } else {
            // Fatigue has occurred, adjust exercises of the same muscle group
            if (exercise.getMuscleGroup() == fatigueMuscleGroup) {
                exercise.adjustParametersFromSet(0, reductionRatio, reductionRatio);
            }
        }
    }
}

void WorkoutSession::displaySession() const {
    for (const auto& exercise : exercises) {
        std::cout << "Exercise: " << exercise.getName()
                  << ", Muscle Group: " << exercise.getMuscleGroup() << std::endl;
        int setNumber = 1;
        for (const auto& set : exercise.getSets()) {
            std::cout << "  Set " << setNumber << ": "
                      << "Weight: " << set.weight
                      << ", Reps: " << set.reps << std::endl;
            ++setNumber;
        }
    }
}

void WorkoutSession::saveSession(const std::string& filename) const {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Unable to open file for saving: " << filename << std::endl;
        return;
    }

    outFile << exercises.size() << '\n';
    for (const auto& exercise : exercises) {
        exercise.save(outFile);
    }
}

void WorkoutSession::loadSession(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Unable to open file for loading: " << filename << std::endl;
        return;
    }

    size_t size;
    inFile >> size;
    inFile.ignore(); // Ignore newline character

    exercises.clear();
    for (size_t i = 0; i < size; ++i) {
        exercises.push_back(Exercise::load(inFile));
    }
}
