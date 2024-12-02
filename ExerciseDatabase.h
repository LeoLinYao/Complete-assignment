#ifndef EXERCISEDATABASE_H
#define EXERCISEDATABASE_H

#include "Exercise.h"
#include <vector>
#include <string>

class ExerciseDatabase {
public:
    // Constructor
    ExerciseDatabase();

    // Add an exercise to the database
    void addExercise(const Exercise& exercise);

    // Search exercises by name
    std::vector<Exercise> searchByName(const std::string& name) const;

    // Filter exercises by muscle group
    std::vector<Exercise> filterByMuscleGroup(const std::string& muscleGroup) const;

    // Recommend exercises based on muscle group
    std::vector<Exercise> recommendExercises(const std::string& muscleGroup) const;

    // Display all exercises in the database
    void displayAllExercises() const;

private:
    std::vector<Exercise> exercises;
};

#endif // EXERCISEDATABASE_H
