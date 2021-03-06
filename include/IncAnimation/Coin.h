#pragma once

#include "IncObjects/StaticObject.h"
#include "IncBuildGame/FactoryObject.h"

class Coin : public StaticObject {
public:
    Coin(const unsigned&,
         std::unique_ptr<b2World> &,
         const sf::Vector2f &,
         const float&,
         const b2BodyType&,
         const int16&);

    void draw(sf::RenderWindow &) override;

private:
    static bool m_registerIt;
    Animation m_animation;
    sf::Clock m_aiTime;
};