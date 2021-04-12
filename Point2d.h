#include <iostream> 

class Point2d
{
    public:
        
        /* default constructor */ 
        Point2d(){x = 0.0; y = 0.0;};
        
        /*consturctor for an axis-aligned rectangle*/
        Point2d(const float _x, const float _y){x = _x; y = _y;};
        ~Point2d() = default;

        /*copy constuctor*/
        Point2d(const Point2d &P);

        
        /*getters*/
        float get_x() const {return x;};
        float get_y() const {return y;}; 

        /*setters*/
        void set_x(float _x) {x = _x;};
        void set_y(float _y) {y = _y;};


    private: 
        float x;
        float y;
        
};

std::ostream& operator << (std::ostream& os, const Point2d& p);
