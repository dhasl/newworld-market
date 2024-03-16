#pragma once
#define CURL_STATICLIB
#include <iostream>
#include <curl/curl.h>
#include <string>
#include <fstream>
#include "/Users/dome-/Desktop/C++ Sample Projects/Ubung/nwmarkt/json/single_include/nlohmann/json.hpp"
class PriceChecker
{
//downloads and manages price data

private:
    

    nlohmann::json jsonData;
    std::string filename = "download.json";

public:
    PriceChecker();
    ~PriceChecker();
    void loadDatafromFile();
    float getItemPrice(std::string itemName);


    

};

