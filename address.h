#pragma once

#include <string>

class address
{
    std::string country;
    std::string city;
    int postalCode;
    std::string street;
    int houseNumber;

public:
    address(std::string country, std::string city, int postalCode, std::string street, int houseNumber);

    void setCountry(std::string &country);
    const std::string &getCountry() const;

    void setCity(std::string &city);
    const std::string &getCity() const;

    void setPostalCode(int postalCode);
    int getPostalCode() const;

    void setStreet(std::string &street);
    const std::string &getStreet() const;

    void setHouseNumber(int houseNumber);
    int getHouseNumber() const;

    bool operator==(const address &anotherAddress) const;
};