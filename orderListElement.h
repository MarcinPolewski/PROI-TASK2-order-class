#pragma once

#include "orderListElement.h"
#include "product.h"

class orderListElement
{
    unsigned int quantity;
    product orderProduct;

public:
    orderListElement(product orderProduct, unsigned int quantity);
    orderListElement(){};

    void setProduct(product orderProduct);
    product getProduct() const;

    void setQuantity(unsigned int quantity);
    unsigned int getQuantitiy() const;

    unsigned int getTotalPriceGr() const;
};