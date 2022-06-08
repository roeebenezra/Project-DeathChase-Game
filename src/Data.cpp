#include "Data.h"

//__________
Data::Data() {
    setWorld();
    m_map.readMapFile(*this);
}

//__________________
void Data::setWorld() {
    //set gravity
    b2Vec2 gravity(0.0f, 10.f);
    m_world = std::make_unique<b2World>(gravity);
}

//______________________
void Data::setWorldStep() {
    m_world->Step(m_timeStep, m_velocityIterations, m_positionIterations);
}

//__________________________________
void Data::setObject(std::string &name,
                     const sf::Vector2f &position,
                     const sf::Vector2f &scale) {
    if (FactoryObject<MovingObject>::checkIfNameInMap(name)) {
        m_moving.push_back(FactoryObject<MovingObject>::create(m_world, name, position, scale));
        return;
    }
    if (FactoryObject<StaticObject>::checkIfNameInMap(name)) {
        m_static.push_back(FactoryObject<StaticObject>::create(m_world, name, position, scale));
        return;
    }
}

//____________________________________________
void Data::moveUserCar(const sf::Event &event) {
    m_moving[User]->move(event);
}

//_________________________________________________
void Data::moveComputerCars(const sf::Event &event) {
    for (auto &moving: m_moving)
        if (moving != m_moving[User])
            moving->move(event);
}

//____________________________________________________________________________
void Data::drawData(sf::RenderWindow &window, const unique_ptr<GameMenu> &menu) {

    for (auto &moving: m_moving)
        moving->draw(window);

    for (auto &statics: m_static)
        statics->draw(window);

    menu->getButton(0)->updatePos(Vector2f(getUserPosition().x + 2000, 50));

    setView(window);
}

//__________________________________________
void Data::setView(sf::RenderWindow &window) {
    auto view = window.getView();
    view.setCenter(getUserPosition().x + 500, 1000);
    view.setSize(3500.0f, 2000.0f);
    window.setView(view);
}