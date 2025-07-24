#include <string>
#include <stdexcept>
#include <iostream>
#include <random>
#include "Consumable.h"
#include "Drink.h"

using namespace crow;
/**
 * @file Drink.cpp
 * @brief Implementation file for the Drink class functions.
*/

// Set up random number generation
std::random_device rd;
std::mt19937 rng(rd()); // Initialize Mersenne Twister RNG with a random seed
std::uniform_int_distribution<int> dist4(1, 4); // Define distribution for integers between 1 and 4 (inclusive)
std::uniform_int_distribution<int> dist10(1, 10); // Define distribution for integers between 1 and 10 (inclusive)
std::uniform_int_distribution<int> dist1000(1, 1000); // Define distribution for integers between 1 and 1000 (inclusive)
// Generate random numbers
int randomNumbero4 = dist4(rng); //Random number from 1 to 4
int randomNumbero10 = dist10(rng); //Random number from 1 to 10
int randomNumbero1000  = dist1000(rng); //Random number from 1 to 1000

Drink::Drink(json::rvalue readValueJson)
{
    updateFromJson(readValueJson);
}

// Convert to JSON
json::wvalue Drink::convertToJson() 
{
    json::wvalue writeValueJson;
    writeValueJson["id"] = id;
    writeValueJson["name"] = consumable;
    writeValueJson["price"] = price;
    writeValueJson["fullSipsAmount"] = fullSipsAmount;
    writeValueJson["sipsAmount"] = sipsAmount;
    writeValueJson["isAlc"] = isAlc;
    writeValueJson["alcPercentage"] = alcPercentage; 
    return writeValueJson;
}

// Update from JSON
void Drink::updateFromJson(json::rvalue readValueJson)
{
    id = readValueJson["id"].s();
    consumable = readValueJson["name"].s();
    price = static_cast<int>(readValueJson["price"].d());    
    fullSipsAmount = static_cast<int>(readValueJson["fullSipsAmount"].d());
    sipsAmount = static_cast<int>(readValueJson["sipsAmount"].d());
    alcPercentage = static_cast<int>(readValueJson["alcPercentage"].d());
    isAlc = readValueJson["isAlc"].b();

}

/**
 * @brief Takes a sip from the Drink
 * @return Null.
 * @throws "Drink is empty!"
*/
void Drink::sipDrink() 
{

    if (sipsAmount == 0)
    {
        throw std::invalid_argument("Your drink is already empty!");
    }

    sipsAmount -= 1;
    if (randomNumbero4 == 1)
    {
        std::cout << "You take a sip of your drink. It tastes refreshing." << std::endl;
    } else {
        std::cout << "You take a sip of your drink." << std::endl;
    }

}

/**
 * @brief Chugs Drink fully.
 * @return Null.
 * @throw "Drink is already emtpy!"
*/
void Drink::chugDrink()
{
    if (sipsAmount == 0)
    {
        throw std::invalid_argument("Your drink is already empty!");
    }
    sipsAmount = 0;

    if ( sipsAmount == 1)
    {
        std::cout << "You finish your drink." << std::endl;
    } else {
        if (randomNumbero1000 == 1)
        {
            std::cout << "You fully chug you drink! You think about what you're doing with your life. You feel sick." << std::endl;
        } else {
            std::cout << "You fully chug your drink! You feel sick." << std::endl;
        }
    }
}

/**
 * @brief Refill Drink to fullSipsAmount.
 * @return Null.
 * @throw "Drink already full!"
*/
void Drink::refillDrink()
{
    if (sipsAmount == fullSipsAmount)
    {
        throw std::invalid_argument("Your drink is already full!");
    }
    sipsAmount = fullSipsAmount;    
    std::cout << "The bartender refills your drink." << std::endl;

}