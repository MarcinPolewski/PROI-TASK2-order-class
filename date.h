#include <string>

class date
{
    unsigned int day;
    unsigned int month;
    unsigned int year;

public:
    date(unsigned int day, unsigned int month, unsigned int year);
    date() = default;

    unsigned int getDay() const;
    void setDay(unsigned int day);

    unsigned int getMonth() const;
    void setMonth(unsigned int month);

    unsigned int getYear() const;
    void setYear(unsigned int year);

    void setDate(unsigned int day, unsigned int month, unsigned int year);

    std::string getDateStr() const;
}