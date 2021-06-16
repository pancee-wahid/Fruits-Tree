#include "Tree.h"

Tree::Tree() {root = nullptr;}

void Tree::insert(int weight) {
    Fruit* newFruit;
/*
    if (type == "OvalShaped")
        OvalShaped* newFruit = reinterpret_cast<OvalShaped*>(newFruit);
    else if (type == "TinyFruit")
        TinyFruit* newFruit = reinterpret_cast<TinyFruit*>(newFruit);
    else if (type == "Berry")
        Berry* newFruit = reinterpret_cast<Berry*>(newFruit);
    else if (type == "Apple")
        Apple* newFruit = reinterpret_cast<Apple*>(newFruit);
    else if (type == "Avocado")
        Avocado newFruit;
    else if (type == "Blackberry")
        Blackberry newFruit;
    else if (type == "Elderberry")
        ElderBerry newFruit;
    else
        Fruit newFruit;
*/
    newFruit->weight = weight;
    newFruit->left = nullptr;
    newFruit->right = nullptr;
    if (root == nullptr)
        root = newFruit;
    else
        insertHelper(root, newFruit);
}

void Tree::insertHelper(Fruit* fruit, Fruit* newFruit) {
    if (newFruit->weight < fruit->weight) {
        if(fruit->left == nullptr){
            fruit->left = newFruit;
            fruit->left->parent = fruit;
        } else {
            insertHelper(fruit->left, newFruit);
        }
    } else if (newFruit->weight > fruit->weight) {
        if(fruit->right == nullptr){
            fruit->right = newFruit;
            fruit->right->parent = fruit;
        } else {
            insertHelper(fruit->right, newFruit);
        }
    } else {
        newFruit->parent = fruit->parent;
        newFruit->left = fruit->left;
        newFruit->right = fruit->right;
        if (fruit->left != nullptr)
            fruit->left->parent = newFruit;
        if (fruit->right != nullptr)
            fruit->right->parent = newFruit;
        if (fruit->parent != nullptr){
            if (fruit->parent->left == fruit)
                fruit->parent->left = newFruit;
            else
                fruit->parent->right = newFruit;
        } else {
            root = newFruit;
        }
    }
}

void Tree::inorderTraversal(Fruit* fruit) {
    if (fruit == nullptr)
        return;
    inorderTraversal(fruit->left);
    cout << fruit->getType() << " " << fruit->weight << "gm" << endl;
    inorderTraversal(fruit->right);
}

void Tree::iterate() {
    inorderTraversal(root);
}

void Tree::filterByType(string type) {
    filterByTypeHelper(root, type);
}

void Tree::filterByTypeHelper(Fruit* fruit, string type) {
    if (fruit == nullptr)
        return;
    filterByTypeHelper(fruit->left, type);
}

void Tree::filterByWeight(int weight) {
    filterByWeightHelper(root, weight);
}

void Tree::filterByWeightHelper(Fruit* fruit, int weight) {

}

void Tree::magnifyByType(string type, int weight) {
    list<int> weightList;
    magnifyByTypeHelper(root, type, weight, weightList);
    list<int> :: iterator it;
    for (it = weightList.begin(); it != weightList.end(); ++it)
        insert(*it);
}

void Tree::magnifyByTypeHelper(Fruit* fruit, string type, int weight, list<int> weightList) {
    if (fruit == nullptr)
        return;
    magnifyByTypeHelper(fruit->left, type, weight, weightList);
//if (fruit->getType())
//is_base_of<Fruit, fruit->getType()>
//Base* bp = dynamic_cast<Base*>(&d1)
}

void Tree::remove(int weight) {
    root = removeHelper(root, weight);
}

Fruit *Tree::removeHelper(Fruit* fruit, int weight) {
    if (fruit == nullptr) {
        return nullptr;
    } else if (weight < fruit->weight) {
        fruit->left = removeHelper(fruit->left, weight);
        return fruit;
    } else if (weight > fruit->weight) {
        fruit->right = removeHelper(fruit->right, weight);
        return fruit;
    } else {
        if (fruit->left == nullptr && fruit->right == nullptr) {
            fruit = nullptr;
            return fruit;
        }
        if (fruit->left == nullptr) {
            fruit = fruit->right;
            return fruit;
        } else if (fruit->right == nullptr) {
            fruit = fruit->left;
            return fruit;
        }

        Fruit* temp = findLightestHelper(fruit->right);
        if (fruit->parent != nullptr) {
            if (fruit->parent->left == fruit)
                fruit->parent->left = temp;
            else
                fruit->parent->right = temp;
        }
        if (temp->parent->left == temp)
            temp->parent->left = nullptr;
        else
            temp->parent->right = nullptr;
        temp->parent = fruit->parent;
        temp->right = fruit->right;
        temp->left = fruit->left;
        if (fruit->left != nullptr)
            fruit->left->parent = temp;
        if (fruit->right != nullptr)
            fruit->right->parent = temp;
        fruit = temp;
        return fruit;

    }
    return nullptr;
}

Fruit* Tree::findLightest() {
    return findLightestHelper(root);
}

Fruit* Tree::findLightestHelper(Fruit* fruit) {
    if (fruit->left == nullptr)
        return fruit;
    return findLightestHelper(fruit->left);
}

Fruit* Tree::findHeaviest() {
    return findHeaviestHelper(root);
}

Fruit* Tree::findHeaviestHelper(Fruit* fruit) {
    if (fruit->right == nullptr)
        return fruit;
    return findHeaviestHelper(fruit->right);
}

