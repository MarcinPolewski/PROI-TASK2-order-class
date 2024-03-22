#include <gtest/gtest.h>

#include "order.h"
#include "date.h"
#include "statusCodes.h"
#include "product.h"
#include "orderListElement.h"
#include "address.h"

// testing date class
TEST(date, date_init_and_getters_1)
{
    date a = date(1, 2, 3);
    ASSERT_EQ(a.getDay(), 1);
    ASSERT_EQ(a.getMonth(), 2);
    ASSERT_EQ(a.getYear(), 3);
}
TEST(date, date_init_and_getters_2)
{
    date a = date(31, 12, 2222);
    ASSERT_EQ(a.getDay(), 31);
    ASSERT_EQ(a.getMonth(), 12);
    ASSERT_EQ(a.getYear(), 2222);
}

TEST(date, date_init_and_getters_errors)
{
    ASSERT_THROW(date(33, 12, 2222), std::invalid_argument);
    ASSERT_THROW(date(31, 13, 2222), std::invalid_argument);
    ASSERT_THROW(date(33, 13, 2222), std::invalid_argument);
}

TEST(date, date_setDay)
{
    date a = date(31, 12, 2222);
    a.setDay(20);
    ASSERT_EQ(a.getDay(), 20);
    ASSERT_EQ(a.getMonth(), 12);
    ASSERT_EQ(a.getYear(), 2222);
}
TEST(date, date_setDay_error)
{
    date a = date(31, 12, 2222);
    ASSERT_THROW(a.setDay(32), std::invalid_argument);
}

TEST(date, date_setMonth)
{
    date a = date(31, 12, 2222);
    a.setMonth(1);
    ASSERT_EQ(a.getDay(), 31);
    ASSERT_EQ(a.getMonth(), 1);
    ASSERT_EQ(a.getYear(), 2222);
}
TEST(date, date_setMonth_error)
{
    date a = date(31, 12, 2222);
    ASSERT_THROW(a.setMonth(13), std::invalid_argument);
}

TEST(date, date_setYear)
{
    date a = date(31, 12, 2222);
    a.setYear(1111);
    ASSERT_EQ(a.getDay(), 31);
    ASSERT_EQ(a.getMonth(), 12);
    ASSERT_EQ(a.getYear(), 1111);
}

TEST(date, date_setDate)
{
    date a = date(31, 12, 2222);
    a.setDate(1, 2, 3);
    ASSERT_EQ(a.getDay(), 1);
    ASSERT_EQ(a.getMonth(), 2);
    ASSERT_EQ(a.getYear(), 3);
}

TEST(date, date_getDateStr)
{
    date a = date(31, 12, 2222);
    ASSERT_EQ(a.getDateStr(), "31.12.2222");
}

TEST(date, date_equals_operator_true)
{
    date a = date(31, 12, 2222);
    date b = date(31, 12, 2222);

    ASSERT_EQ(a == b, true);
}
TEST(date, date_equals_operator_false)
{
    date a = date(31, 12, 2222);
    date b1 = date(30, 12, 2222);
    date b2 = date(31, 11, 2222);
    date b3 = date(31, 12, 2221);

    ASSERT_EQ(a == b1, false);
    ASSERT_EQ(a == b2, false);
    ASSERT_EQ(a == b3, false);
}

// testing product
TEST(product, product_init_and_getters_1)
{
    product p = product("banan", 1, 5);
    ASSERT_EQ(p.getName(), "banan");
    ASSERT_EQ(p.getIdNumber(), 1);
    ASSERT_EQ(p.getPriceInGr(), 5);
}

TEST(product, product_setName)
{
    product p = product("jablko", 2, 5);

    p.setName("kiwi");
    ASSERT_EQ(p.getName(), "kiwi");
    ASSERT_EQ(p.getIdNumber(), 2);
    ASSERT_EQ(p.getPriceInGr(), 5);
}

TEST(product, product_setIdNumber)
{
    product p = product("jablko", 5, 15);

    p.setIdNumber(10);
    ASSERT_EQ(p.getName(), "jablko");
    ASSERT_EQ(p.getIdNumber(), 10);
    ASSERT_EQ(p.getPriceInGr(), 15);
}

