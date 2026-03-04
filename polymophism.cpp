#include <iostream>
#include <string>
using namespace std;

class Hesabu
{
public:  
    void add(int num1, int num2) {  
        cout << num1 + num2 << endl;
    }
    
    void add(double a, double b) {  
        cout << a + b << endl;
    }
    
    void add(string name, int age) {
        cout << "Your name is " << name << " Age is: " << age << endl;
    }
};

int main() {
    Hesabu h;
    h.add(10, 7);           
    h.add(23.8, 19.3);      
    h.add("David Mmari", 21);
    return 0;
}
