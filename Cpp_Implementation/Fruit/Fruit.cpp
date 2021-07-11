#include <iostream>
#include "Fruit.h"
#include <bits/stdc++.h>
using namespace std;

Fruit ::Fruit(){
    this->weight = 0;
    this->left = NULL;
    this->left = NULL;
}
Fruit ::Fruit(int weight){
    this->weight = weight;
    this->left = NULL;
    this->left = NULL;
}
OvalShaped ::OvalShaped(int weight){
    this->weight=weight;
    this->left=NULL;
    this->right=NULL;
}
OvalShaped ::OvalShaped(){}
Apple ::Apple(int weight){
    this->weight=weight;
    this->left=NULL;
    this->right=NULL;
}
Avocado ::Avocado(int weight){
    this->weight=weight;
    this->left=NULL;
    this->right=NULL;
}
Tiny ::Tiny(int weight){
    this->weight=weight;
    this->left=NULL;
    this->right=NULL;
}
Tiny ::Tiny(){}
Berry ::Berry(int weight){
    this->weight=weight;
    this->left=NULL;
    this->right=NULL;
}
Berry ::Berry(){}
Blackberry ::Blackberry(int weight){
    this->weight=weight;
    this->left=NULL;
    this->right=NULL;
}
Elderberry ::Elderberry(int weight){
    this->weight=weight;
    this->left=NULL;
    this->right=NULL;
}
Citrus ::Citrus(int weight){
    this->weight=weight;
    this->left=NULL;
    this->right=NULL;
}
Citrus ::Citrus(){}
Lemon ::Lemon(int weight){
    this->weight=weight;
    this->left=NULL;
    this->right=NULL;
}
Orange ::Orange(int weight){
    this->weight=weight;
    this->left=NULL;
    this->right=NULL;
}
Tangerine ::Tangerine(int weight){
    this->weight=weight;
    this->left=NULL;
    this->right=NULL;
}

int Fruit:: getWeight(){
    return this->weight;
}

void Fruit:: setWeight(int weight){
    this->weight = weight;
}

Fruit* Fruit:: getRight(){
    return this->right;
}

void Fruit:: setRight(Fruit* fruit){
    this->right = fruit;
}

Fruit* Fruit:: getLeft(){
    return this->left;
}

void Fruit:: setLeft(Fruit* fruit){
    this->left = fruit;
}

string Fruit:: getType(){
    return "Fruit";
}
string OvalShaped:: getType(){
    return "OvalShaped Fruit";
}
string Apple:: getType(){
    return "Apple OvalShaped Fruit";
}
string Avocado:: getType(){
    return "Avocado OvalShaped Fruit";
}
string Tiny:: getType(){
    return "Tiny Fruit";
}
string Berry:: getType(){
    return "Berry Tiny Fruit";
}
string Blackberry:: getType(){
    return "Blackberry Berry Tiny Fruit";
}
string Elderberry:: getType(){
    return "Elderberry Berry Tiny Fruit";
}
string Citrus:: getType(){
    return "Citrus Fruit";
}
string Lemon:: getType(){
    return "Lemon Citrus Tiny Fruit";
}
string Orange:: getType(){
    return "Orange Citrus Fruit";
}
string Tangerine:: getType(){
    return "Tangerine Citrus Fruit";
}

void Tree:: insert(Fruit* fruit){
    if(root == NULL)
        root = fruit;
    else
        insertHelper(root, fruit);
}
void Tree:: insertHelper(Fruit* root, Fruit* fruit){
    if (fruit->getWeight() < root->getWeight()){
        if (root->getLeft() != NULL)
            insertHelper(root->getLeft(), fruit);
        else
            root->setLeft(fruit);
    }else{
        if (root->getRight() != NULL)
            insertHelper(root->getRight(), fruit);
        else
            root->setRight(fruit);
    }
}

