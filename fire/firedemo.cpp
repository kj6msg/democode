////////////////////////////////////////////////////////////////////////////////
// Fire Demo
// Copyright (C) 2022 Ryan Clarke <kj6msg@icloud.com>
////////////////////////////////////////////////////////////////////////////////

#include <algorithm>
#include <cmath>
#include <random>
#include <vector>
#include <gsl/util>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "firedemo.hpp"


////////////////////////////////////////////////////////////////////////////////
// Public Member Functions
////////////////////////////////////////////////////////////////////////////////
FireDemo::FireDemo() : m_engine(std::random_device{}()), m_dist(0, 255)
{
    m_window.setTitle("Fire Demo");

    // black (0, 0, 0) to red (128, 0, 0)
    for(gsl::index i{1}; i != 33; ++i)
        m_palette[i] = m_palette[i - 1] + sf::Color(4, 0, 0);

    // red (128, 0, 0) to orange (192, 128, 0)
    for(gsl::index i{33}; i != 65; ++i)
        m_palette[i] = m_palette[i - 1] + sf::Color(2, 4, 0);

    // orange (192, 128, 0) to yellow (192, 190, 0)
    for(gsl::index i{65}; i != 96; ++i)
        m_palette[i] = m_palette[i - 1] + sf::Color(0, 2, 0);

    // yellow (192, 192, 0) to white (255, 255, 255)
    // Linear interpolation: c = c0 + (c1 - c0) * (i - i0) / (i1 - i0)
    //      red   = 192 + (255 - 192) * (i - 96) / (255 - 96)
    //      green = 192 + (255 - 192) * (i - 96) / (255 - 96)
    //      blue  = 0 + (255 - 0) * (i - 96) / (255 - 96)
    for(gsl::index i{96}; i != 256; ++i)
    {
        auto t = (static_cast<float>(i) - 96.0f) / (255.0f - 96.0f);

        m_palette[i].r = static_cast<sf::Uint8>(std::lerp(192.0f, 255.0f, t));
        m_palette[i].g = static_cast<sf::Uint8>(std::lerp(192.0f, 255.0f, t));
        m_palette[i].b = static_cast<sf::Uint8>(std::lerp(0.0f, 255.0f, t));
    }
}


////////////////////////////////////////////////////////////////////////////////
void FireDemo::animate()
{
    // generate hot spots on bottom row of pixels
    std::generate(m_indices.end() - width, m_indices.end(), [&]()
    {
        return m_dist(m_engine);
    });

    auto w{static_cast<gsl::index>(width)};
    auto h{static_cast<gsl::index>(height)};

    for(gsl::index y{0}; y != h - 1; ++y)
    {
        for(gsl::index x{0}; x != w; ++x)
        {
            // Left below, right below, center below, and center two below
            // pixels. The divisor controls the height of the fire.
            gsl::index left    = ((x - 1 + w) % w) + w * (y + 1);
            gsl::index center  = x + w * (y + 1);
            gsl::index right   = ((x + 1) % w) + w * (y + 1);
            gsl::index twodown = x + w * ((y + 2) % h);

            auto new_color = static_cast<float>(m_indices[left])
                + static_cast<float>(m_indices[center])
                + static_cast<float>(m_indices[right])
                + static_cast<float>(m_indices[twodown]);
            new_color /= 4.03f;

            m_indices[x + w * y] = static_cast<sf::Uint8>(new_color);
        }
    }

    for(gsl::index p{0}; const auto i : m_indices)
    {
        m_pixels[p++] = m_palette[static_cast<gsl::index>(i)].r;
        m_pixels[p++] = m_palette[static_cast<gsl::index>(i)].g;
        m_pixels[p++] = m_palette[static_cast<gsl::index>(i)].b;
        m_pixels[p++] = m_palette[static_cast<gsl::index>(i)].a;
    }

    m_texture.update(m_pixels.data());
}
