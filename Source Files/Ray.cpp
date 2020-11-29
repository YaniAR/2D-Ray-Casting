#include "Ray.h"
#include "Constants.h"


Ray::Ray(float x, int y, float angle)
    : m_x(x), m_y(y), m_angle(angle), m_line(x, y, angle, 2)
{
}

void Ray::draw(sf::RenderWindow& window) const
{
    m_line.draw(window);
}

bool Ray::cast(const Wall& wall, float& shortestmagnitude)
{
    // Line positions
    float x1{ m_line.getX1() };
    float y1{ m_line.getY1() };
    float x2{ m_line.getX2() };
    float y2{ m_line.getY2() };

    // Wall positions
    int x3{ wall.getX1() };
    int y3{ wall.getY1() };
    int x4{ wall.getX2() };
    int y4{ wall.getY2() };

    float num1{ (x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4) };
    float num2{ -((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) };
    float denom{ (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4) };
    
    if (denom != 0)
    {
        const float t{ num1 / denom };
        const float u{ num2 / denom };
        if (u > 0 && t > 0 && u < 1) // Line intersects
        {
            float intersection_x{ x1 + t * (x2 - x1) };
            float intersection_y{ y1 + t * (y2 - y1) };
            float magnitude{ sqrt(pow(intersection_x - x1, 2) + pow(intersection_y - y1, 2)) };
            if (magnitude < shortestmagnitude)
            {
                shortestmagnitude = magnitude;
                m_line.setEndPoint(intersection_x, intersection_y);
            }

            return true;
            
        }
        if(shortestmagnitude == (float)sqrt(pow(SCREEN_WIDTH, 2) + pow(SCREEN_HEIGHT, 2)))  // doesn't intersect the wall
            m_line.setLength(sqrt(pow(SCREEN_WIDTH, 2) + pow(SCREEN_HEIGHT, 2))); 
       
    }
    else
    {
        m_line.setLength(sqrt(pow(SCREEN_WIDTH, 2) + pow(SCREEN_HEIGHT, 2))); // parrallel to wall
    }

    return false;
}

void Ray::move(float x, float y)
{
    m_x = x;
    m_y = y;
    m_line.move(x, y);
}

Ray::~Ray()
{
}