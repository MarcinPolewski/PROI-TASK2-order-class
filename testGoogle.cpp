#include <gtest/gtest.h>
#include "order.h"
#include "date.h"

// testing date class

TEST(date, testing_if_tests_work)
{
    date a = date(1, 2, 3);
    ASSERT_EQ(a.getDay(), 5);
    ASSERT_EQ(a.getMonth(), 5);
    ASSERT_EQ(a.getYear(), 3);
}

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

TEST(date, date_init_and_getters_wrong_input)
{
    // sprawdzamy czy błędu nie wyrzuciu
    date a = date(33, 12, 2222);
    date b = date(31, 13, 2222);
    date c = date(33, 13, 123);
}

TEST(date, date_setDay)
{
    date a = date(31, 12, 2222);
    a.setDay(20);
    ASSERT_EQ(a.getDay(), 20);
    ASSERT_EQ(a.getMonth(), 12);
    ASSERT_EQ(a.getYear(), 2222);
}
TEST(date, date_setDay_wrong_input)
{
    date a = date(31, 12, 2222);
    a.setDay(32);
    ASSERT_EQ(a.getDay(), 31);
    ASSERT_EQ(a.getMonth(), 12);
    ASSERT_EQ(a.getYear(), 2222);
}

TEST(date, date_setMonth)
{
    date a = date(31, 12, 2222);
    a.setMonth(1);
    ASSERT_EQ(a.getDay(), 31);
    ASSERT_EQ(a.getMonth(), 1);
    ASSERT_EQ(a.getYear(), 2222);
}
TEST(date, date_setMonth_wrong_input)
{
    date a = date(31, 12, 2222);
    a.setMonth(13);
    ASSERT_EQ(a.getDay(), 31);
    ASSERT_EQ(a.getMonth(), 12);
    ASSERT_EQ(a.getYear(), 2222);
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
    order a = order("aa", "bb", "cc", "dd");
    ASSERT_EQ(a.getName(), "aa");
    ASSERT_EQ(a.getSurname(), "bb");
}

TEST(order, order_init_and_getters_2)
{
    order
}
