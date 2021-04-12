#include "2DRectangles.h"
#include <cstdlib>

Rectangle::Rectangle(Point2d _point, float _width, float _height)
{
    // set width and height, using abs to make sure theyre positive  
    width = abs(_width);
    height = abs(_height);

    // bottom left corner (x,y)
    bottom_left = _point;
    // bottom right corner (x + w, y)
    bottom_right = Point2d(_point.get_x() + width , _point.get_y());
    // top left corner (x, y+h)
    top_left = Point2d(_point.get_x(), _point.get_y() + height);
    //top right corner (x+w , y+h)
    top_right = Point2d(_point.get_x()+ width, _point.get_y() + height);

    //surface area 
    area = width*height;
}


Rectangle::Rectangle(const Rectangle& rec)
{
    bottom_left = rec.get_bottom_l();
    bottom_right = rec.get_bottom_r();
    top_left = rec.get_top_l();
    top_right = rec.get_top_r();
    height = rec.get_height();
    width = rec.get_width();
    area = rec.get_area();
}

bool Rectangle::is_contained(const Point2d p) 
{
    /*inorder for the point to be contained within the rectangle, its x and y coordinates should always be within bottom_left_corner and top_right_corner coordinates
     */
    return (p.get_x() >= bottom_left.get_x() && p.get_x() <= top_right.get_x()) 
        && (p.get_y() >= bottom_left.get_y() && p.get_y() <= top_right.get_y());  
}



bool Rectangle::is_to_right(Rectangle rec) 
{
    return (bottom_left.get_y() > rec.get_top_r().get_y()) 
        || (top_right.get_y() < rec.get_bottom_l().get_y());
}

bool Rectangle::is_below(Rectangle rec)
{
    return (bottom_left.get_x() > rec.get_top_r().get_x()) 
        || (top_right.get_x() < rec.get_bottom_l().get_x());
}

bool Rectangle::is_intersected(Rectangle rec) 
{
    /* there are 4 cases we need to consider :
     * 1. rec is above our rectangle
     * 2. rec is below our rectangle
     * 3. rec is to the left of our rectangle
     * 4. rec is to the right of our rectangle
     * however this can be furthered reduced for example :
     * assume we have R1 and R2, we dont have a collision if (R1 is_above R2 || R2 is_above R1 || R1 is_blow R2 ||R2 is_below R1) | but using demorgans law we can reduce this to R1 is_above R2. a similar argument could be done for the left and right edges. Thus we end up with 2 cases we need to check:
     * 1.if R1 is_above R2 || R1 is_left_of R2
     */
    return is_to_right(rec) && is_below(rec); 

}

Rectangle& Rectangle::operator =(const Rectangle& rec)
{
    bottom_left = rec.get_bottom_l();
    bottom_right = rec.get_bottom_r();
    top_left = rec.get_top_l();
    top_right = rec.get_top_r();
    height = rec.get_height();
    width = rec.get_width();
    area = rec.get_area();
    return *this;

}



std::ostream& operator<<(std::ostream& os, const Rectangle& rec)
{
    std::cout << rec.bottom_left << " , " << rec.bottom_right << " , " << rec.top_left << " , " << rec.top_right; 

    return os;
}






