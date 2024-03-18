#pragma once

#include <string>
#include "statusCodes.h"
#include "date.h"

class order
{
    std::string name;
    std::string surname;
    date orderDate; // zmienić na jakąś klasę ??
    std::vector<std::string> productList;
    int statusCode;
    std::string shipmentAddress;

public:
    // full constructorf
    order(
        std::string name,
        std::string surname,
        date orderDate,
        std::vector<std::string> productList,
        int statusCode,
        std::string shipmentAddress);

    // default statusCode
    order(
        std::string name,
        std::string surname,
        date orderDate,
        std::vector<std::string> productList,
        std::string shipmentAddress);

    // minimum(should this be even accessible to users?)
    order(
        std::string name,
        std::string surname,
        date orderDate,
        std::string shipmentAddress);

    order() = default;

    void setName(std::string newName);
    std::string getName() const;

    void setSurname(std::string newSurname);
    std::string getSurname() const;

    void setDate(date orderDate);
    date getDate() const;

    void setProductList(std::vector<std::string> productList);
    std::vector<std::string> getProductList() const;

    void setStatusCode(int statusCode);
    int getStatusCode() const;

    void setShipmentAddress(std::string shipmentAddress);
    std::string getShipmentAddress() const;
};