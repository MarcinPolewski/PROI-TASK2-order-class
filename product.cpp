#include "product.h"

product::product(std::string name, unsigned int idNumber)
{
    this->idNumber = idNumber;
    this->name = name;
}

void product::setName(std::string name) { this->name = name; }
std::string product::getName() const { return name; }

void product::setIdNumber(unsigned int idNumber) { this->idNumber = idNumber; }
unsigned int product::getIdNumber() const { return idNumber; }

void product::setPriceInGr(unsigned int price) { this->priceInGr = price; }
unsigned int product::getPriceInGr() const { return priceInGr; }