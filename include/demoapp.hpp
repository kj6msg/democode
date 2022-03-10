////////////////////////////////////////////////////////////////////////////////
// Demo App
// Copyright (C) 2022 Ryan Clarke <kj6msg@icloud.com>
////////////////////////////////////////////////////////////////////////////////

#ifndef DEMOAPP_HPP
#define DEMOAPP_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <vector>


////////////////////////////////////////////////////////////////////////////////
class DemoApp
{
  public:
    static constexpr int width{320};
    static constexpr int height{200};

    DemoApp()
        : m_palette(256), m_indices(width * height),
          m_pixels(width * height * 4),
          m_window(sf::VideoMode::getFullscreenModes().front(), "Demo App",
              sf::Style::Fullscreen)
    {
        m_texture.create(width, height);
        m_texture.update(m_pixels.data());
        m_sprite.setTexture(m_texture);

        m_window.setView(sf::View(
            sf::FloatRect(0.0f, 0.0f, static_cast<float>(DemoApp::width),
                static_cast<float>(DemoApp::height))));
        m_window.setFramerateLimit(60);
        m_window.setMouseCursorVisible(false);
    };

    virtual void run()
    {
        while(m_window.isOpen())
        {
            for(sf::Event event; m_window.pollEvent(event);)
            {
                if(event.type == sf::Event::Closed)
                    m_window.close();
            }

            animate();

            m_window.clear();
            m_window.draw(m_sprite);
            m_window.display();
        }
    };

  protected:
    std::vector<sf::Color> m_palette;
    std::vector<sf::Uint8> m_indices;
    std::vector<sf::Uint8> m_pixels;

    sf::Texture m_texture;
    sf::Sprite m_sprite;
    sf::RenderWindow m_window;

    virtual void animate() = 0;
};


#endif   // DEMOAPP_HPP
