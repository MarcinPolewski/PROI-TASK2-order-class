#pragma once

#include <string>
#include "statusCodes.h"
#include "date.h"
#include "orderListElement.h"
#include "address.h"

class order
{
    std::string name;
    std::string surname;
    date orderDate;
    std::vector<orderListElement> productList;
    orderStatus statusCode = orderStatus::ORDER_PLACED;
    address shipmentAddress = address("a", "b", 1, "c", 1); // bez tego komilator krzyczy ze wartosc nie zainicjowana

public:
    // full constructor
    order(
        std::string name,
        std::string surname,
        date orderDate,
        std::vector<orderListElement> productList,
        orderStatus statusCode,
        address shipmentAddress);

    // default statusCode
    order(
        std::string name,
        std::string surname,
        date orderDate,
        std::vector<orderListElement> productList,
        address shipmentAddress);

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

    void setShipmentAddress(address &shipmentAddress);
    const address &getShipmentAddress() const;

    std::vector<orderListElement>::iterator findProduct(int productId);
    std::vector<orderListElement>::iterator findProduct(product seekedProduct);
    void addListElement(orderListElement &newElement);
    void removeProduct(int productId);
    void removeProduct(product productToRemove);
    int getTotalPriceInGr();
    int getTotalNumberOfProducts();
};