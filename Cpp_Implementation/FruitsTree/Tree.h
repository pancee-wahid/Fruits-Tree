#ifndef C___IMPLEMENTATION_TREE_H
#define C___IMPLEMENTATION_TREE_H

#include <iostream>
#include <string>
#include <list>
#include <iterator>
#include "Fruit.h"

using namespace std;

class Tree {
private:
    Fruit* root;
public:
    Tree();
    void insert(int weight);
    void insertHelper(Fruit* fruit, Fruit* newFruit);
    void inorderTraversal(Fruit* fruit);
    void iterate();
    void filterByType(string type);
    void filterByTypeHelper(Fruit* fruit, string type);
    void filterByWeight(int weight);
    void filterByWeightHelper(Fruit* fruit, int weight);
    void magnifyByType(string type, int weight);
    void magnifyByTypeHelper(Fruit* fruit, string type, int weight, list <int> weightList);
    void remove(int weight);
    Fruit* removeHelper(Fruit* fruit, int weight);
    Fruit* findLightest();
    Fruit* findLightestHelper(Fruit* fruit);
    Fruit* findHeaviest();
    Fruit* findHeaviestHelper(Fruit* fruit);
};


#endif //C___IMPLEMENTATION_TREE_H
