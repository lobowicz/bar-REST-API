#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Consumable.h"
#include "Drink.h"
#include <vector>
#include <string>
#include <memory>

TEST_CASE("Consumable Tests") {
    
    SUBCASE("Consumable methods") 
    {
        // since Consumable is an abstract class, we cannot directly create instances of it
        // vector of pointers to Consumable objects
        std::vector<std::unique_ptr<Consumable>> consumables;

        consumables.push_back(std::make_unique<Drink>("1", "Martini", 12, 4, true, 25));
        consumables.push_back(std::make_unique<Drink>("2", "Whiskey", 30, 5, true, 12));
         
        // test for methods in Consumable class through Drink object
        CHECK(consumables[0]->getId() == "1");
        CHECK(consumables[0]->getConsumable() == "Martini");
        CHECK(consumables[0]->getPrice() == 12);
        CHECK(consumables[0]->getIsDrink() == true);
        CHECK(consumables[0]->isSpecial() == true);
        
        CHECK(consumables[1]->getId() == "2");
        CHECK(consumables[1]->getConsumable() == "Whiskey");
        CHECK(consumables[1]->getPrice() == 30);
        CHECK(consumables[1]->getIsDrink() == true);
        CHECK(consumables[1]->isSpecial() == true);
    }
}