void Tree:: iterate(){
    iterateHelper(root);
}
void Tree:: iterateHelper(Fruit *fruit){
    if (fruit == NULL)
        return;
    iterateHelper(fruit->getLeft());
    cout << fruit->getType() << " " << fruit->getWeight() << "gm" << endl;
    iterateHelper(fruit->getRight());
}

Fruit* Tree:: findHeaviest(){
    if(root == NULL)
        return NULL;
    return findHeaviestHelper(root);
}
Fruit* Tree:: findHeaviestHelper(Fruit* node){
    while (node->getRight() != NULL){
            node = node->getRight();
        }
    return node;
}

Fruit* Tree:: findLightest(){
    if(root == NULL)
        return NULL;
    return findLightestHelper(root);
}
Fruit* Tree:: findLightestHelper(Fruit *node){
    while (node->getLeft() != NULL){
        node = node->getLeft();
    }
    return node;
}
void Tree:: filterByWeight(int weight){
    filterByWeightHelper(root, weight);
}
void Tree:: filterByWeightHelper(Fruit* root, int weight){
    if (root == NULL)
        return;
    filterByWeightHelper(root->getLeft(), weight);
    if (root->getWeight() > weight)
        cout << root->getType() << " " << root->getWeight() << "gm" << endl;
    filterByWeightHelper(root->getRight(), weight);
}

void Tree:: magnifyByType(string type, int weight){
    vector<Fruit*> list;
    magnifyByTypeHelper(type,weight,root,list);
    root = NULL;
    for(Fruit* f : list){
        f->setLeft(NULL);
        f->setRight(NULL);
        this->insert(f);
    }
}
void Tree:: magnifyByTypeHelper(string type,int weight,Fruit* root,vector<Fruit*>& list){
    if (root == NULL)
        return;
    queue<Fruit *> q;
    q.push(root);
    while (q.empty() == false){
        Fruit *node = q.front();
        if(node->getType().find(type) != string::npos)
            node->setWeight(node->getWeight()+weight);
        list.push_back(node);
        if (node->left != NULL)
            q.push(node->left);
        if (node->right != NULL)
            q.push(node->right);
        q.pop();
    }
}

void Tree:: filterByType(string type){
    filterByTypeHelper(root, type);
}
void Tree:: filterByTypeHelper(Fruit* root, string type){
    if (root == NULL)
        return;
    filterByTypeHelper(root->getLeft(), type);
    if (root->getType().find(type) != string::npos)
        cout << root->getType() << " " << root->getWeight() << "gm" << endl;
    filterByTypeHelper(root->getRight(), type);
}

int main(){
    Tree *tree = new Tree();
    tree->insert(new Orange(13));
    tree->insert(new Avocado(5));
    tree->insert(new Apple(8));
    tree->insert(new Lemon(4));
    tree->insert(new Elderberry(9));
    cout<<"Test iterate\n";
    cout<<"\n----------------------------\n";
    tree->iterate();
    cout<<"\n\nTest FilterByType\n";
    cout<<"\n----------------------------\n";
    tree->filterByType("Citrus");
    cout<<"\n\nTest FilterByWeight\n";
    cout<<"\n----------------------------\n";
    tree->filterByWeight(8);
    cout<<"\n\nTest MagnifyByType\n";
    cout<<"\n----------------------------\n";
    tree->magnifyByType("Fruit",1);
    tree->iterate();
    cout<<"\n----------------------------\n";
    tree->magnifyByType("Apple",6);
    tree->iterate();
    cout<<"\n\nTest FindHeaviest\n";
    cout<<"\n----------------------------\n";
    Fruit *f = tree->findHeaviest();
    cout << f->getType() << " " << f->getWeight() << "gm" << endl;
    cout<<"\n\nTest FindLightest\n" ;
    cout<<"\n----------------------------\n";
    f = tree->findLightest();
    cout << f->getType() << " " << f->getWeight() << "gm" << endl;
    return 0;
}