TEST(product, product_setPriceInGr)
{
    product p = product("jablko", 5, 15);

    p.setPriceInGr(100);
    ASSERT_EQ(p.getName(), "jablko");
    ASSERT_EQ(p.getIdNumber(), 5);
    ASSERT_EQ(p.getPriceInGr(), 100);
}

TEST(product, product_equals_operator_equal)
{
    product p1 = product("jablko", 5, 15);
    product p2 = product("jablko", 5, 15);
    ASSERT_EQ(p1 == p2, true);
    // ASSERT_EQ(p1, p2); <- tak nie działa :(
}

TEST(product, product_equals_operator_not_equal)
{
    product p1 = product("jablko", 5, 15);
    product p2 = product("gruszka", 10, 15);
    ASSERT_EQ(p1 == p2, false);
    // ASSERT_EQ(p1, p2); <- tak nie działa :(
}

TEST(product, product_order_operator)
{
    product p1 = product("jablko", 5, 15);
    product p2 = product("gruszka", 10, 15);

    ASSERT_EQ(p1 < p2, true);
    ASSERT_EQ(p1 > p2, false);
    ASSERT_EQ(p2 > p1, true);
    ASSERT_EQ(p2 < p1, false);
}

// testing orderListElement
TEST(orderListElement, orderListElement_init_and_getters)
{
    product p = product("jablko", 5, 15);
    orderListElement element = orderListElement(p, 10);

    ASSERT_EQ(element.getProduct() == p, true);
    ASSERT_EQ(element.getQuantitiy(), 10);
    ASSERT_EQ(element.getTotalPriceGr(), 10 * 15);
}

TEST(orderListElement, orderListElement_equals_operator)
{
    product p = product("jablko", 5, 15);
    orderListElement element1 = orderListElement(p, 10);
    orderListElement element2 = orderListElement(p, 10);

    ASSERT_EQ(element1 == element2, true);
}

TEST(orderListElement, orderListElement_set_product)
{
    product p1 = product("jablko", 5, 15);
    product p2 = product("banan", 111, 399);

    orderListElement element = orderListElement(p1, 10);

    element.setProduct(p2);
    ASSERT_EQ(element.getProduct() == p2, true);
}

TEST(orderListElement, orderListElement_setQuantity)
{
    product p1 = product("jablko", 5, 15);
    orderListElement element = orderListElement(p1, 10);

    element.setQuantity(555);
    ASSERT_EQ(element.getQuantitiy(), 555);
}

// testing address class
TEST(address, address_init_and_getters)
{
    std::string country = "Poland";
    std::string city = "Warsaw";
    int postalCode = 12345;
    std::string street = "Nowowiejska";
    int houseNumber = 5;

    address a = address(country, city, postalCode, street, houseNumber);
    ASSERT_EQ("Poland" == a.getCountry(), true);
    ASSERT_EQ("Warsaw" == a.getCity(), true);
    ASSERT_EQ(12345, a.getPostalCode());
    ASSERT_EQ("Nowowiejska" == a.getStreet(), true);
    ASSERT_EQ(houseNumber, a.getHouseNumber());
}

TEST(address, address_set_city)
{
    std::string country = "Poland";
    std::string city = "Bydoszcz";
    int postalCode = 12345;
    std::string street = "Nowowiejska";
    int houseNumber = 5;

    address a = address(country, city, postalCode, street, houseNumber);
    std::string newCity = "Warsaw";
    a.setCity(newCity);

    ASSERT_EQ("Poland" == a.getCountry(), true);
    ASSERT_EQ("Warsaw" == a.getCity(), true);
    ASSERT_EQ(12345, a.getPostalCode());
    ASSERT_EQ("Nowowiejska" == a.getStreet(), true);
    ASSERT_EQ(houseNumber, a.getHouseNumber());
}

