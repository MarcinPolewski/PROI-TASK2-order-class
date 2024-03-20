#pragma once
#include <string>

class product
{
    std::string name;
    unsigned int idNumber;

public:
    // constructors
    product(std::string name, unsigned int idNumber);
    product() = default;

    // getters and setters
    void setName(std::string name);
    std::string getName() const;

    void setIdNumber(unsigned int id);
    unsigned int getIdNumber() const;
};