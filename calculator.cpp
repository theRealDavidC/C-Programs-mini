#include <iostream>
using namespace std;

int main() {
    int num1, num2, sum, difference, product;
    double division;
    int choice = 0;

    cout << "Please enter your first number: \n";
    cin >> num1;
    cout << "Please enter your second number: \n";
    cin >> num2;

    while (choice != -1) {
        cout << "Enter choice (1=Sum, 2=Difference, 3=Product, 4=Division, -1=Quit): \n";
        cin >> choice;

        switch (choice) {
            case 1:
                sum = num1 + num2;
                cout << "The sum is " << sum << "\n";
                break;
            case 2:
                difference = num1 - num2;
                cout << "The difference is " << difference << "\n";
                break;
            case 3:
                product = num1 * num2;
                cout << "The product is " << product << "\n";
                break;
            case 4:
                if (num2 == 0) {
                    cout << "Error: Division by 0 is not allowed\n";
                } else {
                    division = (double)num1 / num2;
                    cout << "The division is " << division << "\n";
                }
                break;
            default:
                cout << "Unknown choice, please choose the correct option\n";
        }
    }
    return 0;
}