TEST(address, address_set_country)
{
    std::string country = "Findland";
    std::string city = "Warsaw";
    int postalCode = 12345;
    std::string street = "Nowowiejska";
    int houseNumber = 5;

    address a = address(country, city, postalCode, street, houseNumber);
    std::string newCountry = "Poland";
    a.setCountry(newCountry);

    ASSERT_EQ("Poland" == a.getCountry(), true);
    ASSERT_EQ("Warsaw" == a.getCity(), true);
    ASSERT_EQ(12345, a.getPostalCode());
    ASSERT_EQ("Nowowiejska" == a.getStreet(), true);
    ASSERT_EQ(houseNumber, a.getHouseNumber());
}

TEST(address, address_set_potal_code)
{
    std::string country = "Poland";
    std::string city = "Warsaw";
    int postalCode = 54321;
    std::string street = "Nowowiejska";
    int houseNumber = 5;

    address a = address(country, city, postalCode, street, houseNumber);
    a.setPostalCode(12345);

    ASSERT_EQ("Poland" == a.getCountry(), true);
    ASSERT_EQ("Warsaw" == a.getCity(), true);
    ASSERT_EQ(12345, a.getPostalCode());
    ASSERT_EQ("Nowowiejska" == a.getStreet(), true);
    ASSERT_EQ(houseNumber, a.getHouseNumber());
}

TEST(address, address_set_street)
{
    std::string country = "Poland";
    std::string city = "Warsaw";
    int postalCode = 12345;
    std::string street = "Bukowa";
    int houseNumber = 5;

    address a = address(country, city, postalCode, street, houseNumber);
    std::string newStreet = "Nowowiejska";
    a.setStreet(newStreet);

    ASSERT_EQ("Poland" == a.getCountry(), true);
    ASSERT_EQ("Warsaw" == a.getCity(), true);
    ASSERT_EQ(12345, a.getPostalCode());
    ASSERT_EQ("Nowowiejska" == a.getStreet(), true);
    ASSERT_EQ(houseNumber, a.getHouseNumber());
}

TEST(address, address_set_house_number)
{
    std::string country = "Poland";
    std::string city = "Warsaw";
    int postalCode = 12345;
    std::string street = "Nowowiejska";
    int houseNumber = 85;

    address a = address(country, city, postalCode, street, houseNumber);
    a.setHouseNumber(5);
    ASSERT_EQ("Poland" == a.getCountry(), true);
    ASSERT_EQ("Warsaw" == a.getCity(), true);
    ASSERT_EQ(12345, a.getPostalCode());
    ASSERT_EQ("Nowowiejska" == a.getStreet(), true);
    ASSERT_EQ(5, a.getHouseNumber());
}

TEST(address, address_equals_operator_true)
{
    std::string country = "Poland";
    std::string city = "Warsaw";
    int postalCode = 12345;
    std::string street = "Nowowiejska";
    int houseNumber = 5;

    address a1 = address(country, city, postalCode, street, houseNumber);
    address a2 = address(country, city, postalCode, street, houseNumber);
    ASSERT_EQ(a1 == a2, true);
}

TEST(address, address_equals_operator_false)
{
    std::string country = "Poland";
    std::string city = "Warsaw";
    int postalCode = 12345;
    std::string street = "Nowowiejska";
    int houseNumber = 5;

    address a1 = address(country, city, postalCode, street, houseNumber);
    address a2 = address(country, city, postalCode, street, houseNumber);
    std::string newStreet = "Sosnowa";
    a2.setStreet(newStreet);

    ASSERT_EQ(a1 == a2, false);
}
// testing order class
TEST(order, order_init_and_getters_1)
{
    date d = date(31, 12, 2030);
    product p1 = product("banan", 1, 399);
    product p2 = product("orange", 2, 499);
    product p3 = product("yoghurt", 3, 199);

    orderListElement element1 = orderListElement(p1, 5);
    orderListElement element2 = orderListElement(p2, 10);
    orderListElement element3 = orderListElement(p3, 15);
    std::vector<orderListElement> prodList = {element1, element2, element3};

    std::string country = "Poland";
    std::string city = "Warsaw";
    int postalCode = 12345;
    std::string street = "Nowowiejska";
    int houseNumber = 5;

    address a = address(country, city, postalCode, street, houseNumber);

    std::string name = "Jorek";
    std::string surname = "Ogorek";

    order o = order(name, surname, d, prodList, a);
    ASSERT_EQ(o.getDate() == d, true);
    ASSERT_EQ(o.getName() == name, true);
    ASSERT_EQ(o.getSurname() == surname, true);
    ASSERT_EQ(o.getShipmentAddress() == a, true);
    ASSERT_EQ(o.getStatusCode(), orderStatus::ORDER_PLACED);
    ASSERT_EQ(o.getProductList()[0] == element1, true);
    ASSERT_EQ(o.getProductList()[1] == element2, true);
    ASSERT_EQ(o.getProductList()[2] == element3, true);
}

