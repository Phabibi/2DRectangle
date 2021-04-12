/*point2d*/
#include "Point2d.cpp"

/*
Specifacations: 
Design and Implement a C++ program that implements the following:
• 2D Rectangle Class with floating point coordinates
     Include methods for constructing an axis-aligned Rectangle with initial size and
coordinates
    Include a Copy constructor and an Assignment operator
• Algorithm that checks whether or not a 2D point is contained in an axis-aligned Rectangle
• Algorithm that checks whether or not two axis-aligned Rectangles intersect
• Simple test code that creates instances of your class and tests your implementation
 */

/*
 * (top_right)--------------------------(top_left)
 *            |                         |
 *            |                         |   
 *            |                         |   
 *            |                         |
 * (bottom_left)------------------------(bottom_right)
 *
 *
 */ 

class Rectangle
{
    public:
        
        /*consturctor for an axis-aligned rectangle given a point, width and height*/
        Rectangle(Point2d _point, float _width, float _height);

        /*default destructor*/
        ~Rectangle()=default;

        /*getters*/
        Point2d get_bottom_l() const {return bottom_left;};
        Point2d get_bottom_r() const {return bottom_right;};
        Point2d get_top_l() const {return top_left;};
        Point2d get_top_r() const {return top_right;};
        float get_height() const {return height;};
        float get_width() const {return width;};
        double get_area() const { return area;};

        /*copy constuctor*/
        Rectangle(const Rectangle& rec);

        /*Assignment operators*/
        Rectangle& operator = (const Rectangle& rec);
        friend std::ostream& operator << (std::ostream& os, const Rectangle& rec);

        
        /*checks to see if a rectangle is located  to the right of our rectangle*/
        bool is_to_right(Rectangle rec);

        /*checks to see if a rectangle is located below our rectangle*/
        bool is_below(Rectangle rec) ;

        /* Algorithm that checks whether or not a 2D point is contained in an axis-aligned Rectangle*/
        bool is_contained(const Point2d point) ;

       /* Algorithm that checks whether or not two axis-aligned Rectangles intersect */
       bool is_intersected(Rectangle rec);  

    private: 
        /*bottom left corner point (starting)*/
        Point2d bottom_left;

        /*rest of the points*/
        Point2d bottom_right;
        Point2d top_right;
        Point2d top_left;

        /*width and height*/
        float width; 
        float height;

        /* surface area */
        double area;





};


