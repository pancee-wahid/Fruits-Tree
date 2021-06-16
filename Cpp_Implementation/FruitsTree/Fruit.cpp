#include "Fruit.h"

using namespace std;
//Fruit class
Fruit::Fruit() {
    weight = 0;
    left = NULL;
    right = NULL;
    parent = NULL;
}

string Fruit::getType() {return "Fruit";}

//OvalShaped class
string OvalShaped::getType() {return "OvalShaped";}

//TinyFruit class
string TinyFruit::getType() {return "TinyFruit";}

//Berry class
string Berry::getType() {return "Berry";}

//Citrus
string Citrus::getType() {return "Citrus";}

//Avocado
string Avocado::getType() {return "Avocado";}

//Apple
string Apple::getType() {return "Apple";}

//Blackberry
string Blackberry::getType() {return "Blackberry";}

//Elderberry
string ElderBerry::getType() {return "Elderberry";}

//Lemon
string Lemon::getType() {return "Lemon";}

//Orange
string Orange::getType() {return "Orange";}

//Tangerine
string Tangerine::getType() {return "Tangerine";}