TEST(order, order_init_and_getters_2)
{
    date d = date(31, 12, 2030);
    product p1 = product("banan", 1, 399);
    product p2 = product("orange", 2, 499);
    product p3 = product("yoghurt", 3, 199);

    orderListElement element1 = orderListElement(p1, 5);
    orderListElement element2 = orderListElement(p2, 10);
    orderListElement element3 = orderListElement(p3, 15);
    std::vector<orderListElement> prodList = {element1, element2, element3};

    std::string country = "Poland";
    std::string city = "Warsaw";
    int postalCode = 12345;
    std::string street = "Nowowiejska";
    int houseNumber = 5;

    address a = address(country, city, postalCode, street, houseNumber);

    std::string name = "Jorek";
    std::string surname = "Ogorek";

    order o = order(name, surname, d, prodList, orderStatus::SENT, a);
    ASSERT_EQ(o.getDate() == d, true);
    ASSERT_EQ(o.getName() == name, true);
    ASSERT_EQ(o.getSurname() == surname, true);
    ASSERT_EQ(o.getShipmentAddress() == a, true);
    ASSERT_EQ(o.getStatusCode(), orderStatus::SENT);
    ASSERT_EQ(o.getProductList()[0] == element1, true);
    ASSERT_EQ(o.getProductList()[1] == element2, true);
    ASSERT_EQ(o.getProductList()[2] == element3, true);
}

TEST(order, order_setName)
{
    date d = date(31, 12, 2030);
    product p1 = product("banan", 1, 399);
    product p2 = product("orange", 2, 499);
    product p3 = product("yoghurt", 3, 199);

    orderListElement element1 = orderListElement(p1, 5);
    orderListElement element2 = orderListElement(p2, 10);
    orderListElement element3 = orderListElement(p3, 15);
    std::vector<orderListElement> prodList = {element1, element2, element3};

    std::string country = "Poland";
    std::string city = "Warsaw";
    int postalCode = 12345;
    std::string street = "Nowowiejska";
    int houseNumber = 5;

    address a = address(country, city, postalCode, street, houseNumber);

    std::string name = "Jorek";
    std::string surname = "Ogorek";

    order o = order(name, surname, d, prodList, orderStatus::SENT, a);
    std::string newName = "babab";
    o.setName(newName);
    ASSERT_EQ(o.getName() == newName, true);
}

TEST(order, order_setSurname)
{
    date d = date(31, 12, 2030);
    product p1 = product("banan", 1, 399);
    product p2 = product("orange", 2, 499);
    product p3 = product("yoghurt", 3, 199);

    orderListElement element1 = orderListElement(p1, 5);
    orderListElement element2 = orderListElement(p2, 10);
    orderListElement element3 = orderListElement(p3, 15);
    std::vector<orderListElement> prodList = {element1, element2, element3};

    std::string country = "Poland";
    std::string city = "Warsaw";
    int postalCode = 12345;
    std::string street = "Nowowiejska";
    int houseNumber = 5;

    address a = address(country, city, postalCode, street, houseNumber);

    std::string name = "Jorek";
    std::string surname = "Ogorek";

    order o = order(name, surname, d, prodList, orderStatus::SENT, a);
    std::string newSurname = "babab";
    o.setSurname(newSurname);
    ASSERT_EQ(o.getSurname() == newSurname, true);
}

