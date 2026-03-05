#pragma once
#include <iostream>
#include <string>
using namespace std;

// Forward declaration so plant::decrement can call store()
void store(char type, int (&storage)[6]);

class plant
{
    int RemainingTime=30;
protected: char type;
public:
    int GetTime();
    bool decrement(int& PassedTime,int (&storage)[6]);
    char GetType()
    {
        return type;
    }
    plant (char type='0')
    {
        this-> type = type;
    }
    ~plant (){
        cout<<"Plant of type "<<type<<" was collected\n";
        type='0';
    }
    virtual int eat (){}
};

class fruit : public plant
{
protected:
    virtual int eat ()
    {
        cout<<"You Like Fruits In General\n";
        if  (type =='S')
            return 2;
        return 2;
    }
public:
    fruit(char type='0'):plant(type){};
};

class tree final : public fruit
{
    int eat ()
    {
        cout<<"You Like Tree Fruits\n";
        if (type=='B')
            return 2;
        return 2;
    }
public:
    tree(char type='0'):fruit(type){cout<< "tree of type "<<type<<" was planted\n";};
};

class bush : public fruit
{
public:
    bush(char type='0'):fruit(type){cout<< "bush of type "<<type<<" was planted\n";};
};

class flower : public plant
{
public:
    flower(char type='0'):plant(type){cout<< "flower of type "<<type<<" was planted\n";};
};
