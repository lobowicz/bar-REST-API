#include "Consumable.h"

using namespace std;
using namespace crow;


Consumable::Consumable(json::rvalue readValueJson)  
{
    updateFromJson(readValueJson);
}

// Convert to JSON
json::wvalue Consumable::convertToJson() 
{
    json::wvalue writeJson;
    writeJson["id"] = id;
    writeJson["name"] = consumable;
    writeJson["price"] = price;
    writeJson["isDrink"] = isDrink;

    return writeJson;
}

// Update from JSON
void Consumable::updateFromJson(json::rvalue readValueJson) 
{
    id = readValueJson["id"].s();
    consumable = readValueJson["name"].s();
    price = static_cast<int>(readValueJson["price"].d());    
    isDrink = readValueJson["isDrink"].b();

}