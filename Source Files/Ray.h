#ifndef RAY_H
#define RAY_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Line.h"
#include "Wall.h"

class Ray
{
private:
    float m_x{}, m_y{};
    Line m_line;
    float m_angle{};
public:
    Ray(float x, int y, float angle);
    ~Ray();
    void draw(sf::RenderWindow& window) const;
    void move(float x, float y);
    bool cast(const Wall& wall, float& magnitude);

    Line getLine() { return m_line; }
};

#endif
