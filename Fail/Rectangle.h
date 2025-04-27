#pragma once
#include "Shape.h"

class Rectangle : public Shape {
    public:
        Rectangle(float w, float h);
        ~Rectangle();

        float Area() const override;

    private:
        float m_width;
        float m_height;
};

