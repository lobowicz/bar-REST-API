#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Drink.h"
#include <string>

TEST_SUITE("Drink Tests") {
    TEST_CASE("Parameterized Constructor") {
        Drink drink("1", "Cola", 10, 5, true, 40);
        CHECK(drink.getId() == "1");
        CHECK(drink.getConsumable() == "Cola");
        CHECK(drink.getPrice() == 10);
        CHECK(drink.getIsAlc() == true);
        CHECK(drink.getAlcPercentage() == 40);
        CHECK(drink.getSipsAmount() == 5);
        CHECK(drink.getFullSipsAmount() == 5);
    }

    TEST_CASE("JSON Conversion") {
        Drink drink("1", "Cola", 10, 5, true, 40);
        crow::json::wvalue result = drink.convertToJson();
        crow::json::rvalue rValue = crow::json::load(result.dump());
        CHECK(rValue["id"].s() == "1");
        CHECK(rValue["name"].s() == "Cola");
        CHECK(rValue["price"].i() == 10);
        CHECK(rValue["isAlc"].b() == true);
        CHECK(rValue["alcPercentage"].i() == 40);
        CHECK(rValue["sipsAmount"].i() == 5);
        CHECK(rValue["fullSipsAmount"].i() == 5);
    }

    TEST_CASE("Update from JSON") {
        Drink drink;
        crow::json::rvalue fakeJson = crow::json::load("{\"id\":\"2\", \"name\":\"Sprite\", \"price\":15, \"fullSipsAmount\":10, \"sipsAmount\":10, \"alcPercentage\":0, \"isAlc\":false}");
        drink.updateFromJson(fakeJson);
        CHECK(drink.getId() == "2");
        CHECK(drink.getConsumable() == "Sprite");
        CHECK(drink.getPrice() == 15);
        CHECK(drink.getIsAlc() == false);
        CHECK(drink.getAlcPercentage() == 0);
        CHECK(drink.getSipsAmount() == 10);
        CHECK(drink.getFullSipsAmount() == 10);
    }

    TEST_CASE("Drink Actions") {
        Drink drink("1", "Cola", 10, 3, true, 40);
        SUBCASE("Sip Drink") {
            drink.sipDrink();
            CHECK(drink.getSipsAmount() == 2);
        }
        SUBCASE("Chug Drink") {
            drink.chugDrink();
            CHECK(drink.getSipsAmount() == 0);
        }
        SUBCASE("Refill Drink") {
            drink.sipDrink(); // Take one sip to not be full
            drink.refillDrink();
            CHECK(drink.getSipsAmount() == 3);
        }
        SUBCASE("Exceptions") {
            drink.chugDrink(); // Empty the drink
            CHECK_THROWS_AS(drink.sipDrink(), std::invalid_argument);
            CHECK_THROWS_AS(drink.chugDrink(), std::invalid_argument);
            CHECK_NOTHROW(drink.refillDrink());
            CHECK_THROWS_AS(drink.refillDrink(), std::invalid_argument);
        }
    }
}