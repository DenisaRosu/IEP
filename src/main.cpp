#include <iostream>

class House
{

public:
    int bedroom, bathroom, kitchen;

public:
    House()
    { //constructor neinit.
    }

    House(int a, int b, int c)
        //initializare inainte de a intra in functie.
        : bedroom(a), bathroom(b), kitchen(c)
    {
    }

    int roomNumber()
    {
        return bedroom + bathroom + kitchen;
    }

    //House(const House &h) = delete; // copy constructor
    House &operator-(const House &t) = delete; // sters house1-house2;

    House operator+(House t)
    {   //pt item 5: 
        //t=copy of house 2 ( incearca sa apeleze copy const. la ce am dat delete mai sus)

        House newHouse;
        newHouse.bathroom = bathroom + t.bathroom; // nr of newHouse = nr of house1+house2 of bathrooms
        newHouse.bedroom = bedroom + t.bedroom;
        newHouse.kitchen = kitchen + t.kitchen;
        return newHouse;
    } //house1+house2 -> house1.operator+(house2)  (se face copy constructor)( won t working)
};

int main()
{
    House house1;
    //House house2 = House(3, 2, 1);
    House house2(3, 2, 1);
    std::cout << "Numarul de camere din casa 1 = " << house1.roomNumber() << "\n";
    std::cout << "Numarul de camere din casa 2 = " << house2.roomNumber() << "\n";

    House house3(4, 2, 1);
    std::cout << "Numarul de camere din casa 3 = " << house3.roomNumber() << "\n";
    House house4 = house2 + house3;
    std::cout << "Numarul de camere din casa 4 = " << house4.roomNumber() << "\n";

   //pt item 6 
  // House house5= house4-house3;
}