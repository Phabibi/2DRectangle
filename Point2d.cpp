#include "Point2d.h"

Point2d::Point2d(const Point2d& P)
{
    x = P.get_x();
    y = P.get_y();
}
/* checks weather two points are on the same x axis, used to validate corners of rectangles */
bool Point2d::is_x_axis_aligned(const Point2d p2) const
{
    return p2.get_y() == y;
}

/* checks weather two points are on the same y axis used to validate corners of rectangles*/
bool Point2d::is_y_axis_aligned(const Point2d p2) const
{
    return p2.get_x() == x;
}

std::ostream& operator<<(std::ostream& os, const Point2d& p)
{
    std::cout << "(" <<  p.get_x() << "," << p.get_y() << ")";  
    return os;
}









