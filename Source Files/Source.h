#ifndef SOURCE_H
#define SOURCE_H

#include "Ray.h"

class Source
{
private:
    int m_x{}, m_y{}, totalRays{}, fov;
    std::vector<Ray> m_rays{};
    std::vector<Line> m_lines;
public:
    Source(int x, int y, int beamCount);
    ~Source();
    void draw(sf::RenderWindow& window) const;
    void move(float x, float y);
    void point(float x, float y);
    void checkWalls(const std::vector<Wall>& walls);

    void setFov(int value);
    std::vector<Ray> getRay() { return m_rays;  }
};

#endif