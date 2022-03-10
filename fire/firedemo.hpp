////////////////////////////////////////////////////////////////////////////////
// Fire Demo
// Copyright (C) 2022 Ryan Clarke <kj6msg@icloud.com>
////////////////////////////////////////////////////////////////////////////////

#ifndef FIRE_HPP
#define FIRE_HPP

#include "demoapp.hpp"

#include <SFML/Config.hpp>

#include <random>


////////////////////////////////////////////////////////////////////////////////
class FireDemo : public DemoApp
{
  public:
    FireDemo();

  private:
    std::default_random_engine m_engine;
    std::uniform_int_distribution<sf::Uint8> m_dist;

    void animate() override;
};


#endif   // FIREDEMO_HPP
