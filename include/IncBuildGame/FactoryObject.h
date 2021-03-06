#pragma once

#include "macros.h"
#include "IncObjects/CarObjects.h"
#include "IncObjects/StaticObject.h"

template<typename T>
class FactoryObject {
public:
    using pFnc = std::unique_ptr<T>(*)(std::unique_ptr<b2World> &world,
                                       const sf::Vector2f &,
                                       const float);

    static std::unique_ptr<T> create(std::unique_ptr<b2World> &,
                                     const std::string &,
                                     const sf::Vector2f &,
                                     const float);

    static bool registerIt(const std::string &, pFnc);

    static bool checkIfNameInMap(const std::string &name) { return FactoryObject::getMap().count(name) > 0; }

private:
    static auto &getMap() {
        static std::map<std::string, pFnc> m_map;
        return m_map;
    }
};

template<typename T>
std::unique_ptr<T> FactoryObject<T>::create(std::unique_ptr<b2World> &world,
                                            const std::string &name,
                                            const sf::Vector2f &position,
                                            const float rotation) {
    auto it = FactoryObject::getMap().find(name);
    if (it == FactoryObject::getMap().end())
        return nullptr;
    return it->second(world, position, rotation);
}

template<typename T>
bool FactoryObject<T>::registerIt(const std::string &name, pFnc f) {
    FactoryObject::getMap().emplace(name, f);
    return true;
}