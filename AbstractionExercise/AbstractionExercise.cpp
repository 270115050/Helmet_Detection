#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//Abstraction (how I understand it) is it hides the complex logic and what you only need to know is that this abstraction can do this.
//Example dev1 and dev2 are given a list of functionality for this Laptop dev1 will be working on Dell and dev2 is working on HP they dont need to know
//the functionality of the other product they only need to worry how they are going to implement the provided funciton.
//Any derived class that inherits the Laptop will need to provide there own implementation of all virtual funciton if not it will give syntax error.
class Laptop {
public:  
    //This mean that anyone who inherits Laptop will need to provide there own implementation of this function
    virtual void husbandoSpecs() = 0;
    virtual void husbandoPrice() = 0;

};

class Dell:public Laptop{
public:
    void husbandoSpecs() {
        cout << "Aikuro Mikisugi <3";
    }
    void husbandoPrice() {
        cout << "$69.00 <3";
    }
};

class Hp:public Laptop {
public:
    void husbandoSpecs() {
        cout << "Levi Ackerman";
    }
    void husbandoPrice() {
        cout << "$3003.00 <3";
    }
};

//template <class Derived>
//class Base {
//public: 
//    void interface() {
//        cout << "Base::interface called\n";
//        static_cast<Derived*>(this)->implementation();
//    }
//};

//class Derived :public Base<Derived> {
//public:
//    void implementation() {
//        cout << "hello my worthless life\n";
//    }
//};

//class Shapes {
//protected:
//    double base;
//    double height;
//
//public:
//    virtual void getData() = 0;
//    virtual void displayArea() = 0;
//};
//
//class Rectangle : public Shapes {
//public:
//    void displayArea() {
//        cout << "\nThe area is: " << base * height << endl;
//    }
//
//    void getData() {
//        cout << "\nPlease enter the Length in centimeters: ";
//        cin >> base;
//        cout << "\nPlease enter the Width in centimeters: ";
//        cin >> height;
//    }
//};
//
//class Triangle : public Shapes {
//public:
//    void displayArea() {
//        cout << "\nThe area is: " << base * height / 2 << endl;
//    }
//    void getData() {
//        cout << "\nPlease enter the base in centimeters: ";
//        cin >> base;
//        cout << "\nPlease enter the height in centimeters: ";
//        cin >> height;
//    }
//};

int main()
{
    vector<Laptop*>l;
    int choice,num;
    bool isTrue;

    do {
        isTrue = true, num = 0, choice = 0;
        cout << "\nPick Brand"
            << "\nPress 1 for Dell"
            << "\nPress 2 for HP"
            << "\nPress 3 to exit..."
            << "\nChoose options: ";
        cin >> choice;

        switch (choice) {
        case 1: 
            cout << "How many Laptop would you like to create?: ";
            cin >> num;
            for (int i = 0; i < num; i++)
                l.push_back(new Dell);
            break;
        case 2:
            cout << "How many Laptop would you like to create?: ";
            cin >> num;
            for (int i = 0; i < num; i++)
                l.push_back(new Hp);
            break;
        case 3:
            isTrue = false;
            break;
        default:
            cout << "\nInvalid Input, Please try again...\n";
            break;
        }
    } while (isTrue);

    cout << "\n\n\n";
    for (auto item : l) {
        cout << "My husbando is "; 
        item->husbandoSpecs(); 
        cout << " the price I payed ";
        item->husbandoPrice();
        cout << endl << endl;
    }
    return 0;
}
