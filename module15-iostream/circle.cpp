#include "circle.h"

circle::circle(double x, double y, double radius) : x(x), y(y), radius(radius) {}

double circle::getX() const {
    return x;
}

double circle::getY() const {
    return y;
}

double circle::getRadius() const {
    return radius;
}

double circle::area() const {
    return 3.1415 * radius * radius;
}

std::ostream &operator<<(std::ostream &os, const circle &circle) {
    os << "{ \"x\": " << circle.x << ", \"y\": " << circle.y << ", \"radius\": " << circle.radius << " }";
    return os;
}
