#include <gtest/gtest.h>
#include "order.h"
#include "date.h"
#include "statusCodes.h"

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

// testing order class
TEST(order, order_init_and_getters_1)
{
    date d = date(31, 12, 2012);
    std::vector<std::string> pl = {"banan", "gruszka", "kiwi"};

    order a = order("name", "surname", d, pl, SENT, "Warszawa, plac politechniki 1");
    ASSERT_EQ(a.getName(), "name");
    ASSERT_EQ(a.getSurname(), "surname");

    date storedDate = a.getDate();
    ASSERT_EQ(storedDate.getDay(), 31);
    ASSERT_EQ(storedDate.getMonth(), 12);
    ASSERT_EQ(storedDate.getYear(), 2012);

    std::vector<std::string> storedList = a.getProductList();
    ASSERT_EQ(storedList[0], "banan");
    ASSERT_EQ(storedList[1], "gruszka");
    ASSERT_EQ(storedList[2], "kiwi");

    ASSERT_EQ(a.getStatusCode(), SENT);
    ASSERT_EQ(a.getShipmentAddress(), "Warszawa, plac politechniki 1");
}
TEST(order, order_init_and_getters_2)
{
    date d = date(31, 12, 2012);
    std::vector<std::string> pl = {"banan", "gruszka", "kiwi"};

    order a = order("name", "surname", d, pl, "Warszawa, plac politechniki 1");
    ASSERT_EQ(a.getName(), "name");
    ASSERT_EQ(a.getSurname(), "surname");

    date storedDate = a.getDate();
    ASSERT_EQ(storedDate.getDay(), 31);
    ASSERT_EQ(storedDate.getMonth(), 12);
    ASSERT_EQ(storedDate.getYear(), 2012);

    std::vector<std::string> storedList = a.getProductList();
    ASSERT_EQ(storedList[0], "banan");
    ASSERT_EQ(storedList[1], "gruszka");
    ASSERT_EQ(storedList[2], "kiwi");

    ASSERT_EQ(a.getStatusCode(), ORDER_PLACED);
    ASSERT_EQ(a.getShipmentAddress(), "Warszawa, plac politechniki 1");
}
TEST(order, order_init_and_getters_3)
{
    date d = date(31, 12, 2012);

    order a = order("name", "surname", d, "Warszawa, plac politechniki 1");
    ASSERT_EQ(a.getName(), "name");
    ASSERT_EQ(a.getSurname(), "surname");

    date storedDate = a.getDate();
    ASSERT_EQ(storedDate.getDay(), 31);
    ASSERT_EQ(storedDate.getMonth(), 12);
    ASSERT_EQ(storedDate.getYear(), 2012);

    ASSERT_EQ(a.getStatusCode(), ORDER_PLACED);
    ASSERT_EQ(a.getShipmentAddress(), "Warszawa, plac politechniki 1");
}

TEST(order, order_init_and_getters_error)
{
    date d = date(31, 12, 2012);
    std::vector<std::string> pl = {"banan", "gruszka", "kiwi"};

    order a = order("name", "surname", d, pl, SENT, "Warszawa, plac politechniki 1");
}

TEST(order, order_init_and_getters_4)
{
    // testing if error does not occur
    order a = order();
}

TEST(order, order_setters_1)
{
    date d = date(31, 12, 2012);
    std::vector<std::string> pl = {"banan", "gruszka", "kiwi"};

    order a = order("name", "surname", d, pl, SENT, "Warszawa, plac politechniki 1");

    a.setName("Marek");
    ASSERT_EQ(a.getName(), "Marek");

    a.setSurname("Kaganek");
    ASSERT_EQ(a.getSurname(), "Kaganek");

    date d1 = date(1, 2, 3);
    a.setDate(d1);
    date storedDate = a.getDate();
    ASSERT_EQ(storedDate.getDay(), 1);
    ASSERT_EQ(storedDate.getMonth(), 2);
    ASSERT_EQ(storedDate.getYear(), 3);

    a.setStatusCode(CANCELED);
    ASSERT_EQ(a.getStatusCode(), CANCELED);

    a.setShipmentAddress("inny address");
    ASSERT_EQ(a.getShipmentAddress(), "inny address");
}