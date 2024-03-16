#include "order.h"
#include "statusCodes.h"

// constructors

// getters and setters
void order::setName(std::string newName) {}
std::string order::getName() const { return name; }

void order::setSurname(std::string newSurname) {}
std::string order::getSurname() const { return surname; }

void order::setDate(std::string date)
{
}
std::string order::getDate() const { return "poniedzialek"; }

void order::setProductList(std::vector<std::string> productList) {}
std::vector<std::string> order::getProductList() const { return productList; }

void order::setStatusCode(int statusCode) {}
int order::getStatusCode() const { return statusCode; }

void order::setShipmentAddress(std::string shipmentAddress) {}
std::string order::getShipmentAddress() const { return shipmentAddress; }