#ifndef BARTENDER_H
#define BARTENDER_H

#include <string>
#include <vector>
#include "Consumable.h"


/**
 * @brief Represents a bartender. 
 * 
 * The Bartender class holds information about a bartender,
 * including their name and a list of consumables they manage.
*/
class Bartender 
{
    public:
        /**
         * @brief Constructor for creating a Bartender object.
         * @param name The name of the bartender.
        */
        Bartender(std::string name) : name(name) { }

        /**
         * @brief Adds a consumable item to the bartender's list of consumables.
         * This method allows the bartender to manage a new consumable item.
         * @param consumable The consumable item to be added. 
        */
        void addConsumable(Consumable* consumable) {
            consumables.push_back(consumable);
        }

        /**
         * @brief Gets the name of the bartender.
         * This method returns the name of the bartender as a standard string.
         * @return The name of the bartender.
         */
        std::string getName() const {
            return name;
        }

        /**
         * @brief Retrieves all consumable items managed by the bartender.
         * This method returns a list (vector) of all consumables that the bartender currently manages.
         * @return A vector containing all consumables managed by the bartender.
         */
        std::vector<Consumable*> getConsumables() {
            return consumables;
        }

    private:
        std::string name;
        std::vector<Consumable*> consumables;

};

#endif
