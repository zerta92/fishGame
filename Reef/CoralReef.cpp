#include <iostream>

#include "CoralReef.h"

using namespace std;
static int reefs = 1;
bool check_reef = false; // Condition so that update() returns true only once.
CoralReef::CoralReef() : GameObject(82, reefs)
{
    this->state = 102;
    this->amount = 100;
    reefs++;
}

CoralReef::CoralReef(int in_id, CartPoint in_loc) : GameObject(82, in_id, in_loc)
{

    this->state = 102;
    this->amount = 100;
}

bool CoralReef::is_empty()
{
    if (amount == 0)
    {
        return true;
    }
    return false;
}

double CoralReef::provide_food(double amount_to_provide)
{

    if (amount >= amount_to_provide)
    {
        amount = amount - amount_to_provide;
        return amount_to_provide;
    }
    if (amount < amount_to_provide)
    {
        double temp_amount = amount;
        amount = 0;
        return temp_amount;
    }
    // return something?
}

bool CoralReef::update()
{

    while (!check_reef)
    {
        if (amount == 0)
        {
            state = 101;
            GameObject::display_code = 'r';
            cout << "CoralReef " << get_id() << " has been depleted" << endl;
            check_reef = true; // Condition so that update() returns true only once.

            return true;
        }

        if (amount > 0)
        {
            GameObject::display_code = 'R';
            return false;
        }
    }

    return false;
}

void CoralReef::show_status()
{

    cout << "Coral Reef Status: ";
    GameObject::show_status();
    cout << " containing food " << amount << endl;
}
