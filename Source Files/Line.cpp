#include "Line.h"
#include "Constants.h"

Line::Line(float x1, float y1, float x2, float y2, float thickness)
    : m_x1{ x1 }, m_y1{ y1 }, m_x2{ x2 }, m_y2{ y2 }, m_thickness{ thickness }
{
    float magnitude{ (float)sqrt(pow((m_x2 - m_x1), 2) + pow((m_y2 - m_y1), 2)) };
    
    m_rect = sf::RectangleShape(sf::Vector2f{ magnitude, m_thickness });
    m_angle = float(atan((m_y2 - m_y1) / (m_x2 - m_x1))) * 180 / M_PI;
    
    // Shape settings
    m_rect.setOrigin(0, m_thickness / 2);
    m_rect.setPosition(sf::Vector2f(m_x1, m_y1));
    m_rect.rotate(m_angle);
    m_rect.setFillColor(sf::Color(255, 255, 255, 250));
}

Line::Line(float x1, float y1, float angle, float thickness)
    : m_x1{ x1 }, m_y1{ y1 }, m_angle{ angle }, m_thickness{ thickness }
{
    float magnitude{ (float)sqrt(pow((m_x2 - m_x1), 2) + pow((m_y2 - m_y1), 2)) };
    m_rect = sf::RectangleShape(sf::Vector2f(magnitude, m_thickness));

    // Shape settings
    m_rect.setOrigin(0, m_thickness / 2);
    m_rect.setPosition(sf::Vector2f(m_x1, m_y1));
    m_rect.rotate(m_angle);
    calculateEndPoints();
    m_rect.setFillColor(sf::Color(255, 255, 255, 50));
}

void Line::setLength(float len)
{
    m_rect.setSize(sf::Vector2f{ len, m_thickness });
}

void Line::setEndPoint(float x, float y)
{
    m_x2 = x;
    m_y2 = y;
    m_rect.setSize(sf::Vector2f(sqrt(pow(float(m_x2 - m_x1), 2) + pow(float(m_y2 - m_y1), 2)), m_thickness));
}

void Line::calculateEndPoints()
{
    float magnitude{ sqrt(pow(m_rect.getSize().x, 2) + pow(m_rect.getSize().y, 2)) };
    if (m_angle >= 0 && m_angle <= 90)
    {
        m_x2 = m_x1 + cos(m_angle * RAD) * magnitude;
        m_y2 = m_y1 + sin(m_angle * RAD) * magnitude;
    }
    else if (m_angle >= 90 && m_angle <= 180)
    {
        m_x2 = m_x1 - cos((180 - m_angle) * RAD) * magnitude;
        m_y2 = m_y1 + sin((180 - m_angle) * RAD) * magnitude;
    }
    else if (m_angle >= 180 && m_angle <= 270)
    {
        m_x2 = m_x1 - cos((m_angle - 180) * RAD) * magnitude;
        m_y2 = m_y1 - sin((m_angle - 180) * RAD) * magnitude;
    }
    else
    {
        m_x2 = m_x1 + cos((360 - m_angle) * RAD) * magnitude;
        m_y2 = m_y1 - sin((360 - m_angle) * RAD) * magnitude;
    }
}

void Line::move(float x, float y)
{
    m_x1 = x;
    m_y1 = y;
    calculateEndPoints();
    m_rect.setPosition(sf::Vector2f(m_x1, m_y1));
}

void Line::draw(sf::RenderWindow& window) const
{
    window.draw(m_rect);
}

Line::~Line()
{
}