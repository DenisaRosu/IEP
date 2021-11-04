#include <iostream>

class House
{

private:
    int bedroom, bathroom, kitchen;

public:
    House()
    { //constructor neinit.
    }

    House(int a, int b, int c) 
    //initializare inainte de a intra in functie. 
       :bedroom(a), bathroom(b),kitchen(c){}
   
    int roomNumber()
    {
        return bedroom+bathroom+kitchen;
    }

};

int main()
{ 
    House house1;
    House house2=House(3,2,1);

    std::cout<<"Numarul de camere din casa = "<<house1.roomNumber()<<"\n";
     std::cout<<"Numarul de camere din casa = "<<house2.roomNumber()<<"\n";
}