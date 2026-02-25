#include <iostream>
using namespace std;
class Car 
{
  public:
   string brand;
   string model;
   int year;
};
int main () 
{ 
 Car mycar;
 mycar.brand = "Ford";
 mycar.model = "Mustang";
 mycar.year = 2010;
  cout<< mycar.brand<< " "<<mycar.model<< " "<< mycar.year;
  return 0;
}
