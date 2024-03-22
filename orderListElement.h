#pragma once

#include "orderListElement.h"
#include "product.h"

class orderListElement
{
    unsigned int quantity;
    product orderProduct = product("a", 1, 1); // bez tego nie działa
    // wyrzuca błąd ze product nie ma defaultowego konstruktora i ze
    // klasa musi zostac zainicjalizowana

public:
    orderListElement(product orderProduct, unsigned int quantity);

    void setProduct(product orderProduct);
    product getProduct() const;

    void setQuantity(unsigned int quantity);
    unsigned int getQuantitiy() const;

    unsigned int getTotalPriceGr() const;

    bool operator==(const orderListElement &anotherElement);
};