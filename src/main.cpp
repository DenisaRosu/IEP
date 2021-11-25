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
  

 
     House& operator=(const House &t)
     {  
//item 11 
        if (this == &t)  //self assignment 
            return *this;  //daca aveam egalitate de identitate nu e nevoie de actualizarea obiectului
     
          bathroom = t.bathroom; 
          bedroom = t.bedroom;
          kitchen = t.kitchen;
 //item10
          return *this;  //updatare a obiectului curent 
     }

};
//item12
class Villa: public House{
   
   public:
    int garage; 
    
 Villa():House()
 {

 }
Villa(int a, int b, int c, int d )
        //initializare inainte de a intra in functie.
        :House(a,b,c), garage(d)
    {
    }

Villa& operator=(const Villa &t)
     {  

        if (this == &t)
            return *this;  //daca aveam egalitate de identitate nu e nevoie de actualizarea obiectului
          
          House::operator=(t);  // this (Villa) ia toate campurile (update) prin mosenire( super din Java)
          //daca comentam linia de mai sus, valoarea finala  va fi garbage value
          garage = t.garage; 
          
          return *this; 
     }
   

};

int main()
{   

    /*Item 10: Have assignment operators return a reference to *this.
Item 11: Handle assignment to self in operator=.
Item 12: Copy all parts of an object.
    */

    //item4
    House house1;
    //House house2 = House(3, 2, 1);
    House house2(3, 2, 1);
    std::cout << "Numarul de camere din casa 1 = " << house1.roomNumber() << "\n";
    std::cout << "Numarul de camere din casa 2 = " << house2.roomNumber() << "\n";

    House house3(4, 2, 1);
    std::cout << "Numarul de camere din casa 3 = " << house3.roomNumber() << "\n";
    House house4 = house2 + house3;
    std::cout << "Numarul de camere din casa 4 = " << house4.roomNumber() << "\n";

    House  house5(2,2,2);
    house4 = house5;
  std::cout << "Camerele din house 5: " << house5.bathroom <<" "<<  house5.bedroom<<" " << house5.kitchen<< "\n";
   

    //item10: 
    house1=(house2=house3)=house5;
    std::cout << "Noul numar de camere din House1 ( house 5) = " << house1.roomNumber() << "\n";
    //ex2item10:
   (house3=house2)=house4=house1;
    std::cout << "Noul numar de camere din House 3 ( house 1) = " << house1.roomNumber() << "\n";

    Villa v1(3,2,3,1);
    Villa v2;
    v2=v1;
    std::cout << " nr de garaje din  din vila:, nr de bai din vila:  " << v2.garage <<" "<< v2.bathroom<<"\n";
   


   //pt item 6 
  // House house5= house4-house3;
}
