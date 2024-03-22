#include <iostream>
#include <string>
#include "order.h"

int main(int argc, char *argv[])
{

    if (argc != 12)
    {
        std::cout << "invalid number of argumets, proceed according to instruction:\n";
        std::cout << "pass values consequantly name, surname, country, city,"
                  << " postal code, street, house number, quantity of each product:\n"
                  << "1. banana\n2. orange\n3. yoghurt\n4. bread\n\nfor instance:"
                  << "Jorek Ogorek Poland Warsaw 12345 Nowowiejska 5 3 0 5 6\n";
        return 2;
    }

    date d = date(31, 12, 2030);
    product p1 = product("banan", 1, 399);
    product p2 = product("orange", 2, 499);
    product p3 = product("yoghurt", 3, 199);
    product p4 = product("bread", 4, 799);

    std::vector<orderListElement> prodList;
    try
    {
        std::string name = argv[1];
        std::string surname = argv[2];

        std::string country = argv[3];
        std::string city = argv[4];
        int postalCode = std::stoi(argv[5]);
        std::string street = argv[6];
        int houseNumber = std::stoi(argv[7]);

        address a = address(country, city, postalCode, street, houseNumber);
        order o = order(name, surname, d, prodList, a);

        o.addProduct(p1, (std::stoi(argv[8])));
        o.addProduct(p2, (std::stoi(argv[9])));
        o.addProduct(p3, (std::stoi(argv[10])));
        o.addProduct(p4, (std::stoi(argv[11])));

        std::cout << "object initialized correctly" << '\n';
        return 0;
    }
    catch (...)
    {
        std::cout << "error has occured during parsing the elements\n";
        return 3;
    }
}