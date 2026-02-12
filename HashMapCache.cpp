/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** HashMapCache
*/

#include "HashMapCache.hpp"
#include <cassert>

namespace nts {

size_t g_current_tick = 0;

//static map
static std::unordered_map<CacheKey, CacheEntry, CacheKeyHash> cache;

nts::Tristate compute_cached(nts::IComponent* comp, std::size_t pin)
{
    if (!comp)
        return Undefined;
    CacheKey key{comp, pin};
    auto it = cache.find(key); //check if key already exits in map

    if (it != cache.end() && it->second.tick == g_current_tick) {
        if (it->second.state == CS_Done)
            return it->second.value; //we already computed and we can just return
        if (it->second.state == CS_InProgress)
            return Undefined; //smth sketchy goin on and we return undef
    }

    //if it didn't exist before now it does. TODO: does this cause mem leak
    CacheEntry &entry = cache[key];
    entry.tick = g_current_tick;
    entry.state = CS_InProgress;

    //we call the real comput which will call getLink, which will call compute_cached
    nts::Tristate result = comp->compute(pin);

    //da result
    entry.value = result;
    entry.state = CS_Done;
    return result;
}

//every time tick ends, we need to clear contentes
void clear_cache()
{
    cache.clear();
}

}