#include "budget.h"
#include "buffer.h"
#include "cook.h"
#include "deliverer.h"
#include "meal.h"
#include "recipe.h"
#include "waiter.h"
#include <iostream>
#include "mailbox.h"
int main()
{
    Ingredient pomidor("pomidor", 2);
    Ingredient ananas("ananas", 3);
    Ingredient pomarancza("pomarancza", 5);
    Ingredient salata("salata", 2);
    Ingredient ogorek("ogorek", 4);
    Ingredient ser("ser", 6);
    Ingredient mieso("mieso", 10);
    Ingredient makaron("makaron", 7);
    Mailbox mail;

    Recipe r1("salatka", 25, { { salata, 3 },
                                 { pomidor, 2 },
                                 { pomarancza, 2 },
                                 { ogorek, 2 } });

    Recipe r2("pizza", 50, { { mieso, 1 },
                               { ser, 2 },
                               { ananas, 1 } });

    Recipe r3("danie", 70, { { makaron, 1 },
                                { mieso, 1 } });

    Buffer<Ingredient> buff_pomidor(100, "buff_pomidor");
    Buffer<Ingredient> buff_ananas(100, "buff_ananas");
    Buffer<Ingredient> buff_pomarancza(100, "buff_pomarancza");
    Buffer<Ingredient> buff_salata(100, "buff_salata");
    Buffer<Ingredient> buff_ogorek(100, "buff_ogorek");
    Buffer<Ingredient> buff_ser(100, "buff_ser");
    Buffer<Ingredient> buff_mieso(100, "buff_mieso");
    Buffer<Ingredient> buff_makaron(100, "buff_makaron");

    Budget budget(1000);

    Buffer<Recipe> buff_recipe(100, "buff_recipe");
    Buffer<Meal> buff_meal(100, "buff_meal");
    Cook cook({ { std::ref(pomidor), std::ref(buff_pomidor) },
                  { std::ref(ananas), std::ref(buff_ananas) },
                  { std::ref(pomarancza), std::ref(buff_pomarancza) },
                  { std::ref(salata), std::ref(buff_salata) },
                  { std::ref(ogorek), std::ref(buff_ogorek) },
                  { std::ref(ser), std::ref(buff_ser) },
                  { std::ref(mieso), std::ref(buff_mieso) },
                  { std::ref(makaron), std::ref(buff_makaron) } },
        buff_recipe, buff_meal, mail);

    Deliverer deliverer(
        { { std::ref(pomidor), std::ref(buff_pomidor) },
            { std::ref(ananas), std::ref(buff_ananas) },
            { std::ref(pomarancza), std::ref(buff_pomarancza) },
            { std::ref(salata), std::ref(buff_salata) },
            { std::ref(ogorek), std::ref(buff_ogorek) },
            { std::ref(ser), std::ref(buff_ser) },
            { std::ref(mieso), std::ref(buff_mieso) },
            { std::ref(makaron), std::ref(buff_makaron) } },
        budget, mail);

    WaiterOrder waiter1({ r1, r2, r3 }, buff_recipe);
    WaiterDeliver waiter2(buff_meal, budget);

    std::thread t1(&Deliverer::run, deliverer);
    std::thread t2(&Cook::run, cook);
    std::thread t3(&WaiterOrder::run, waiter1);
    std::thread t4(&WaiterDeliver::run, waiter2);

    while (!budget.bankrupt()) {
        std::ostringstream os;
        os << "[Budget] "<< budget.budget << "$";
        std::cout << os.str() << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(30));
    }
    std::cout << std::endl << "BANKRUPT!" << std::endl;
    
    t1.detach();
    t2.detach();
    t3.detach();
    t4.detach();
    return 0;
}
