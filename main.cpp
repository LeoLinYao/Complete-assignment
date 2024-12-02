#include "WorkoutSession.h"
#include "ExerciseDatabase.h"
#include "Exercise.h"
#include <iostream>
#include <string>

int main() {
    WorkoutSession session;
    ExerciseDatabase exerciseDB;

    int choice;
    std::string filename;
    while (true) {
        std::cout << "\nPlease select an option:\n";
        std::cout << "1. View all available exercises\n";
        std::cout << "2. Search exercises by name\n";
        std::cout << "3. Filter exercises by muscle group\n";
        std::cout << "4. Add exercise to workout session\n";
        std::cout << "5. Display current workout session\n";
        std::cout << "6. Save workout session\n";
        std::cout << "7. Load workout session\n";
        std::cout << "8. Adjust workout after fatigue\n";
        std::cout << "9. Exit\n";
        std::cout << "Enter your choice (1-9): ";
        std::cin >> choice;

        if (choice == 1) {
            exerciseDB.displayAllExercises();
        } else if (choice == 2) {
            std::string searchName;
            std::cout << "Enter the exercise name to search: ";
            std::cin.ignore();
            std::getline(std::cin, searchName);
            auto results = exerciseDB.searchByName(searchName);
            if (results.empty()) {
                std::cout << "No exercises found.\n";
            } else {
                for (const auto& exercise : results) {
                    std::cout << "Exercise: " << exercise.getName()
                              << ", Target Muscle Group: " << exercise.getMuscleGroup() << std::endl;
                }
            }
        } else if (choice == 3) {
            std::string muscleGroup;
            std::cout << "Enter muscle group (e.g., Chest, Back, Legs): ";
            std::cin.ignore();
            std::getline(std::cin, muscleGroup);
            auto results = exerciseDB.filterByMuscleGroup(muscleGroup);
            if (results.empty()) {
                std::cout << "No exercises found for the specified muscle group.\n";
            } else {
                for (const auto& exercise : results) {
                    std::cout << "Exercise: " << exercise.getName()
                              << ", Requires Equipment: " << (exercise.isEquipmentRequired() ? "Yes" : "No") << std::endl;
                }
            }
        } else if (choice == 4) {
            std::string exerciseName;
            std::cout << "Enter the name of the exercise to add: ";
            std::cin.ignore();
            std::getline(std::cin, exerciseName);
            auto results = exerciseDB.searchByName(exerciseName);
            if (results.empty()) {
                std::cout << "Exercise not found.\n";
            } else {
                const Exercise& exercise = results[0]; // Assuming the first matching exercise
                int sets, reps;
                double weight;
                std::cout << "Set parameters - Total Sets: ";
                std::cin >> sets;
                std::cout << "Set parameters - Weight (kg), enter 0 for bodyweight exercises: ";
                std::cin >> weight;
                std::cout << "Set parameters - Reps: ";
                std::cin >> reps;
                Exercise customizedExercise = exercise;
                customizedExercise.setSets(sets, weight, reps);
                session.addExercise(customizedExercise);
                std::cout << "Exercise added to workout session.\n";
            }
        } else if (choice == 5) {
            session.displaySession();
        } else if (choice == 6) {
            std::cout << "Enter the filename to save the session: ";
            std::cin >> filename;
            session.saveSession(filename);
            std::cout << "Workout session saved to file: " << filename << std::endl;
        } else if (choice == 7) {
            std::cout << "Enter the filename to load the session: ";
            std::cin >> filename;
            session.loadSession(filename);
            std::cout << "Workout session loaded from file: " << filename << std::endl;
        } else if (choice == 8) {
            int totalCompletedSets;
            std::cout << "Enter the total number of sets completed so far: ";
            std::cin >> totalCompletedSets;
            double reductionRatio = 0.9; // Automatically reduce by 10%
            session.adjustAfterFatigue(totalCompletedSets, reductionRatio);
            std::cout << "Workout session has been adjusted due to fatigue.\n";
        } else if (choice == 9) {
            break;
        } else {
            std::cout << "Invalid option, please try again.\n";
        }
    }

    return 0;
}
