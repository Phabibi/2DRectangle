/* STD */ 
#include <iostream>
#include <vector>

/*rectangle*/
#include "2DRectangles.cpp"

int main(){
    Point2d p(0.0,0.0);
    Rectangle rec(p, 5.0 , 5.0 );
    
    std::cout << "====================test 1=========================" << std::endl;
    std::cout << "rectangle = " << rec << std::endl;

    //tries to set bottom left to -1,-1 (should be invalid) */
    Point2d p_test(-2.0,-2.0);
    try{
        if(rec.is_contained(p_test))
        {
            std::cout << "the point : " << p_test << " is cotained within the rectangle : " << rec << std::endl;
        }
        else 
        {
            throw("the point is not contained within the rectangle");
        }
    }

        catch(const char* err)
        {
            std::cout << err << std::endl; 
        }

    std::cout << "====================test 2=========================" << std::endl;
    Point2d p_test_1(2.0,1.0);
    try{
        if(rec.is_contained(p_test_1))
        {
            std::cout << "the point : " << p_test_1 << " is cotained within the rectangle : " << rec << std::endl;
        }
        else 
        {
            throw("the point is not contained within the rectangle");
        }
    }

        catch(const char* err)
        {
            std::cout << err << std::endl; 
        }


    std::cout << "====================test 3=========================" << std::endl;
    Point2d p_test_2(-2.0,-2.0);
    Rectangle rec2(p_test_2,40.0,40.0);

    try{
        if(rec.is_intersected(rec2))
        {
            std::cout << "the rectangle : " << rec2 << " collided with the rectangle : " << rec << std::endl;
        }
        else 
        {
            throw("did not collide");
        }
    }

        catch(const char* err)
        {
            std::cout << err << std::endl; 
        }

    return 0;
}

