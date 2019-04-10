#include "particle_system.h"



extern const sf::Vector2u WINDOW_SIZES;



Particle::Particle(
    const sf::Vector2f position,
    const sf::Vector2f velocity,
    const sf::Vector2f acceleration,
    const float radius)
    : position_(position), 
    velocity_(velocity),  
    acceleration_(acceleration),
    radius_(radius)
{
    shape_.setRadius(radius_);
    shape_.setFillColor(sf::Color::Magenta);
    shape_.setOrigin(sf::Vector2f(radius_, radius_));
    shape_.setPosition(position_);

}



void Particle::Push(const sf::Vector2f delta_velocity)
{
    velocity_ += delta_velocity;
}



void Particle::Update(const float dt)
{
    position_ += velocity_ * dt;
    velocity_ += acceleration_ * dt;

    if (position_.x < radius_)
    {
        position_.x = radius_;
        velocity_.x = -velocity_.x / 2.0f;
    }
    if (position_.y < radius_)
    {
        position_.y = radius_;
        velocity_.y = -velocity_.y / 2.0f;
    }
    if (position_.x + radius_ > WINDOW_SIZES.x)
    {
        position_.x = WINDOW_SIZES.x - radius_;
        velocity_.x = -velocity_.x / 2.0f;
    }
    const float bottom_gap = 50.0f;
    if (position_.y + radius_ + bottom_gap > WINDOW_SIZES.y)
    {
        position_.y = WINDOW_SIZES.y - radius_ - bottom_gap;
        velocity_.y = -velocity_.y / 2.0f;
    }
}



void Particle::Render(sf::RenderWindow& window)
{
    shape_.setPosition(position_);
    shape_.setRadius(radius_);

    window.draw(shape_);
}



ParticleSystem::ParticleID ParticleSystem::AddParticle(const sf::Vector2f position,
    const sf::Vector2f velocity,
    const sf::Vector2f acceleration,
    const float radius)
{
    Particle new_particle(position, velocity, acceleration, radius);
    particles_.push_back(new_particle);

    return particles_.size() - 1;
}



void ParticleSystem::RemoveParticle(const ParticleID particle_id)
{
    if (particle_id < particles_.size())
    {
        particles_.erase(particles_.begin() + particle_id);
    }
}



void ParticleSystem::Update(const float dt)
{
    for (size_t i = 0; i < particles_.size(); i++)
    {
        particles_[i].Update(dt);
    }
}



void ParticleSystem::Render(sf::RenderWindow& window)
{
    for (size_t i = 0; i < particles_.size(); i++)
    {
        particles_[i].Render(window);
    }
}



void ParticleSystem::Push(const sf::Vector2f delta_velocity)
{
    for (size_t i = 0; i < particles_.size(); i++)
    {
        particles_[i].Push(delta_velocity);
    }
} 


