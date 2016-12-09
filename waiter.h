#ifndef waiter_h
#define waiter_h

#include <chrono>
#include <thread>
#include <sstream>
#include "budget.h"
#include "buffer.h"
#include "meal.h"
#include "recipe.h"

class WaiterOrder {
public:
    Buffer<Recipe>& buff;
    std::vector<Recipe> recipe_vec;
    WaiterOrder(std::initializer_list<Recipe> init, Buffer<Recipe>& buff)
        : buff{ buff }
    {
        for (auto i = init.begin(); i != init.end(); ++i)
            recipe_vec.push_back(*i);
    }
    void run();
};

class WaiterDeliver {
public:
    Buffer<Meal>& completed_meals;
    Budget& budget;

    WaiterDeliver(Buffer<Meal>& completed_meals, Budget& budget)
        : completed_meals{ completed_meals }
        , budget{ budget }
    {
    }

    void run();
};

#endif /* waiter_h */
