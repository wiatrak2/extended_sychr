#ifndef cook_h
#define cook_h

#include <thread>
#include <vector>
#include <sstream>
#include "mailbox.h"
#include "ingredient.h"
#include "buffer.h"
#include "meal.h"
#include "recipe.h"

class Cook {
public:
    std::vector<std::pair<Ingredient&, Buffer<Ingredient>&> > ingredients;
    Buffer<Recipe>& orders;
    Buffer<Meal>& completed_meals;
    Mailbox & mail;
    
    Meal meal;

    Cook (std::initializer_list<std::pair<Ingredient&, Buffer<Ingredient>&>> init,
          Buffer<Recipe>& orders,
          Buffer<Meal>& completed_meals,
          Mailbox & mail)
    : orders {orders},
      completed_meals {completed_meals},
      mail {mail}
    {
        for (auto i = init.begin(); i != init.end(); ++i)
            ingredients.push_back(*i);
    }

    void run();
};

#endif /* cook_h */
