#include "mailbox.h"

bool Mailbox::is_message()
{
    std::unique_lock < std::mutex > lock (m);
    if (queue.empty())
    {
        lock.unlock();
        return false;
    }
    lock.unlock();
    return true;
    
}

Ingredient& Mailbox::get_message()
{
    std::unique_lock < std::mutex > lock (m);
    Ingredient& res = queue.front();
    queue.pop();
    is_full.notify_one();
    lock.unlock();
    std::ostringstream os;
    os << "[Mailbox] Got message: " << res.name;
    std::cout << os.str() << std::endl;
    return res;
}

void Mailbox::push_message(Ingredient& i)
{
    std::unique_lock < std::mutex > lock (m);
    is_full.wait(lock, [this] () { return queue.size() != mail_limit; });
    queue.push(i);
    lock.unlock();
    std::ostringstream os;
    os<< "[Mailbox] Added message: " << i.name;
    std::cout << os.str() << std::endl;
}

