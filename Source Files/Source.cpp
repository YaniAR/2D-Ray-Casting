#include "Source.h"
#include "Constants.h"
#include <algorithm>

Source::Source(int x, int y, int tRays) 
    : m_x{ x }, m_y{ y }, totalRays{ tRays }, fov{ 90 }
{
    m_rays.reserve(totalRays);
    for (int i{ 0 }; i < totalRays; ++i)
    {
        float angle = (360 / totalRays) * i;
        //if((angle >= 0 && angle < fov / 2) || (angle > (360 - (fov / 2)) && angle <= 360) )
        if(angle >= 0 && angle <= 360)
            m_rays.emplace_back(x, y, (360 / totalRays) * i);
    }
}

void Source::move(float x, float y)
{
    for (int i{ 0 }; i < m_rays.size(); ++i)
    {
        m_rays[i].move(x, y);
    }
}

void Source::draw(sf::RenderWindow& window) const
{
    for (int i{ 0 }; i < m_rays.size(); ++i)
    {
        m_rays[i].draw(window);
    }
}

void Source::checkWalls(const std::vector<Wall>& walls)
{
    for (auto& ray : m_rays)
    {
        float shortestMagnitude{ (float)sqrt(pow(SCREEN_WIDTH, 2) + pow(SCREEN_HEIGHT, 2)) };
        for (const auto& wall : walls)
        {
            ray.cast(wall, shortestMagnitude);
        }
    }
}

void Source::point(float x1, float y1)
{
}

void Source::setFov(int value) { fov = value; }

Source::~Source()
{
}