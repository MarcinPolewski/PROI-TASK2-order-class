#pragma once

#include <string>
#include "statusCodes.h"
#include "date.h"
#include "orderListElement.h"

class order
{
    std::string name;
    std::string surname;
    date orderDate;
    std::vector<orderListElement> productList = std::vector<orderListElement>(1);
    orderStatus statusCode = ORDER_PLACED;
    std::string shipmentAddress;

public:
    // full constructorf
    order(
        std::string name,
        std::string surname,
        date orderDate,
        std::vector<orderListElement> productList,
        orderStatus statusCode,
        std::string shipmentAddress);

    // default statusCode
    order(
        std::string name,
        std::string surname,
        date orderDate,
        std::vector<orderListElement> productList,
        std::string shipmentAddress);

    // minimum(should this be even accessible to users?)
    order(
        std::string name,
        std::string surname,
        date orderDate,
        std::string shipmentAddress);

    void setName(std::string newName);
    std::string getName() const;

    void setSurname(std::string newSurname);
    std::string getSurname() const;

    void setDate(date orderDate);
    date getDate() const;

    void setProductList(std::vector<orderListElement> &productList);
    std::vector<orderListElement> &getProductList();

    void setStatusCode(orderStatus statusCode);
    orderStatus getStatusCode() const;

    void setShipmentAddress(std::string shipmentAddress);
    std::string getShipmentAddress() const;

    int findProduct(std::string productName); // returns index of procuct, -1 if product is not on the list
};