TEST(order, order_setDate)
{
    date d1 = date(31, 12, 2030);
    product p1 = product("banan", 1, 399);
    product p2 = product("orange", 2, 499);
    product p3 = product("yoghurt", 3, 199);

    orderListElement element1 = orderListElement(p1, 5);
    orderListElement element2 = orderListElement(p2, 10);
    orderListElement element3 = orderListElement(p3, 15);
    std::vector<orderListElement> prodList = {element1, element2, element3};

    std::string country = "Poland";
    std::string city = "Warsaw";
    int postalCode = 12345;
    std::string street = "Nowowiejska";
    int houseNumber = 5;

    address a = address(country, city, postalCode, street, houseNumber);

    std::string name = "Jorek";
    std::string surname = "Ogorek";

    order o = order(name, surname, d1, prodList, orderStatus::SENT, a);
    date d2 = date(1, 1, 1111);
    o.setDate(d2);
    ASSERT_EQ(o.getDate() == d2, true);
}

TEST(order, order_setProductList)
{
    date d1 = date(31, 12, 2030);
    product p1 = product("banan", 1, 399);
    product p2 = product("orange", 2, 499);
    product p3 = product("yoghurt", 3, 199);
    product p4 = product("bread", 5, 799);

    orderListElement element1 = orderListElement(p1, 5);
    orderListElement element2 = orderListElement(p2, 10);
    orderListElement element3 = orderListElement(p3, 15);
    orderListElement element4 = orderListElement(p4, 20);
    std::vector<orderListElement> prodList1 = {element1, element2};
    std::vector<orderListElement> prodList2 = {element3, element4};

    std::string country = "Poland";
    std::string city = "Warsaw";
    int postalCode = 12345;
    std::string street = "Nowowiejska";
    int houseNumber = 5;

    address a = address(country, city, postalCode, street, houseNumber);

    std::string name = "Jorek";
    std::string surname = "Ogorek";

    order o = order(name, surname, d1, prodList1, orderStatus::SENT, a);
    o.setProductList(prodList2);
    ASSERT_EQ(o.getProductList()[0] == element3, true);
    ASSERT_EQ(o.getProductList()[1] == element4, true);
}

TEST(order, order_setShipmentAddress)
{
    date d1 = date(31, 12, 2030);
    product p1 = product("banan", 1, 399);
    product p2 = product("orange", 2, 499);
    product p3 = product("yoghurt", 3, 199);
    product p4 = product("bread", 5, 799);

    orderListElement element1 = orderListElement(p1, 5);
    orderListElement element2 = orderListElement(p2, 10);
    orderListElement element3 = orderListElement(p3, 15);
    orderListElement element4 = orderListElement(p4, 20);
    std::vector<orderListElement> prodList1 = {element1, element2};
    std::vector<orderListElement> prodList2 = {element3, element4};

    std::string country = "Poland";
    std::string city = "Warsaw";
    int postalCode = 12345;
    std::string street = "Nowowiejska";
    int houseNumber = 5;

    address a1 = address(country, city, postalCode, street, houseNumber);

    std::string country2 = "Sweden";
    std::string city2 = "Stockholm";
    int postalCode2 = 2354;
    std::string street2 = "Warszawska";
    int houseNumber2 = 15;

    address a2 = address(country2, city2, postalCode2, street2, houseNumber2);

    std::string name = "Jorek";
    std::string surname = "Ogorek";

    order o = order(name, surname, d1, prodList1, orderStatus::SENT, a1);
    o.setShipmentAddress(a2);
    ASSERT_EQ(o.getShipmentAddress() == a2, true);
}

TEST(order, order_addElement)
{
    date d1 = date(31, 12, 2030);
    product p1 = product("banan", 1, 399);
    product p2 = product("orange", 2, 499);
    product p3 = product("yoghurt", 3, 199);
    product p4 = product("bread", 5, 799);

    orderListElement element1 = orderListElement(p1, 5);
    orderListElement element2 = orderListElement(p2, 10);
    orderListElement element3 = orderListElement(p3, 15);
    orderListElement element4 = orderListElement(p4, 20);
    std::vector<orderListElement> prodList1 = {element4, element3};

    std::string country = "Poland";
    std::string city = "Warsaw";
    int postalCode = 12345;
    std::string street = "Nowowiejska";
    int houseNumber = 5;

    address a1 = address(country, city, postalCode, street, houseNumber);

    std::string name = "Jorek";
    std::string surname = "Ogorek";

    order o = order(name, surname, d1, prodList1, orderStatus::SENT, a1);
    ASSERT_EQ(o.getProductList()[0] == element3, true);
    ASSERT_EQ(o.getProductList()[1] == element4, true);

    o.addListElement(element2);
    ASSERT_EQ(o.getProductList()[0] == element2, true);
    ASSERT_EQ(o.getProductList()[1] == element3, true);
    ASSERT_EQ(o.getProductList()[2] == element4, true);

    o.addListElement(element1);
    ASSERT_EQ(o.getProductList()[0] == element1, true);
    ASSERT_EQ(o.getProductList()[1] == element2, true);
    ASSERT_EQ(o.getProductList()[2] == element3, true);
    ASSERT_EQ(o.getProductList()[3] == element4, true);
}

