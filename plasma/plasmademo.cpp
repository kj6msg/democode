////////////////////////////////////////////////////////////////////////////////
// Plasma Demo
// Copyright (C) 2022 Ryan Clarke <kj6msg@icloud.com>
////////////////////////////////////////////////////////////////////////////////

#include "plasmademo.hpp"

#include <SFML/Graphics.hpp>
#include <gsl/util>

#include <algorithm>
#include <cmath>
#include <vector>


////////////////////////////////////////////////////////////////////////////////
// Public Member Functions
////////////////////////////////////////////////////////////////////////////////
PlasmaDemo::PlasmaDemo()
{
    // black (0, 0, 0) to white (255, 255, 255)
    for(gsl::index i{1}; i != 128; ++i)
        m_palette[i] = m_palette[i - 1] + sf::Color(2, 2, 2);

    // white (255, 255, 255) to black (0, 0, 0)
    std::reverse_copy(m_palette.begin(), m_palette.begin() + 128,
        m_palette.begin() + 128);

    // generate plasma
    for(int y{0}; y != height; ++y)
    {
        for(int x{0}; x != width; ++x)
        {
            auto color = (std::cosf(static_cast<float>(x) * 0.1f) +
                             std::sinf(static_cast<float>(y) * 0.1f)) *
                             63.5f +
                         128.0f;

            auto i = static_cast<gsl::index>(x + y * width);

            m_indices[i] = static_cast<sf::Uint8>(color);
        }
    }
}


////////////////////////////////////////////////////////////////////////////////
// Private Member Functions
////////////////////////////////////////////////////////////////////////////////
void PlasmaDemo::animate()
{
    std::rotate(m_palette.begin(), m_palette.begin() + 1, m_palette.end());

    for(gsl::index p{0}; const auto i : m_indices)
    {
        m_pixels[p++] = m_palette[static_cast<gsl::index>(i)].r;
        m_pixels[p++] = m_palette[static_cast<gsl::index>(i)].g;
        m_pixels[p++] = m_palette[static_cast<gsl::index>(i)].b;
        m_pixels[p++] = m_palette[static_cast<gsl::index>(i)].a;
    }

    m_texture.update(m_pixels.data());
}
