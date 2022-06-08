#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <map>
#include <typeinfo>
#include <typeindex>
#include <memory>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Resources.h"
#include "box2d/box2d.h"

using namespace sf;
using namespace std;

const string FileName = "map.txt";

const string FontFile = "FontFile.ttf";


const std::vector Textures = {"PlayBackground.png", "truck.png", "redCar.png", "greenCar.png",
                              "ground_1.png", "ground_2.png", "ground_3.png", "ground_4.png",
                              "ground_5.png", "ground_8.png", "ground_9.png", "barrel.png",
                              "coin.png", "icon.png", "dust.png", "box.png", "healthObjectBar.png",
                              "one.png", "two.png", "three.png", "four.png", "five.png", "six.png",
                              "seven.png", "explosion.png", "water.png", "finishLine.png",
                              "openMenu.png", "musicIcons.png", "Buttons.png", "OpenMenuButtons.png"};

const int User = 0;

enum TextureRcs {
    PlayBackground,
    userCar,
    redCar,
    greenCar,
    ground_1,
    ground_2,
    ground_3,
    ground_4,
    ground_5,
    ground_8,
    ground_9,
    barrel,
    coin,
    icon,
    dust,
    box,
    healthBar,
    one,
    two,
    three,
    four,
    five,
    six,
    seven,
    explosion,
    water,
    finishLine,
    OpenMenuBackground,
    musicIcons,
    Buttons,
    OpenMenuButtons,
    TexturesCount
};

const vector Sounds = {"GameMenuSound.wav"};

enum SoundRcs {
    OpenSound,
    SoundsCount
};

enum Menus {
    OpenGameMenu,
    Play,
    HowToPlayMenu,
    ChooseCarMenu,
    InGameMenu,
    MenusCount
};

const int MenuButtonHeight = 102;
const int MenuButtonWidth = 285;

const int SoundButtonHeight = 125;
const int MusicButtonWidth = 100;
const int clicksButtonWidth = 150;

enum groupIndex {
    Collide = 3,
    DontCollide = -3,
    GroundCollide = 1,
    SensorCollide = -9,
};

const int carPLaceStart = three; // by the amount of cars in the game

const int carVelocity = 80;

const double carAngle = 0.05;

//animations time
const float dustTime = 0.06f;
const float coinTime = 0.2f;
const float healthTime = 0.6f;
const float explosionTime = 0.01f;

const sf::Vector2f carDustForward = {-150, 0};
const sf::Vector2f carDustBackward = {90, 0};

const sf::Vector2f healthBarOffset = {40, -80};
const sf::Vector2f explosionOffset = {0, -500};
const int carPlaceOffset = 150;

const sf::Vector2f regularScale = {1, 1};
const sf::Vector2f oppositeScale = {-1, -1};
