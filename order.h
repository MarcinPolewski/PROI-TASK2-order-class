#include <iostream>

class order
{
    std::string name;
    std::string surname;
    // date
    // std::ctime ?
    std::vector<std::string> productList;
    int statusCode;
    std::string shipmentAddress;

public:
    void setName(std::string newName);
    std::string getName() const;

    void setSurname(std::string newSurname);
    std::string getSurname() const;

    void setDate(std::string date);
    std::string getDate() const;

    void setProductList(std::vector<std::string> productList);
    std::vector<std::string> getProductList() const;

    void setStatusCode(int statusCode);
    int getStatusCode() const;

    void setShipmentAddress(std::string shipmentAddress);
    std::string getShipmentAddress() const;
}