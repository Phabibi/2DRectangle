#include "2DRectangles.h"

Rectangle::Rectangle(const Point2d& bottom_l, float _width, float _height)
{
    try {
       // set width and height, using abs to make sure theyre positive  
       width = _width;
       height = _height;
       if( !(width > 0.0 && height > 0.0) ) 
       {
           throw ("width and height must be positive");
       }
       
    }
    catch(const char* err) {
        std::cout << err << std::endl;
    }

    // bottom left corner (x,y)
    bottom_left = bottom_l;
    // bottom right corner (x + w, y)
    bottom_right = Point2d(bottom_l.get_x() + width , bottom_l.get_y());
    // top left corner (x, y+h)
    top_left = Point2d(bottom_l.get_x(), bottom_l.get_y() + height);
    //top right corner (x+w , y+h)
    top_right = Point2d(bottom_l.get_x()+ width, bottom_l.get_y() + height);

    //surface area 
    area = width*height;
}

/*assumes the first param is the bottom left corner and second param is top right corner*/
Rectangle::Rectangle(const Point2d& bottom_l , const Point2d& top_r)
{
    try{
        if(bottom_l.get_x() < top_r.get_x() && bottom_l.get_y() < top_r.get_y())
        {
            //valid rectangle 
            width = top_r.get_x() - bottom_l.get_x();
            height = top_r.get_y() - bottom_l.get_y();

            //set the two corners
            bottom_left = bottom_l;
            top_right = top_r;
            
            //the rest
            bottom_right = Point2d(bottom_left.get_x() + width , bottom_left.get_y());
            top_left = Point2d(bottom_left.get_x(), bottom_left.get_y() + height);
            area = width * height ;
        }

        else
        {
            throw ("could not initilize rectangle");
        }
        
    }
    catch (const char * err){
        std::cout << err << " bottom_left point must have coordinates smaller than top_right point" << std::endl;

    }

}



Rectangle::Rectangle(Rectangle& rec)
{
    bottom_left = rec.get_bottom_l();
    bottom_right = rec.get_bottom_r();
    top_left = rec.get_top_l();
    top_right = rec.get_top_r();
    height = rec.get_height();
    width = rec.get_width();
    area = rec.get_area();
}

bool Rectangle::is_contained(const Point2d& p) const 
{
    /*inorder for the point to be contained within the rectangle, its x and y coordinates should always be within bottom_left_corner and top_right_corner coordinates
     */
    return (p.get_x() >= bottom_left.get_x() && p.get_x() <= top_right.get_x()) 
        && (p.get_y() >= bottom_left.get_y() && p.get_y() <= top_right.get_y());  
}


/*inorder for rec to below, either our bottom left y is > rec top_right.y OR 
 * top right y < rec bottom left y. For the case in which we are above, bottom_left.get_y() will always be bigger than rev.get_top_r.y */

bool Rectangle::is_below(const Rectangle& rec) const 
{
    return (bottom_left.get_y() > rec.get_top_r().get_y()) 
        || (top_right.get_y() < rec.get_bottom_l().get_y());
}

/*it rec is to the right, then top_right_corners.x > bottom_left_corner.x or our
 *top right corner < rec.bottom_left_corner.x. if rec is to our left then
 *bottom_left.get_x is always > rec.top_right.x 
 */ 

bool Rectangle::is_to_right(const Rectangle& rec) const
{

    return (bottom_left.get_x() > rec.get_top_r().get_x()) 
        || (top_right.get_x() < rec.get_bottom_l().get_x());
}

bool Rectangle::is_intersected(const Rectangle& rec) const 
{
    /* there are 4 cases we need to consider :
     * 1. rec is above our rectangle
     * 2. rec is below our rectangle
     * 3. rec is to the left of our rectangle
     * 4. rec is to the right of our rectangle
     * however this can be furthered reduced for example :
     * assume we have R1 and R2, we dont have a collision if (R1 is_above R2 || R2 is_above R1 || R1 is_blow R2 ||R2 is_below R1) | but using demorgans law we can reduce this to R1 is_below R2. a similar argument could be done for the left and right edges. Thus we end up with 2 cases we need to check:
     * 1.if R1 is_above R2 
     * 2.if R1 is_right_of R2
     */
    if(is_to_right(rec))
    {
        return false;
    }
    if(is_below(rec))
    {
        return false;
    }
    return true;

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
    std::cout << rec.get_bottom_l() << " , " << rec.get_bottom_r()<< " , " << rec.get_top_l() << " , " << rec.get_top_r(); 

    return os;
}






