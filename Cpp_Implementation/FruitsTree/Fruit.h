#ifndef C___IMPLEMENTATION_FRUIT_H
#define C___IMPLEMENTATION_FRUIT_H

#include <iostream>
#include <string>

using namespace std;

class Fruit {
public:
    Fruit();
    int weight;
    Fruit* left;
    Fruit* right;
    Fruit* parent;
    virtual string getType();
};

class OvalShaped : virtual Fruit{
public:
    string getType();
};

class TinyFruit : virtual Fruit{
public:
    string getType();
};

class Berry : virtual TinyFruit{
public:
    string getType();
};

class Citrus : virtual Fruit{
public:
    string getType();
};

class Apple : virtual OvalShaped{
public:
    string getType();
};

class Avocado : virtual OvalShaped{
public:
    string getType();
};

class Blackberry : virtual Berry{
public:
    string getType();
};

class ElderBerry : virtual Berry{
public:
    string getType();
};

class Lemon : virtual Citrus{
public:
    string getType();
};

class Orange : virtual Citrus{
public:
    string getType();
};

class Tangerine : virtual Citrus{
public:
    string getType();
};

#endif //C___IMPLEMENTATION_FRUIT_H
