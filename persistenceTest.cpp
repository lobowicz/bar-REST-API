#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <crow.h>
#include "doctest.h"
#include "persistence.h"
#include "Drink.h"

using namespace std;
using namespace crow;

TEST_CASE("Saving to a file and loading from a file.") 
{
    // load a resources to read
    map<string, Drink> drinksMap;
    drinksMap["1"] = Drink{json::load(R"({"alcPercentage":0,"name":"Water","id":"101","fullSipsAmount":4,"price":2,"sipsAmount":4,"isAlc":false})")};
    drinksMap["2"] = Drink{json::load(R"({"isAlc":true,"sipsAmount":9,"price":4,"fullSipsAmount":9,"id":"102","name":"Beer","alcPercentage":5})")};
    drinksMap["3"] = Drink{json::load(R"({"alcPercentage":40,"name":"Vodka","id":"103","fullSipsAmount":1,"price":4,"sipsAmount":1,"isAlc":true})")};

    // Perform the action
    saveToFile<Drink>(drinksMap, "persistenceTest.json");
    map<string, Drink> drinksMapLoaded = loadFromFile<Drink>("persistenceTest.json");

    // check the results
    CHECK(drinksMap.size() == drinksMapLoaded.size()); // Ensure saved and loaded map are the same size.
    CHECK(drinksMap.at("1").getId() == drinksMapLoaded.at("101").getId()); // Validate the content
    CHECK(drinksMap.at("1").getConsumable() == drinksMapLoaded.at("101").getConsumable()); // Validate the content
    CHECK(drinksMap.at("1").getAlcPercentage() == drinksMapLoaded.at("101").getAlcPercentage()); // Validate the content
    CHECK(drinksMap.at("1").getFullSipsAmount() == drinksMapLoaded.at("101").getFullSipsAmount()); // Validate the content
    CHECK(drinksMap.at("1").getIsAlc() == drinksMapLoaded.at("101").getIsAlc()); // Validate the content
    CHECK(drinksMap.at("1").getPrice() == drinksMapLoaded.at("101").getPrice()); // Validate the content
    CHECK(drinksMap.at("1").getSipsAmount() == drinksMapLoaded.at("101").getSipsAmount()); // Validate the content

    CHECK(drinksMap.size() == drinksMapLoaded.size()); // Ensure saved and loaded map are the same size.
    CHECK(drinksMap.at("2").getId() == drinksMapLoaded.at("102").getId()); // Validate the content
    CHECK(drinksMap.at("2").getConsumable() == drinksMapLoaded.at("102").getConsumable()); // Validate the content
    CHECK(drinksMap.at("2").getAlcPercentage() == drinksMapLoaded.at("102").getAlcPercentage()); // Validate the content
    CHECK(drinksMap.at("2").getFullSipsAmount() == drinksMapLoaded.at("102").getFullSipsAmount()); // Validate the content
    CHECK(drinksMap.at("2").getIsAlc() == drinksMapLoaded.at("102").getIsAlc()); // Validate the content
    CHECK(drinksMap.at("2").getPrice() == drinksMapLoaded.at("102").getPrice()); // Validate the content
    CHECK(drinksMap.at("2").getSipsAmount() == drinksMapLoaded.at("102").getSipsAmount()); // Validate the content

    CHECK(drinksMap.size() == drinksMapLoaded.size()); // Ensure saved and loaded map are the same size.
    CHECK(drinksMap.at("3").getId() == drinksMapLoaded.at("103").getId()); // Validate the content
    CHECK(drinksMap.at("3").getConsumable() == drinksMapLoaded.at("103").getConsumable()); // Validate the content
    CHECK(drinksMap.at("3").getAlcPercentage() == drinksMapLoaded.at("103").getAlcPercentage()); // Validate the content
    CHECK(drinksMap.at("3").getFullSipsAmount() == drinksMapLoaded.at("103").getFullSipsAmount()); // Validate the content
    CHECK(drinksMap.at("3").getIsAlc() == drinksMapLoaded.at("103").getIsAlc()); // Validate the content
    CHECK(drinksMap.at("3").getPrice() == drinksMapLoaded.at("103").getPrice()); // Validate the content
    CHECK(drinksMap.at("3").getSipsAmount() == drinksMapLoaded.at("103").getSipsAmount()); // Validate the content
}
