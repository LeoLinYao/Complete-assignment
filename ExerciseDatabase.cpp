#include "ExerciseDatabase.h"
#include <algorithm>
#include <iostream>

ExerciseDatabase::ExerciseDatabase() {
    // Initialize with some default exercises (without sets, weight, reps)
    addExercise(Exercise("Squat", "Legs", true));
    addExercise(Exercise("Bench Press", "Chest", true));
    addExercise(Exercise("Pull-Up", "Back", false));
    addExercise(Exercise("Lunge", "Legs", false));
    addExercise(Exercise("Push-Up", "Chest", false));
    addExercise(Exercise("High pull-down", "Back", true));
    addExercise(Exercise("Seated rowing", "Back", true));
    addExercise(Exercise("Bicep Curl", "Biceps", false));
    addExercise(Exercise("Cable Dips", "Triceps",true));
    // Add more exercises as needed...
}

void ExerciseDatabase::addExercise(const Exercise& exercise) {
    exercises.push_back(exercise);
}

std::vector<Exercise> ExerciseDatabase::searchByName(const std::string& name) const {
    std::vector<Exercise> results;
    for (const auto& exercise : exercises) {
        if (exercise.getName().find(name) != std::string::npos) {
            results.push_back(exercise);
        }
    }
    return results;
}

std::vector<Exercise> ExerciseDatabase::filterByMuscleGroup(const std::string& muscleGroup) const {
    std::vector<Exercise> results;
    for (const auto& exercise : exercises) {
        if (exercise.getMuscleGroup() == muscleGroup) {
            results.push_back(exercise);
        }
    }
    return results;
}

std::vector<Exercise> ExerciseDatabase::recommendExercises(const std::string& muscleGroup) const {
    return filterByMuscleGroup(muscleGroup);
}

void ExerciseDatabase::displayAllExercises() const {
    for (const auto& exercise : exercises) {
        std::cout << "Exercise: " << exercise.getName()
                  << ", Target Muscle Group: " << exercise.getMuscleGroup()
                  << ", Requires Equipment: " << (exercise.isEquipmentRequired() ? "Yes" : "No")
                  << std::endl;
    }
}
