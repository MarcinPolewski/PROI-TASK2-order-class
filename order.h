#include <string>
#include "statusCodes.h"

class order
{
    std::string name;
    std::string surname;
    std::string date; // zmienić na jakąś klasę ??
    // std::ctime ?
    std::vector<std::string> productList;
    int statusCode;
    std::string shipmentAddress;

public:
    // full constructor
    order(
        std::string name,
        std::string surname,
        std::string date,
        std::vector<std::string> productList,
        int statusCode,
        std::string shipmentAddress);

    // default statusCode
    order(
        std::string name,
        std::string surname,
        std::string date,
        std::vector<std::string> productList,
        std::string shipmentAddress);

    // minimum(should this be even accessible to users?)
    order(
        std::string name,
        std::string surname,
        std::string date,
        std::string shipmentAddress);

    order() = default;

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
};