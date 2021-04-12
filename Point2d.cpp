#include "Point2d.h"

Point2d::Point2d(const Point2d& P)
{
    x = P.get_x();
    y = P.get_y();
}

std::ostream& operator<<(std::ostream& os, const Point2d& p)
{
    std::cout << "(" <<  p.get_x() << "," << p.get_y() << ")";  
    return os;
}









