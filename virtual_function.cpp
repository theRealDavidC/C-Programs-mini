#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void makeSound() = 0;
    virtual ~Animal() {}  
};

class Dog : public Animal
{
public:
    void makeSound() override {
        cout<<"Woof! Woof!"<<endl;
    }
};

class Cat : public Animal
{
public:
    void makeSound() override {
        cout<<"Meow! Meow!"<<endl;
    }
};

class Cow : public Animal
{
public:
    void makeSound() override {  
        cout<<"Moo! Moo!"<<endl;
    }
};

int main () {
    cout<<"Listening to animal sound..."<<endl;
    Dog myDog;
    Cat myCat;
    Cow myCow;
    
    // Direct calls
    myDog.makeSound();
    myCat.makeSound();
    myCow.makeSound();
    
    cout<<"\nUsing pointers (Polymorphism):"<<endl;  
    
    // Using pointers (Polymorphism)
    Animal* animal1 = &myDog;
    Animal* animal2 = &myCat;
    Animal* animal3 = &myCow;
    
    animal1->makeSound();  
    animal2->makeSound();
    animal3->makeSound();
    
    return 0;
}
