#pragma once

#include <SFML/Graphics.hpp>
#include <exception>



class Particle
{
public:
    Particle(const sf::Vector2f position,
        const sf::Vector2f velocity,
        const sf::Vector2f acceleration,
        const float radius);
    virtual ~Particle() = default;

    void Push(const sf::Vector2f delta_velocity);

    void Update(const float dt);
    void Render(sf::RenderWindow& window);



private:
    sf::Vector2f position_;
    sf::Vector2f velocity_;
    sf::Vector2f acceleration_;
    float radius_;

    sf::CircleShape shape_;
};



class ParticleSystem
{
public:
    ParticleSystem() = default;
    virtual ~ParticleSystem() = default;

    using ParticleID = size_t;

    ParticleID AddParticle(const sf::Vector2f position,
        const sf::Vector2f velocity,
        const sf::Vector2f acceleration,
        const float radius);

    void RemoveParticle(const ParticleID particle_id);

    void Update(const float dt);
    void Render(sf::RenderWindow& window);
    void Push(const sf::Vector2f delta_velocity);

private:
    std::vector<Particle> particles_;

};