#include "mocha.h"

#include <iostream>

#include "ingredient.h"
#include "sub_ingredients.h"

Mocha::Mocha():EspressoBased("Mocha")
{
    this->ingredients.push_back(new Espresso(2));
    this->ingredients.push_back(new Milk(2));
    this->ingredients.push_back(new MilkFoam(1));
    this->ingredients.push_back(new Chocolate(1));
}

Mocha::Mocha(const Mocha& ma):EspressoBased(ma)
{
    this->name = ma.name;

    for(const auto &pt : ma.side_items)
    {
        this->side_items.push_back(pt->clone());
    }
}

Mocha::~Mocha()
{
    for(const auto &pt : side_items)
    {
        delete pt;
    }
    side_items.clear();
}

Mocha& Mocha::operator=(const Mocha& ma)
{
    if(&ma != this)
    {
        this->name = ma.name;
        for(const auto &pt : ingredients)
        {
            delete pt;
        }
        for(const auto &pt : side_items)
        {
            delete pt;
        }
        ingredients.clear(), side_items.clear();
        for(const auto &pt : ma.ingredients)
        {
            this->ingredients.push_back(pt->clone());
        }

        for(const auto &pt : ma.side_items)
        {
            this->side_items.push_back(pt->clone());
        }
    }
    return *this;
}

double Mocha::price()
{
    double p = 0;
    for (auto& i : ingredients) {
        p += i->price();
    }
    for (auto& i : side_items) {
        p += i->price();
    }
    return p;
}

void Mocha::brew()
{
    std::cout << "making mocha..." << std::endl;
    for (const auto& i : ingredients) {
        std::cout << "adding " << i->get_name() << "..." << std::endl;
    }
    for (const auto& i : side_items) {
        std::cout << "adding " << i->get_name() << "..." << std::endl;
    }
    std::cout << "mocha finished" << std::endl;
}

void Mocha::add_side_item(Ingredient* side)
{
    side_items.push_back(side);
}