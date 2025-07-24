#include <crow.h>
#include <map>
#include <string>
#include <iostream>
#include "Consumable.h"
#include "Drink.h"
#include "Food.h"
#include "GenericAPI.h"
#include "persistence.h"

using namespace std;
using namespace crow;

// Creating a map to store drinks in bars
map<string, Drink> drinksMap = loadFromFile<Drink>("velvetMartiniDrinks.json");
map<string, Food> foodsMap = loadFromFile<Food>("velvetMartiniFoods.json");


// Creating a map to store bars
//map<string, <>> barMap;

int main() 
{
    // Create GenericAPIs to use in the CROW_ROUTES
    GenericAPI<Drink>::consumableMap = drinksMap;
    GenericAPI<Food>::consumableMap = foodsMap;


    // Setup the simple web service.
    SimpleApp app;

    //Define endpoints and CRUD methods for the Bar and/or Drink consumable.
    CROW_ROUTE(app, "/api/bar/drinks").methods("POST"_method)(GenericAPI<Drink>::createConsumable);
    CROW_ROUTE(app, "/api/bar/drinks").methods("GET"_method)(GenericAPI<Drink>::readAllConsumables);
    CROW_ROUTE(app, "/api/bar/drinks/<string>").methods("GET"_method)(GenericAPI<Drink>::readConsumable);
    CROW_ROUTE(app, "/api/bar/drinks/<string>").methods("PUT"_method)(GenericAPI<Drink>::updateConsumable);
    CROW_ROUTE(app, "/api/bar/drinks/<string>").methods("DELETE"_method)(GenericAPI<Drink>::deleteConsumable);
    
    //Define endpoints and CRUD methods for the Bar and/or Food consumable.
    CROW_ROUTE(app, "/api/bar/foods").methods("POST"_method)(GenericAPI<Food>::createConsumable);
    CROW_ROUTE(app, "/api/bar/foods").methods("GET"_method)(GenericAPI<Food>::readAllConsumables);
    CROW_ROUTE(app, "/api/bar/foods/<string>").methods("GET"_method)(GenericAPI<Food>::readConsumable);
    CROW_ROUTE(app, "/api/bar/foods/<string>").methods("PUT"_method)(GenericAPI<Food>::updateConsumable);
    CROW_ROUTE(app, "/api/bar/foods/<string>").methods("DELETE"_method)(GenericAPI<Food>::deleteConsumable);


    // Run the web service app. 
    // *****************  MAKE SURE TO USE A UNIQUE PORT NUMBER ******************/
    app.port(12123).run();

    //Save the consumables to a file to save game.
    saveToFile<Drink>(GenericAPI<Drink>::consumableMap, "velvetMartiniDrinks.json");
    saveToFile<Food>(GenericAPI<Food>::consumableMap, "velvetMartiniFoods.json");


    return 0;
}