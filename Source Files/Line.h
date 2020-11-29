#ifndef LINE_H
#define LINE_H

#include <SFML/Graphics.hpp>

class Line
{
private:
    float m_x1{}, m_y1{}, m_x2{}, m_y2{}, m_thickness{};
    float m_angle{};
    sf::RectangleShape m_rect{};
public:
    Line(float x1, float y1, float x2, float y2, float thickness);
    Line(float x1, float y1, float angle, float thickness);
    ~Line();
    void draw(sf::RenderWindow& window) const;
    void move(float x, float y);
    void calculateEndPoints();
    float getX1() const { return m_x1; }
    float getY1() const { return m_y1; }
    float getX2() const { return m_x2; }
    float getY2() const { return m_y2; }
    void setLength(float len);
    void setEndPoint(float x, float y);
};

#endif