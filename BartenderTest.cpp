#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Bartender.h"
#include "Consumable.h"
#include "Drink.h"
#include <vector>

TEST_CASE("Testing Bartender functionalities") {
    
    // Create a bartender object
    Bartender john("John Doe");

    // Test Bartender's name
    CHECK(john.getName() == "John Doe");

    // Creating consumables using smart pointers to handle dynamic allocation
    std::unique_ptr<Drink> cola = std::make_unique<Drink>("1", "Cola", 10, 5, true, 40);
    std::unique_ptr<Drink> sprite = std::make_unique<Drink>("1", "Sprite", 10, 5, true, 40);

    // Add consumables to the bartender
    john.addConsumable(cola.get());
    john.addConsumable(sprite.get());

    // Check if consumables are added correctly
    std::vector<Consumable*> consumables = john.getConsumables();
    CHECK(consumables.size() == 2);
    CHECK(consumables[0]->getConsumable() == "Cola");
    CHECK(consumables[1]->getConsumable() == "Sprite");

}
