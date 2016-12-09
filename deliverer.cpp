#include "deliverer.h"

void Deliverer::run()
{
    srand((unsigned int) time(NULL));
    
    while (true)
    {
        if(mail.is_message())
        {
            Ingredient & tmp = mail.get_message();
            for (auto i : buffer_set)
            {
                if (i.first == tmp)
                {
                    i.second.produce(i.first);
                    budget.decrease(i.first.price);
                }
            }
        }
        else
        {
            int rnd = rand() % buffer_set.size();
            buffer_set[rnd].second.produce ( buffer_set[rnd].first ) ;
            budget.decrease(buffer_set[rnd].first.price);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(6));
    }
}
