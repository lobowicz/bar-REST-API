#ifndef GENERIC_API_H
#define GENERIC_API_H

#include <crow.h>
#include <map>
#include <string>

template<typename T> 
class GenericAPI 
{
public:
    static std::map<std::string, T> consumableMap;
    static crow::response createConsumable(crow::request req);
    static crow::response readConsumable(std::string id); 
    static crow::response readAllConsumables(crow::request req);
    static void updateConsumable(crow::request req, crow::response& res, std::string id); 
    static crow::response deleteConsumable(std::string id); 
    bool getIsSpecial(T consumable);
};

#endif // GENERIC_API_H