#include "date.h"

date::date(unsigned int day, unsigned int month, unsigned int year)
{
    if (day <= 31 && month <= 12)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }
}

unsigned int date::getDay() const
{
    return day;
}
void date::setDay(unsigned int day)
{
    if (day <= 31)
        this->day = day;
}

unsigned int date::getMonth() const
{
    return month;
}
void date::setMonth(unsigned int month)
{
    if (month <= 12)
        this->month = month;
}

unsigned int date::getYear() const
{
    return year;
}
void date::setYear(unsigned int year)
{
    this->year = year;
}

std::string date::getDateStr() const
{
    return std::to_string(day) +
           '.' + std::to_string(month) +
           '.' + std::to_string(year);
}

void date::setDate(unsigned int day, unsigned int month, unsigned int year)
{
    if (day <= 31 && month <= 12)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }
}