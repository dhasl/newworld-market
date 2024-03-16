#include "PriceChecker.h"

PriceChecker::PriceChecker() {
    loadDatafromFile();

}

PriceChecker::~PriceChecker() {


}
void PriceChecker::loadDatafromFile() {
    using json = nlohmann::json;
    // JSON-Datei laden
    std::ifstream file("download.json");
    if (!file.is_open()) {
        std::cerr << "Failed to open JSON file.\n";
    }
    try
    {
        file >> jsonData;
        file.close();
    }
    catch (json::parse_error& e)
    {
        std::cerr << "Failed to parse JSON: " << e.what() << '\n';
    }
}
float PriceChecker::getItemPrice(std::string itemName) {
    float x = 0.0f;
    for (const auto& item : jsonData) {
        if (item["ItemName"] == itemName)
        {         
            try {
                std::string p = item["Price"];
                x = std::stof(p);
            }
            catch (const nlohmann::json::type_error& e)
            {
                // output exception information
                std::cout << "message: " << e.what() << '\n'
                    << "exception id: " << e.id << std::endl;
            }
        }
    }
    if (x == 0.0f) { 
        std::cerr << "Item not found: " << itemName << '\n';
    }   
    return x;
}




