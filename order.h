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
    std::vector<orderListElement> productList;
    orderStatus statusCode = orderStatus::ORDER_PLACED;
    std::string shipmentAddress;

public:
    // full constructor
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

    void setName(std::string newName);
    std::string getName() const;

    void setSurname(std::string newSurname);
    std::string getSurname() const;

    void setDate(date &orderDate);
    const date &getDate() const;

    void setProductList(std::vector<orderListElement> &productList);
    std::vector<orderListElement> &getProductList(); // returning reference, so list can be modified
                                                     // easily somewhere else
    void setStatusCode(orderStatus statusCode);
    orderStatus getStatusCode() const;

    void setShipmentAddress(std::string shipmentAddress);
    std::string getShipmentAddress() const;

    int findProduct(std::string productName); // returns index of procuct, -1 if product is not on the list
};