#include <iostream>
#include <vector>
#include "Circle.h"
#include "Rectangle.h"

using namespace std;

int main() {
    vector<Shape*> shapes;

    Shape* c = new Circle(1.0f);
    dynamic_cast<Circle*>(c)->SetRadius(3.0f); // Safe downcast
    Shape* r = new Rectangle(4.0f, 5.0f);

    shapes.push_back(c);
    shapes.push_back(r);

    for (size_t i = 0; i < shapes.size(); ++i) {
        cout << "Area: " << shapes[i]->Area() << endl;

        // Print radius if Circle
        Circle* circlePtr = dynamic_cast<Circle*>(shapes[i]);
        if (circlePtr) {
            cout << "  Radius: " << circlePtr->GetRadius() << endl;
        }
    }

    // Memory cleanup
    for (Shape* shape : shapes) {
        delete shape;
    }

    return 0;
}