TEST(order, order_addElement_empty_list_at_start)
{
    date d1 = date(31, 12, 2030);
    product p1 = product("banan", 1, 399);
    product p2 = product("orange", 2, 499);
    product p3 = product("yoghurt", 3, 199);
    product p4 = product("bread", 5, 799);

    orderListElement element1 = orderListElement(p1, 5);
    orderListElement element2 = orderListElement(p2, 10);
    orderListElement element3 = orderListElement(p3, 15);
    orderListElement element4 = orderListElement(p4, 20);
    std::vector<orderListElement> prodList1;

    std::string country = "Poland";
    std::string city = "Warsaw";
    int postalCode = 12345;
    std::string street = "Nowowiejska";
    int houseNumber = 5;

    address a1 = address(country, city, postalCode, street, houseNumber);

    std::string name = "Jorek";
    std::string surname = "Ogorek";

    order o = order(name, surname, d1, prodList1, orderStatus::SENT, a1);

    o.addListElement(element4);
    ASSERT_EQ(o.getProductList()[0] == element4, true);

    o.addListElement(element3);
    ASSERT_EQ(o.getProductList()[0] == element3, true);
    ASSERT_EQ(o.getProductList()[1] == element4, true);

    o.addListElement(element2);
    ASSERT_EQ(o.getProductList()[0] == element2, true);
    ASSERT_EQ(o.getProductList()[1] == element3, true);
    ASSERT_EQ(o.getProductList()[2] == element4, true);

    o.addListElement(element1);
    ASSERT_EQ(o.getProductList()[0] == element1, true);
    ASSERT_EQ(o.getProductList()[1] == element2, true);
    ASSERT_EQ(o.getProductList()[2] == element3, true);
    ASSERT_EQ(o.getProductList()[3] == element4, true);
}

TEST(order, order_addElement_array_sorted)
{
    date d1 = date(31, 12, 2030);
    product p1 = product("banan", 1, 399);
    product p2 = product("orange", 2, 499);
    product p3 = product("yoghurt", 3, 199);
    product p4 = product("bread", 5, 799);

    orderListElement element1 = orderListElement(p1, 5);
    orderListElement element2 = orderListElement(p2, 10);
    orderListElement element3 = orderListElement(p3, 15);
    orderListElement element4 = orderListElement(p4, 20);
    std::vector<orderListElement> prodList1;

    std::string country = "Poland";
    std::string city = "Warsaw";
    int postalCode = 12345;
    std::string street = "Nowowiejska";
    int houseNumber = 5;

    address a1 = address(country, city, postalCode, street, houseNumber);

    std::string name = "Jorek";
    std::string surname = "Ogorek";

    order o = order(name, surname, d1, prodList1, orderStatus::SENT, a1);

    o.addListElement(element1);
    ASSERT_EQ(o.getProductList()[0] == element1, true);

    o.addListElement(element2);
    ASSERT_EQ(o.getProductList()[0] == element1, true);
    ASSERT_EQ(o.getProductList()[1] == element2, true);

    o.addListElement(element3);
    ASSERT_EQ(o.getProductList()[0] == element1, true);
    ASSERT_EQ(o.getProductList()[1] == element2, true);
    ASSERT_EQ(o.getProductList()[2] == element3, true);

    o.addListElement(element4);
    ASSERT_EQ(o.getProductList()[0] == element1, true);
    ASSERT_EQ(o.getProductList()[1] == element2, true);
    ASSERT_EQ(o.getProductList()[2] == element3, true);
    ASSERT_EQ(o.getProductList()[3] == element4, true);
}

