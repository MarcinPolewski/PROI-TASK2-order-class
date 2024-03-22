#include "address.h"

address::address(std::string country, std::string city, int postalCode, std::string street, int houseNumber)
{
    this->country = country;
    this->city = city;
    this->postalCode = postalCode;
    this->street = street;
    this->houseNumber = houseNumber;
}

void address::setCountry(std::string &country) { this->country = country; }
const std::string &address::getCountry() const { return country; }

void address::setCity(std::string &city) { this->city = city; }
const std::string &address::getCity() const { return city; }

void address::setPostalCode(int postalCode) { this->postalCode = postalCode; }
int address::getPostalCode() const { return postalCode; }

void address::setStreet(std::string &street) { this->street = street; }
const std::string &address::getStreet() const { return street; }

void address::setHouseNumber(int houseNumber) { this->houseNumber = houseNumber; }
int address::getHouseNumber() const { return houseNumber; }

bool address::operator==(const address &another) const
{
    // comparing ints first, because it's the fastests and good chance
    // there will be a difference
    return (houseNumber == another.getHouseNumber() &&
            postalCode == another.getPostalCode() &&
            country.compare(another.getCountry()) &&
            city.compare(another.getCity()) &&
            postalCode == another.getPostalCode() &&
            street.compare(another.getStreet()));
}