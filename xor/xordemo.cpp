////////////////////////////////////////////////////////////////////////////////
// XOR Demo
// Copyright (C) 2022 Ryan Clarke <kj6msg@icloud.com>
////////////////////////////////////////////////////////////////////////////////

#include <vector>
#include <gsl/util>
#include <SFML/Graphics.hpp>
#include "xordemo.hpp"


////////////////////////////////////////////////////////////////////////////////
// Public Member Functions
////////////////////////////////////////////////////////////////////////////////
XORDemo::XORDemo()
{
    gsl::index p{0};

    for(int y{0}; y != height; ++y)
    {
        for(int x{0}; x != width; ++x)
        {
            auto v = static_cast<sf::Uint8>((x ^ y) & 0xFF);
            m_pixels[p++] = v;
            m_pixels[p++] = v;
            m_pixels[p++] = v;
            m_pixels[p++] = 255;
        }
    }

    m_texture.update(m_pixels.data());
}
