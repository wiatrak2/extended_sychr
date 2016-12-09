#include "waiter.h"

void WaiterOrder::run()
{
    srand((unsigned int)time(NULL));

    while (true) {
        int rnd = rand() % recipe_vec.size();
        buff.produce(recipe_vec[rnd]);
        std::ostringstream os;
        os << "[WaiterOrder] Added order: " << recipe_vec[rnd].name;
        std::cout << os.str()<< std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void WaiterDeliver::run()
{
    while (true) {
        Meal meal = completed_meals.consume();
        budget.increase(meal.recipe.price);
        std::ostringstream os;
        os << "[WaiterDeliver] Meal deliverd: " << meal.recipe.name;
        std::cout << os.str() << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}
