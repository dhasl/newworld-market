#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <string>

struct Transformation {
    std::map<std::string, int> inputs; // Map von Inputmaterialien zu ihrer benötigten Anzahl
    float craftingTax;
    float additionalCrafts;
};
class TransformationDatabase
{
private:
    std::map<std::string, std::vector<Transformation>> database; // Map von Outputmaterialien zu ihren Herstellvarianten

public:
    TransformationDatabase();
    ~TransformationDatabase();
    
    std::map<std::string, std::vector<Transformation>>& getDatabase();
    void addTransformation(const std::string& outputMaterial, const Transformation& transformation); // Funktion zum Hinzufügen einer Transformation zur Datenbank
    std::vector<Transformation> getTransformations(const std::string& outputMaterial) const;// Funktion zum Abfragen von Transformationen für ein Outputmaterial
    void printTransformations(std::string outputMaterial);
    void listAllMaterials();
    void initialize();

};

