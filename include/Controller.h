#pragma once

#include "macros.h"
#include "Data.h"
#include "IncMenus/GameMenu.h"
#include "IncMenus/MusicButton.h"
#include "IncMenus/PauseButton.h"
#include "IncMenus/OpenMenuButton.h"

#include "IncMenus/OpenMenu.h"
#include "IncMenus/ChooseVehicleMenu.h"
#include "IncMenus/PlayMenu.h"
#include "MyContactListener.h"

class Controller {

public:
    Controller();

    void run();

private:
    void DataSetup(MyContactListener *);

    void setMenus();

    long CurrMenu();

    void handleEvents();

    void mouseEventPressed(const Event &);

    void mouseEventMoved(const Event &);

    void keyboardPressed(const sf::Event &);

    void draw();

    void exitGame(const Event &);

    RenderWindow m_gameWindow = {VideoMode(1600, 900), "Death Chase"};

    std::vector<sf::View> m_views;

    Data m_data;

    vector<bool> m_windows = {true, false, false, false, false};

    vector<unique_ptr<GameMenu>> m_menus;

    bool m_userMoved;
};
