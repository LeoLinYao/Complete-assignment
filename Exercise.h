#ifndef EXERCISE_H
#define EXERCISE_H

#include <string>
#include <fstream>
#include <vector>

struct Set {
    double weight;
    int reps;
};

class Exercise {
public:
    // Constructor
    Exercise(const std::string& name = "", const std::string& muscleGroup = "",
             bool requiresEquipment = false, int totalSets = 0, double weight = 0.0, int reps = 0);

    // Adjust parameters from a specific set index
    void adjustParametersFromSet(int startSetIndex, double weightRatio, double repRatio);

    // Serialization methods
    void save(std::ofstream& outFile) const;
    static Exercise load(std::ifstream& inFile);

    // Getters
    const std::string& getName() const;
    const std::string& getMuscleGroup() const;
    bool isEquipmentRequired() const;
    int getTotalSets() const;
    const std::vector<Set>& getSets() const;

    // Set the parameters for all sets
    void setSets(int totalSets, double weight, int reps);

private:
    std::string name;
    std::string muscleGroup;
    bool requiresEquipment;
    std::vector<Set> sets; // Parameters for each set
};

#endif // EXERCISE_H
