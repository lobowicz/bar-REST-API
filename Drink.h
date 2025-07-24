#ifndef DRINK_H
#define DRINK_H

#include <crow.h>
#include "Consumable.h"

/**
 * @brief Represents a drink item, inheriting from Consumable.
 * 
 * The Drink class inherits from the Consumable class and represents
 * a consumable item that is specifically a drink.
 */
class Drink : public Consumable 
{
public:
    //Constructors
    Drink(): Consumable() { }


    Drink(crow::json::rvalue readValueJson);
    
    /**
     * @brief Constructor for Drink.
     * @param sipsAmount The amount of sips left in the drink before its empty.
     * @param isAlc Boolean value regarding the alcohol content of the Drink.
     * @param alcPerc The % alcohol content of the Drink.
     * @return Null.
    */
    Drink(std::string id, std::string consumable, int price, int sips, bool isAlc, int alcPerc)
        : Consumable(true, id, consumable, price),  
        sipsAmount(sips), fullSipsAmount(sips), alcPercentage(alcPerc), isAlc(isAlc)  {} 


    /**
     * @brief Get the boolean value for whether or not Drink is alcoholic.
     * @return The boolean value for whether or not Drink is alcoholic.
    */
    bool getIsAlc() { return isAlc; }

    // Override the isSpecial() method for Drink
    bool isSpecial() const override { return isAlc; }

    /**
     * @brief Get the integer value for the acohol % of Drink.
     * @return The integer value for the acohol % of Drink.
    */
    int getAlcPercentage() const { return alcPercentage; }

    /**
     * @brief Get the amount of sips left in Drink.
     * @return Int of sips remaining.
    */
    int getSipsAmount() { return sipsAmount; }

    /**
     * @brief Get the amount of sips Drink can hold at max capacity.
     * @return Int of max sips possible in Drink.
    */
    int getFullSipsAmount() { return fullSipsAmount; }

    // Convert to JSON.
    crow::json::wvalue convertToJson();

    // Update from JSON.
    void updateFromJson(crow::json::rvalue readValueJson);

    /**
     * @brief Sets the boolean value displaying whether or not Drink is acoholic
     * @param isAlcohol boolean value regarding the acoholic status of Drink.
     * @return Null
    */
    void setIsAlc(bool isAlcohol) { isAlc = isAlcohol; }
    
    /**
     * @brief Takes a sip from the Drink.
     * @return Null.
     * @throws "Drink is empty!"
    */
    void sipDrink();

    /**
     * @brief Chugs Drink fully.
     * @return Null.
     * @throw "Drink is already emtpy!"
    */
    void chugDrink();
    
    /**
     * @brief Refill Drink to fullSipsAmount.
     * @return Null.
     * @throw "Drink already full!"
    */
    void refillDrink();

    static const bool isDrink = true;

private:
    int sipsAmount;
    int fullSipsAmount;
    int alcPercentage;
    bool isAlc;
    
};

#endif // DRINK_H