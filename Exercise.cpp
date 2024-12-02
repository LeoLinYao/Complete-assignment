#include "Exercise.h"
#include <cmath>
#include <iostream>

// Constructor implementation
Exercise::Exercise(const std::string& name, const std::string& muscleGroup,
                   bool requiresEquipment, int totalSets, double weight, int reps)
    : name(name), muscleGroup(muscleGroup), requiresEquipment(requiresEquipment) {
    setSets(totalSets, weight, reps);
}

// Set the parameters for all sets
void Exercise::setSets(int totalSets, double weight, int reps) {
    sets.clear();
    for (int i = 0; i < totalSets; ++i) {
        sets.push_back({weight, reps});
    }
}

// Adjust parameters from a specific set index
void Exercise::adjustParametersFromSet(int startSetIndex, double weightRatio, double repRatio) {
    for (size_t i = startSetIndex; i < sets.size(); ++i) {
        sets[i].weight = std::round(sets[i].weight * weightRatio);
        sets[i].reps = static_cast<int>(std::round(sets[i].reps * repRatio));

        // Ensure parameters are not zero or negative
        if (sets[i].weight < 0) sets[i].weight = 0;
        if (sets[i].reps < 1) sets[i].reps = 1;
    }
}

// Serialization methods
void Exercise::save(std::ofstream& outFile) const {
    outFile << name << '\n'
            << muscleGroup << '\n'
            << requiresEquipment << '\n'
            << sets.size() << '\n';
    for (const auto& set : sets) {
        outFile << set.weight << ' ' << set.reps << '\n';
    }
}

Exercise Exercise::load(std::ifstream& inFile) {
    std::string name;
    std::string muscleGroup;
    bool requiresEquipment;
    int totalSets;

    std::getline(inFile, name);
    std::getline(inFile, muscleGroup);
    inFile >> requiresEquipment;
    inFile >> totalSets;
    inFile.ignore(); // Ignore newline character

    Exercise exercise(name, muscleGroup, requiresEquipment);
    for (int i = 0; i < totalSets; ++i) {
        double weight;
        int reps;
        inFile >> weight >> reps;
        exercise.sets.push_back({weight, reps});
    }
    inFile.ignore(); // Ignore newline character

    return exercise;
}

// Getter implementations
const std::string& Exercise::getName() const { return name; }
const std::string& Exercise::getMuscleGroup() const { return muscleGroup; }
bool Exercise::isEquipmentRequired() const { return requiresEquipment; }
int Exercise::getTotalSets() const { return sets.size(); }
const std::vector<Set>& Exercise::getSets() const { return sets; }
