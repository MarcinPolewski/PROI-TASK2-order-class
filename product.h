#pragma once
#include <string>

class product
{
    std::string name;
    unsigned int idNumber;
    unsigned int priceInGr;

public:
    // constructors
    product(std::string name, unsigned int idNumber, unsigned int price);

    // getters and setters
    void setName(std::string name);
    std::string getName() const;

    void setIdNumber(unsigned int id);
    unsigned int getIdNumber() const;

    void setPriceInGr(unsigned int price);
    unsigned int getPriceInGr() const;

    bool operator==(const product &p);
};