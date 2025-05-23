#ifndef SUB_INGREDIENTS_H
#define SUB_INGREDIENTS_H

#define DEFCLASS(NAME, PRICE)                                          \
class NAME: public Ingredient                                          \
{                                                                      \
public:                                                                \
    NAME(size_t units) : Ingredient{PRICE, units}                      \      
    {                                                                  \
        this->name = #NAME;                                            \
    }                                                                  \
    virtual double price() override {return units *  PRICE;}           \
    virtual Ingredient* clone() { return new NAME(*this); }            \
};

DEFCLASS(Cinnamon, 5);
DEFCLASS(Chocolate, 5);
DEFCLASS(Sugar, 1);
DEFCLASS(Cookie, 10);
DEFCLASS(Espresso, 15);
DEFCLASS(Milk, 10);
DEFCLASS(MilkFoam, 5);
DEFCLASS(Water, 1);
#endif // SUB_INGREDIENTS_H