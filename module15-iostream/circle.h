#ifndef MODULE15_IOSTREAM_CIRCLE_H
#define MODULE15_IOSTREAM_CIRCLE_H

#include <ostream>

class circle {
    double x,y,radius;
public:
    circle(double x=0.0, double y=0.0, double radius=1.0);

    double getX() const;

    double getY() const;

    double getRadius() const;
    virtual double area() const ;

    friend std::ostream &operator<<(std::ostream &os, const circle &circle);
};

std::ostream &operator<<(std::ostream &os, const circle &circle);

#endif //MODULE15_IOSTREAM_CIRCLE_H
