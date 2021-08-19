#include <iostream>
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

class Dell:public Laptop {
public:
    void husbandoSpecs() {
        cout << "\nAikuro Mikisugi <3\n";
    }
    virtual void husbandoPrice() {
        cout << "\n$69.00 <3\n";
    }
};

class Hp:public Laptop {
public:
    void husbandoSpecs() {
        cout << "\nLevi Ackerman\n";
    }
    virtual void husbandoPrice() {
        cout << "\n$3003.00 <3\n";
    }
};

class Shapes {
protected:
    double base;
    double height;

public:
    virtual void getData() = 0;
    virtual void displayArea() = 0;
};

class Rectangle : public Shapes {
public:
    void displayArea() {
        cout << "\nThe area is: " << base * height << endl;
    }

    void getData() {
        cout << "\nPlease enter the Length in centimeters: ";
        cin >> base;
        cout << "\nPlease enter the Width in centimeters: ";
        cin >> height;
    }
};

class Triangle : public Shapes {
public:
    void displayArea() {
        cout << "\nThe area is: " << base * height / 2 << endl;
    }
    void getData() {
        cout << "\nPlease enter the base in centimeters: ";
        cin >> base;
        cout << "\nPlease enter the height in centimeters: ";
        cin >> height;
    }
};

int main()
{
    Laptop* l1 = new Dell();
    Laptop* l2 = new Hp();
    l1->husbandoSpecs();
    l1->husbandoPrice();
    l2->husbandoSpecs();
    l2->husbandoPrice();

    Shapes* s1 = new Rectangle();
    Shapes* s2 = new Triangle();

    cout << "\nArea of Rectangle\n";
    s1->getData();
    s1->displayArea();
    cout << "\nArea of Triangle\n";
    s2->getData();
    s2->displayArea();

    return 0;
}
