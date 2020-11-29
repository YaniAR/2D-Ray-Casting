#ifndef WALL_H
#define WALL_H

#include "Line.h"

class Wall
{
private:
    int m_x1{}, m_y1{}, m_x2{}, m_y2{};
    Line m_line;
public:
    Wall(int x1, int y1, int x2, int y2);
    ~Wall();
    void draw(sf::RenderWindow& window) const;
    int getX1() const { return m_x1; }
    int getY1() const { return m_y1; }
    int getX2() const { return m_x2; }
    int getY2() const { return m_y2; }
};

#endif