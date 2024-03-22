#include "order.h"

// constructors
order::order(
    std::string name,
    std::string surname,
    date orderDate,
    std::vector<orderListElement> productList,
    orderStatus statusCode,
    address shipmentAddress)
{
    // sorting array accoring to idNumber
    std::sort(productList.begin(), productList.end(), [](const auto &left, const auto &right)
              { return left.getProduct() < right.getProduct(); });

    this->name = name;
    this->surname = surname;
    this->orderDate = orderDate;
    this->productList = productList;
    this->statusCode = statusCode;
    this->shipmentAddress = shipmentAddress;
}

order::order(
    std::string name,
    std::string surname,
    date orderDate,
    std::vector<orderListElement> productList,
    address shipmentAddress)
{
    // sorting array accoring to idNumber
    std::sort(productList.begin(), productList.end(), [](const auto &left, const auto &right)
              { return left.getProduct() < right.getProduct(); });

    this->name = name;
    this->surname = surname;
    this->orderDate = orderDate;
    this->productList = productList;
    this->shipmentAddress = shipmentAddress;
}

// getters and setters
void order::setName(std::string newName)
{
    this->name = newName;
}
std::string order::getName() const { return name; }

void order::setSurname(std::string newSurname) { this->surname = newSurname; }
std::string order::getSurname() const { return surname; }

void order::setDate(date &orderDate) { this->orderDate = orderDate; }
const date &order::getDate() const { return orderDate; }

void order::setProductList(std::vector<orderListElement> &productList) { this->productList = productList; }
std::vector<orderListElement> &order::getProductList() { return productList; }

void order::setStatusCode(orderStatus statusCode) { this->statusCode = statusCode; }
orderStatus order::getStatusCode() const { return statusCode; }

void order::setShipmentAddress(address &shipmentAddress) { this->shipmentAddress = shipmentAddress; }
const address &order::getShipmentAddress() const { return shipmentAddress; }

std::vector<orderListElement>::iterator order::findProduct(product seekedProduct)
{
    return findProduct(seekedProduct.getIdNumber());
}

std::vector<orderListElement>::iterator order::findProduct(int productId)
{
    int l = 0, r = productList.size() - 1, mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (productId == productList[mid].getProduct().getIdNumber())
            return productList.begin() + mid;
        if (productId > productList[mid].getProduct().getIdNumber())
            l = mid + 1;
        else
            r = mid - 1;
    }
    return productList.end();
}
void order::addListElement(orderListElement &newElement)
{
    // 1. check if such product is on list
    std::vector<orderListElement>::iterator foundElementIt = findProduct(newElement.getProduct());
    if (foundElementIt != productList.end()) // if element was found, we just add quantities
    {
        unsigned int newQuantity = (*foundElementIt).getQuantitiy() + newElement.getQuantitiy();
        (*foundElementIt).setQuantity(newQuantity);
        return;
    }

    // 2. extending the array
    productList.push_back(newElement);

    if (productList.size() == 1)
        return;

    // 3. placing the element into sorted array
    int it = productList.size() - 2; // index in array indicating currently compared element
    // moving bigger elements to the right side of the array
    while (it >= 0 && newElement.getProduct() < (*(productList.begin() + it)).getProduct())
    {
        *(productList.begin() + it + 1) = *(productList.begin() + it);
        --it;
    }
    *(productList.begin() + it + 1) = newElement;
}
void order::removeProduct(int productId)
{
    std::vector<orderListElement>::iterator foundElementIt = findProduct(productId);
    if (foundElementIt != productList.end()) // if element was found, it's removed from the list
    {
        productList.erase(foundElementIt);
    }
}

void order::removeProduct(product productToRemove)
{
    removeProduct(productToRemove.getIdNumber());
}

int order::getTotalPriceInGr()
{
    int sum = 0;
    for (auto it : productList)
    {
        sum += it.getTotalPriceGr();
    }
    return sum;
}
int order::getTotalNumberOfProducts()
{
    int counter = 0;
    for (auto it : productList)
    {
        counter += it.getQuantitiy();
    }

    return counter;
}