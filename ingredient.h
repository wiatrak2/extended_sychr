#ifndef ingredient_h
#define ingredient_h

#include <iostream>
#include <string>
#include <utility>

class Ingredient {
public:
    std::string name;
    unsigned int price;

    Ingredient()
        : name{ "" }
        , price{ 0 }
    {
    }

    Ingredient(const std::string& name, const unsigned int price)
        : name{ name }
        , price{ price }
    {
    }

    Ingredient(const Ingredient& i)
        : name{ i.name }
        , price{ i.price }
    {
    }

    Ingredient& operator=(const Ingredient& i)
    {
        if (&i == this)
            return *this;
        name = i.name;
        price = i.price;
        return *this;
    }

    bool operator ==(const Ingredient& i) const
    {
        return name == i.name;
    }
};

#endif /* ingredient_h */
