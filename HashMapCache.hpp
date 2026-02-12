/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** HashMapCache
*/

#ifndef INCLUDED_HASHMAPCACHE_HPP
    #define INCLUDED_HASHMAPCACHE_HPP

#include "IComponent.hpp"
#include <unordered_map>
#include <cstdint>

namespace nts {

    extern size_t g_current_tick; //our global variable



struct CacheKey { //component to a key
    IComponent* comp;
    size_t pin;
    bool operator==(CacheKey const& o) const noexcept {
        return comp == o.comp && pin == o.pin;
    }
};

enum CacheState {
    CS_None = 0,
    CS_InProgress = 1,
    CS_Done = 2
};

struct CacheKeyHash { //had to look this up ngl, don't really get it
    std::size_t operator()(CacheKey const& k) const noexcept {
        // combine pointer and pin into a size_t hash
        auto p = reinterpret_cast<uintptr_t>(k.comp);
        return (p >> 4) ^ (k.pin * 0x9e3779b97f4a7c15ULL);
    }
};

struct CacheEntry {//this what the cashe holds
    size_t tick = 0;
    CacheState state = CS_None;
    Tristate value = Undefined;
};

Tristate compute_hashmap(IComponent* comp, size_t pin);


}

#endif
