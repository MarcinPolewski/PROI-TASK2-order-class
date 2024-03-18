#include "order.h"

// constructors
order::order(
    std::string name,
    std::string surname,
    date orderDate,
    std::vector<std::string> productList,
    int statusCode,
    std::string shipmentAddress)
{
    this->name = name;
    this->surname = surname;
    this->orderDate = orderDate;
    this->productList = productList;
    this->statusCode = statusCode;
    this->shipmentAddress = shipmentAddress;
}

order::order(
    std::string name,
    std::string surname,
    date orderDate,
    std::vector<std::string> productList,
    std::string shipmentAddress)
{
    this->name = name;
    this->surname = surname;
    this->orderDate = orderDate;
    this->statusCode = ORDER_PLACED;
    this->productList = productList;
    this->shipmentAddress = shipmentAddress;
}

order::order(
    std::string name,
    std::string surname,
    date orderDate,
    std::string shipmentAddress)
{
    this->name = name;
    this->surname = surname;
    this->orderDate = orderDate;
    this->statusCode = ORDER_PLACED;
    this->productList = std::vector<std::string>(1);
    this->shipmentAddress = shipmentAddress;
}

// getters and setters
void order::setName(std::string newName)
{
    this->name = newName;
}
std::string order::getName() const { return name; }

void order::setSurname(std::string newSurname) { this->surname = newSurname; }
std::string order::getSurname() const { return surname; }

void order::setDate(date orderDate) { this->orderDate = orderDate; }
date order::getDate() const { return orderDate; }

void order::setProductList(std::vector<std::string> productList) {}
std::vector<std::string> order::getProductList() const { return productList; }

void order::setStatusCode(int statusCode) {}
int order::getStatusCode() const { return statusCode; }

void order::setShipmentAddress(std::string shipmentAddress) {}
std::string order::getShipmentAddress() const { return shipmentAddress; }