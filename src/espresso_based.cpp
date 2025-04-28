#include "espresso_based.h"

EspressoBased::EspressoBased(const EspressoBased& esp)
{
    for (const auto& i : esp.ingredients) {
        ingredients.push_back(i->clone());
    }
}

EspressoBased::~EspressoBased()
{
    for(const auto& i : ingredients)
        delete i;
    ingredients.clear();
}