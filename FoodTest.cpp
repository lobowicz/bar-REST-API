#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Food.h"
#include <string>

TEST_SUITE("Food Tests") {
    TEST_CASE("Parameterized Constructor") {
        Food food("1", "Pizza", 20, 8, true);
        CHECK(food.getId() == "1");
        CHECK(food.getConsumable() == "Pizza");
        CHECK(food.getPrice() == 20);
        CHECK(food.getBitesAmount() == 8);
        CHECK(food.getFullBitesAmount() == 8);
        CHECK(food.getIsHot() == true);
    }

    TEST_CASE("Biting Food") {
        Food food("2", "Burger", 15, 5, true);
        SUBCASE("Bite once") {
            food.biteFood();
            CHECK(food.getBitesAmount() == 4);
        }
        SUBCASE("Finish Bites") {
            for (int i = 0; i < 5; i++) {
                food.biteFood();  // Bite until it's supposed to be empty
            }
            CHECK(food.getBitesAmount() == 0);
            CHECK_THROWS_AS(food.biteFood(), std::invalid_argument);
        }
    }

    TEST_CASE("Finishing Food") {
        Food food("3", "Noodles", 12, 10, false);
        food.finishFood();
        CHECK(food.getBitesAmount() == 0);
        CHECK_THROWS_AS(food.biteFood(), std::invalid_argument);
    }

    TEST_CASE("Reordering Food") {
        Food food("4", "Salad", 10, 3, false);
        food.finishFood();  // This will set bitesAmount to 0.
        CHECK_NOTHROW(food.reorderFood());  // Since bitesAmount is 0, reorder should not throw here.
        CHECK(food.getBitesAmount() == 3);  // Check if food is refilled.
        CHECK_THROWS_AS(food.reorderFood(), std::invalid_argument);  // Now it should throw because it's already full.
    }
}
