/* STD */ 
#include <iostream>
#include <vector>

/*rectangle*/
#include "2DRectangles.cpp"

int main(){
    std::cout << "====================test 1 (bad rectangle with - width,height) =========================" << std::endl;
    Point2d p_b(0.0,0.0);
    Rectangle rec_b(p_b, -5.0 , -5.0 );
    std::cout << "====================test 1 (good rectnalge) =========================" << std::endl;
    Point2d p(0.0,0.0);
    Rectangle rec(p, 5.0 , 5.0 );
    std::cout << "rectangle = " << rec << std::endl;
    
    std::cout << "====================test 1 (is_contained invalid) =========================" << std::endl;

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
            std::cout << err<< " point = " << p_test << std::endl; 
        }

    std::cout << "====================test 2(point contained valid)=========================" << std::endl;
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


    std::cout << "====================test 3 (rectangle collide) =========================" << std::endl;
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
    std::cout << "====================test 4 (rectangle not collide) =========================" << std::endl;
    Point2d p_test_3(-100.0,-100.0);
    Rectangle rec3(p_test_3,40.0,40.0);

    try{
        if(rec.is_intersected(rec3))
        {
            std::cout << "the rectangle : " << rec3 << " collided with the rectangle : " << rec << std::endl;
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

    std::cout << "====================test 5 (collide with the same rectangle) =========================" << std::endl;
    Point2d p_test_4(0.0,0.0);
    Rectangle rec4(p_test_4,5.0,5.0);

    try{
        if(rec.is_intersected(rec4))
        {
            std::cout << "the rectangle : " << rec4 << " collided with the rectangle : " << rec << std::endl;
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

