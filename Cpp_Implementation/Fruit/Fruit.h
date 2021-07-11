#include <string.h>
#include <iostream>
#include <bits/stdc++.h>

class Fruit {
    protected :
        int weight;
        std::string type;
    public :
        Fruit *left ,*right;

    public :
        Fruit();
        Fruit(int);
        int getWeight();
        void setWeight(int);
        Fruit* getRight();
        void setRight(Fruit*);
        Fruit* getLeft();
        void setLeft(Fruit*);
        virtual std:: string getType();
};

class Tree{
    public:
        Fruit* root;
    public:
        Tree(){
            root = NULL;
        }
        void iterate();
        void iterateHelper(Fruit*);
        void filterByType(std::string);
        void filterByTypeHelper(Fruit*,std::string);
        void filterByWeight(int);
        void filterByWeightHelper(Fruit*,int);
        void magnifyByType(std::string,int);
        void magnifyByTypeHelper(std::string,int,Fruit*,std::vector<Fruit*>&);
        Fruit* findHeaviest();
        Fruit* findHeaviestHelper(Fruit*);
        Fruit* findLightest();
        Fruit* findLightestHelper(Fruit*);
        void insert(Fruit*);
        void insertHelper(Fruit*,Fruit*);
};
class OvalShaped :virtual public Fruit{
    public :
        virtual std:: string getType();
        OvalShaped();
        OvalShaped(int);
};
class Apple : public OvalShaped{
    public :
        virtual std:: string getType();
        Apple(int);
};
class Avocado : public OvalShaped{
    public :
        virtual std:: string getType();
        Avocado(int);
};
class Tiny :virtual public Fruit{
    public :
        virtual std:: string getType();
        Tiny();
        Tiny(int);
};
class Berry: public Tiny{
    public :
        virtual std:: string getType();
        Berry();
        Berry(int);
};
class Blackberry: public Berry{
    public :
        virtual std:: string getType();
        Blackberry(int);
};
class Elderberry: public Berry{
    public :
        virtual std:: string getType();
        Elderberry(int);
};
class Citrus : virtual public Fruit{
    public:
        virtual std:: string getType();
        Citrus();
        Citrus(int);
};
class Lemon : public Citrus, public Tiny{
    public:
        virtual std:: string getType();
        Lemon(int);
};
class Orange : public Citrus{
    public:
        virtual std:: string getType();
        Orange(int);
};
class Tangerine : public Citrus{
    public:
        virtual std:: string getType();
        Tangerine(int);
};