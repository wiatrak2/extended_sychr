#ifndef meal_h
#define meal_h

#include <vector>
#include <sstream>
#include "ingredient.h"
#include "recipe.h"

class Meal {
public:
    Recipe recipe;
    std::vector<std::pair<Ingredient, unsigned int> > missing_ingredients;

    Meal()
        : recipe{ Recipe() }
        , missing_ingredients{}
    {
    }

    Meal(Recipe recipe)
        : recipe{ recipe }
    {
        for (auto i : recipe.ingredients) {
            missing_ingredients.push_back(i);
        }
    }

    Meal& operator=(const Meal& m)
    {
        if (&m == this)
            return *this;
        recipe = m.recipe;
        for (auto i : m.missing_ingredients)
            missing_ingredients.push_back(i);
        return *this;
    }

    bool is_completed();
    Ingredient get_missing_ingredient();
    void update_misiing_ingredients();
};

std::ostream& operator << ( std::ostream& stream, const Meal& m );

#endif /* meal_h */
