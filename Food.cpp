#include <string>
#include <stdexcept>
#include <iostream>
#include "Consumable.h"
#include "Food.h"

using namespace crow;

/**
 * @file Food.cpp
 * @brief Implementation file for the Food class functions.
*/


Food::Food(json::rvalue readValueJson)
{
    updateFromJson(readValueJson);
}

// Convert to JSON
json::wvalue Food::convertToJson() 
{
    json::wvalue writeValueJson;
    writeValueJson["id"] = id;
    writeValueJson["name"] = consumable;
    writeValueJson["price"] = price;
    writeValueJson["fullBitesAmount"] = fullBitesAmount;
    writeValueJson["bitesAmount"] = bitesAmount;
    writeValueJson["isHot"] = isHot;

    return writeValueJson;
}
    
// Update from JSON
void Food::updateFromJson(json::rvalue readValueJson)
{
    id = readValueJson["id"].s();
    consumable = readValueJson["name"].s();
    price = static_cast<int>(readValueJson["price"].d());    
    fullBitesAmount = static_cast<int>(readValueJson["fullBitesAmount"].d());
    bitesAmount = static_cast<int>(readValueJson["bitesAmount"].d());
    isHot = readValueJson["isHot"].b();

}

/**
 * @brief Takes a bite from the Food.
 * @return Null.
 * @throws "There's no name_of_food left!"
*/
void Food::biteFood() 
{
    std::string foodName = this->getConsumable();

    if (bitesAmount == 0)
    {
        throw std::invalid_argument("There's no " + foodName + " left!");
    }
    bitesAmount -= 1;
    std::cout << "You take a bite of your food. tasty" << std::endl;
}


/**
 * @brief Eats Food completely.
 * @return Null.
 * @throw "There's no name_of_food left!"
*/
void Food::finishFood() 
{ 
    std::string foodName = this->getConsumable();
    if (bitesAmount == 0)
    {
        throw std::invalid_argument("There's no " + foodName + " left!");
    }
    bitesAmount = 0;
    if (bitesAmount == 1)
    {
        std::cout << "You finish your food. Delicious!" << std::endl;
    } else {
        std::cout << "You stuff your mouth with the food. In a rush?" << std::endl;
    }
}

/**
 * @brief Get another order of Food.
 * @return Null.
 * @throw "You already have fresh name_of_food!"
*/
void Food::reorderFood() 
{ 
    std::string foodName = this->getConsumable();
    if (bitesAmount == fullBitesAmount)
    {
        throw std::invalid_argument("You already have fresh " + foodName + " !");
    }
    bitesAmount = fullBitesAmount;    
    std::cout << "The bartender brings you another plate of " << foodName << std::endl;

}