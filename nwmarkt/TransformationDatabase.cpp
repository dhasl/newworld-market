
#pragma once
#include "TransformationDatabase.h"





TransformationDatabase::TransformationDatabase() {
    initialize();
}

TransformationDatabase::~TransformationDatabase()
{

}
   

// Funktion zum Hinzufügen einer Transformation zur Datenbank
void TransformationDatabase::addTransformation(const std::string& outputMaterial, const Transformation& transformation) {
        
        
    database[outputMaterial].push_back(transformation);
}

// Funktion zum Abfragen von Transformationen für ein Outputmaterial
std::vector<Transformation> TransformationDatabase::getTransformations(const std::string& outputMaterial) const {
    auto it = database.find(outputMaterial);
    if (it != database.end()) {
        return it->second;
    }
    else {
        return {}; // Wenn kein Outputmaterial gefunden wurde, leere Vektor zurückgeben
    }
}

void TransformationDatabase::printTransformations(std::string outputMaterial) {
    auto swordTransformations = getTransformations(outputMaterial);
    for (const auto& trans : swordTransformations) {
        std::cout << outputMaterial << " Transformation:" << std::endl;
        for (const auto& input : trans.inputs) {
            std::cout << input.first << ": " << input.second << std::endl;
        }
        std::cout << "\n";
    }
}

void TransformationDatabase::listAllMaterials() {
    for (const auto& mat : database) {
        std::cout << mat.first << "\n";
    }
}

std::map<std::string, std::vector<Transformation>>& TransformationDatabase::getDatabase() {
    return database; 
}

void TransformationDatabase::initialize() {
    Transformation prismaticIngot1;
    prismaticIngot1.inputs = { {"Asmodeum", 1}, {"Mythril Ingot", 10}, {"Charcoal", 4}, {"Obsidian Flux", 4} };
    prismaticIngot1.craftingTax = 0.5f;
    addTransformation("Prismatic Ingot", prismaticIngot1);

    Transformation asmodeum1;
    asmodeum1.craftingTax = 0.19f;
    asmodeum1.inputs = { {"Orichalcum Ingot", 5}, {"Tolvium", 1}, {"Cinnabar", 1}, {"Obsidian Flux", 1}, {"Charcoal", 2} };
    addTransformation("Asmodeum", asmodeum1);

    Transformation asmodeum2;
    asmodeum2.craftingTax = 10.0f;
    asmodeum2.inputs = { {"Vial of Suspended Azoth", 5} };
    addTransformation("Asmodeum", asmodeum2);

    Transformation mythrilIngot1;
    mythrilIngot1.craftingTax = 0.22f;
    mythrilIngot1.inputs = { {"Mythril Ore", 12}, {"Orichalcum Ingot", 2}, {"Charcoal", 2}, {"Obsidian Flux", 1} };
    addTransformation("Mythril Ingot", mythrilIngot1);

    Transformation charcoal1;
    charcoal1.inputs = { {"Green Wood", 2} };
    charcoal1.craftingTax = 0.01f;
    addTransformation("Charcoal", charcoal1);

    Transformation charcoal2;
    charcoal2.inputs = { {"Aged Wood", 2} };
    charcoal2.craftingTax = 0.01f;
    addTransformation("Charcoal", charcoal2);

    Transformation charcoal3;
    charcoal3.inputs = { {"Wyrdwood", 2} };
    charcoal3.craftingTax = 0.01f;
    addTransformation("Charcoal", charcoal3);

    Transformation charcoal4;
    charcoal4.inputs = { {"Ironwood", 2} };
    charcoal4.craftingTax = 0.01f;
    addTransformation("Charcoal", charcoal4);

    Transformation charcoal5;
    charcoal5.inputs = { {"Runewood", 2} };
    charcoal5.craftingTax = 0.01f;
    addTransformation("Charcoal", charcoal5);

    Transformation oriIngot1;
    oriIngot1.inputs = { {"Orichalcum Ore", 8}, {"Starmetal Ingot", 2 }, {"Charcoal", 2}, {"Obsidian Flux", 1} };
    oriIngot1.craftingTax = 0.13f;
    addTransformation("Orichalcum Ingot", oriIngot1);

    Transformation starmetalIngot1;
    starmetalIngot1.inputs = { {"Starmetal Ore", 6}, {"Steel Ingot", 2 }, {"Charcoal", 2}, {"Obsidian Flux", 1} };
    starmetalIngot1.craftingTax = 0.07f;
    addTransformation("Starmetal Ingot", starmetalIngot1);

    Transformation steelIngot1;
    steelIngot1.inputs = { {"Iron Ingot", 3 }, {"Charcoal", 2}, {"Obsidian Flux", 1} };
    steelIngot1.craftingTax = 0.07f;
    steelIngot1.additionalCrafts = 1.00f;
    addTransformation("Steel Ingot", steelIngot1);

    Transformation ironIngot1;
    ironIngot1.inputs = { {"Iron Ore", 4 } };
    ironIngot1.craftingTax = 0.01f;
    // ironIngot1.additionalCrafts = 1.00f;
    addTransformation("Iron Ingot", ironIngot1);
}