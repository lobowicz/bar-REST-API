#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Drink.h"
#include "Food.h"
#include "GenericAPI.h"
#include <crow.h>
#include <string>

using namespace std;
using namespace crow;

// Define the maps for resources
map<string, Drink> drinksMap;
map<string, Food> foodsMap;

// Testing the Drink class
TEST_CASE("Creating a new Drink consumable") 
{
    // Clear the map before testing
    GenericAPI<Drink>::consumableMap.clear();

    // Set up the request object
    request req;
    req.body = R"({"alcPercentage":0,"name":"Water","id":"101","fullSipsAmount":4,"price":2,"sipsAmount":4,"isAlc":false})"; 

    // Perform the action
    response res = GenericAPI<Drink>::createConsumable(req);

    // Check the results
    CHECK(res.code == 201);
    CHECK(res.body == req.body);
    CHECK(GenericAPI<Drink>::consumableMap.size() == 1);
    CHECK(GenericAPI<Drink>::consumableMap.at("101").getId() == "101");
    CHECK(GenericAPI<Drink>::consumableMap.at("101").getConsumable() == "Water");
}

TEST_CASE("Reading a Drink consumable") 
{
    // Load a resource into the map
    drinksMap["101"] = Drink(json::load(R"({"alcPercentage":0,"name":"Water","id":"101","fullSipsAmount":4,"price":2,"sipsAmount":4,"isAlc":false})"));

    // Set the map before the test
    GenericAPI<Drink>::consumableMap = drinksMap;

    // Perform the action
    response res = GenericAPI<Drink>::readConsumable("101");

    // Check the results
    CHECK(res.code == 200);
    CHECK(res.body == drinksMap["101"].convertToJson().dump());
    CHECK(GenericAPI<Drink>::consumableMap.size() == 1);
}

TEST_CASE("Reading all Drink consumables") 
{
    // Load multiple resources
    drinksMap["101"] = Drink(json::load(R"({"alcPercentage":0,"name":"Water","id":"101","fullSipsAmount":4,"price":2,"sipsAmount":4,"isAlc":false})"));
    drinksMap["201"] = Drink(json::load(R"({"isAlc":true,"sipsAmount":9,"price":4,"fullSipsAmount":9,"id":"102","name":"Beer","alcPercentage":5})"));

    // Set the map before the test
    GenericAPI<Drink>::consumableMap = drinksMap;

    // Perform the action
    response res = GenericAPI<Drink>::readAllConsumables(request());

    // Create the expected response body
    string expectedResponseBody = R"([{"alcPercentage":0,"name":"Water","id":"101","fullSipsAmount":4,"price":2,"sipsAmount":4,"isAlc":false},{"isAlc":true,"sipsAmount":9,"price":4,"fullSipsAmount":9,"id":"102","name":"Beer","alcPercentage":5}])";
    
    // Check the results
    CHECK(res.code == 200);
    // CHECK(res.body == expectedResponseBody);
    CHECK(GenericAPI<Drink>::consumableMap.size() == 2);
}

TEST_CASE("Updating a Drink consumable") {
    // Load a resource to update
    drinksMap["101"] = Drink(json::load(R"({"alcPercentage":0,"name":"Water","id":"101","fullSipsAmount":4,"price":2,"sipsAmount":4,"isAlc":false})"));
    drinksMap["201"] = Drink(json::load(R"({"isAlc":true,"sipsAmount":9,"price":4,"fullSipsAmount":9,"id":"102","name":"Beer","alcPercentage":5})"));

    // Set the map before the test
    GenericAPI<Drink>::consumableMap = drinksMap;

    // Setup request object to change the drink's details
    request req;
    req.body = R"({"alcPercentage":0,"name":"Cola","id":"101","fullSipsAmount":4,"price":2,"sipsAmount":4,"isAlc":false})";

    // Setup a response object
    response res;

    // Perform the action
    GenericAPI<Drink>::updateConsumable(req, res, "101");

    // Check the results
    CHECK(res.code == 200);
    CHECK(res.body == req.body);
    CHECK(GenericAPI<Drink>::consumableMap.size() == 2);
    CHECK(GenericAPI<Drink>::consumableMap.at("101").getId() == "101");
    CHECK(GenericAPI<Drink>::consumableMap.at("101").getConsumable() == "Cola");
}