TEST(order, order_addElement_duplicate)
{
    date d1 = date(31, 12, 2030);
    product p1 = product("banan", 1, 399);
    product p2 = product("orange", 2, 499);
    product p3 = product("yoghurt", 3, 199);
    product p4 = product("bread", 5, 799);

    orderListElement element1 = orderListElement(p1, 5);
    orderListElement element2 = orderListElement(p2, 10);
    orderListElement element3 = orderListElement(p3, 15);
    orderListElement element4 = orderListElement(p4, 20);
    orderListElement element5 = orderListElement(p4, 10);

    std::vector<orderListElement> prodList1 = {element1, element2, element3, element4};

    std::string country = "Poland";
    std::string city = "Warsaw";
    int postalCode = 12345;
    std::string street = "Nowowiejska";
    int houseNumber = 5;

    address a1 = address(country, city, postalCode, street, houseNumber);

    std::string name = "Jorek";
    std::string surname = "Ogorek";

    order o = order(name, surname, d1, prodList1, orderStatus::SENT, a1);

    o.addListElement(element5);
    ASSERT_EQ(o.getProductList()[0] == element1, true);
    ASSERT_EQ(o.getProductList()[1] == element2, true);
    ASSERT_EQ(o.getProductList()[2] == element3, true);
    ASSERT_EQ(o.getProductList()[3].getQuantitiy(), 30);
    ASSERT_EQ(o.getProductList()[3].getProduct() == p4, true);
}

TEST(order, order_findProduct)
{
    date d1 = date(31, 12, 2030);
    product p1 = product("banan", 1, 399);
    product p2 = product("orange", 2, 499);
    product p3 = product("yoghurt", 3, 199);
    product p4 = product("bread", 5, 799);

    orderListElement element1 = orderListElement(p1, 5);
    orderListElement element2 = orderListElement(p2, 10);
    orderListElement element3 = orderListElement(p3, 15);
    orderListElement element4 = orderListElement(p4, 20);
    std::vector<orderListElement> prodList1 = {element1, element2, element3, element4};

    std::string country = "Poland";
    std::string city = "Warsaw";
    int postalCode = 12345;
    std::string street = "Nowowiejska";
    int houseNumber = 5;

    address a1 = address(country, city, postalCode, street, houseNumber);

    std::string name = "Jorek";
    std::string surname = "Ogorek";

    order o = order(name, surname, d1, prodList1, a1);
    std::vector<orderListElement>::iterator baseIt = o.getProductList().begin();

    ASSERT_EQ(o.findProduct(1), baseIt);
    ASSERT_EQ(o.findProduct(2), baseIt + 1);
    ASSERT_EQ(o.findProduct(3), baseIt + 2);
    ASSERT_EQ(o.findProduct(5), baseIt + 3);
}

TEST(order, order_findProduct_no_such_product)
{
    date d1 = date(31, 12, 2030);
    product p1 = product("banan", 1, 399);
    product p2 = product("orange", 2, 499);
    product p3 = product("yoghurt", 3, 199);
    product p4 = product("bread", 5, 799);

    orderListElement element1 = orderListElement(p1, 5);
    orderListElement element2 = orderListElement(p2, 10);
    orderListElement element3 = orderListElement(p3, 15);
    orderListElement element4 = orderListElement(p4, 20);
    std::vector<orderListElement> prodList1 = {element1, element2, element3, element4};

    std::string country = "Poland";
    std::string city = "Warsaw";
    int postalCode = 12345;
    std::string street = "Nowowiejska";
    int houseNumber = 5;

    address a1 = address(country, city, postalCode, street, houseNumber);

    std::string name = "Jorek";
    std::string surname = "Ogorek";

    order o = order(name, surname, d1, prodList1, a1);
    std::vector<orderListElement>::iterator endIt = o.getProductList().end();

    ASSERT_EQ(o.findProduct(-1), endIt);
    ASSERT_EQ(o.findProduct(10), endIt);
}