#pragma once

#include "macros.h"

class Resources {

public:
    static Resources &instance();

    Resources(const Resources &) = delete;

    void operator=(const Resources &) = delete;

    sf::Sprite &getSprite(const unsigned name){ return m_sprites[name]; }

    const sf::Texture &getTexture(const unsigned name) const { return m_texture[name]; }

    void playSound(unsigned);

    void stopSound(unsigned);

    void playInLoopSound(unsigned);

    void setSoundVol(unsigned, float);

private:
    Resources();

    void loadResources();

    std::vector<sf::Sprite> m_sprites;
    std::vector<sf::Texture> m_texture;

    std::vector<sf::SoundBuffer> m_soundsBuffer;
    std::vector<sf::Sound> m_sounds;
    sf::Font m_font;
};