#pragma once

#include "StaticObject.h"
#include "IncBuildGame/FactoryObject.h"

class Box : public StaticObject {

public:
    Box(const unsigned&,
        std::unique_ptr<b2World> &,
        const sf::Vector2f &,
        const float&,
        const b2BodyType&,
        const int16&);

private:
    static bool m_registerIt;
};