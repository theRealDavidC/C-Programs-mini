#include <iostream>
using namespace std;
class Vehicle 
{
  public:
    string name;
	void engineStarts() 
	 {
	cout<<"Engine gives out sound\n";
	}
};
	
class Car : public Vehicle
{
 public:
  void drive() 
   {
  cout<<"A car starts to move on four wheels";
  }
};

int main() {
 Car c;
  c.name = "Ferrari";
  c.engineStarts();
  c.drive();
 }
