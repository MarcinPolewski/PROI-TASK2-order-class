#include "order.h"

// constructors
order::order(
    std::string name,
    std::string surname,
    date orderDate,
    std::vector<orderListElement> productList,
    orderStatus statusCode,
    address shipmentAddress)
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
    std::vector<orderListElement> productList,
    address shipmentAddress)
{
    this->name = name;
    this->surname = surname;
    this->orderDate = orderDate;
    this->productList = productList;
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

void order::setDate(date &orderDate) { this->orderDate = orderDate; }
const date &order::getDate() const { return orderDate; }

void order::setProductList(std::vector<orderListElement> &productList) { this->productList = productList; }
std::vector<orderListElement> &order::getProductList() { return productList; }

void order::setStatusCode(orderStatus statusCode) { this->statusCode = statusCode; }
orderStatus order::getStatusCode() const { return statusCode; }

void order::setShipmentAddress(address &shipmentAddress) { this->shipmentAddress = shipmentAddress; }
const address &order::getShipmentAddress() const { return shipmentAddress; }