#include "Circle.h"

Circle::Circle(float r) : m_radius(r) {}

Circle::~Circle() {}

float Circle::Area() const {
    return 3.14f * m_radius * m_radius;
}

void Circle::SetRadius(float radius) {
    m_radius = radius;
}

float Circle::GetRadius() const {
    return m_radius;
}
