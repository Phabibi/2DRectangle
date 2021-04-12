#include <iostream>
#include <vector>

unsigned int multiples(unsigned int n)
{
    //trivial case
    if(n == 1) {return 1;}; 

    //pre initilize the vetor of results
    //could be at most n thus space complexity would be O(n)
    std::vector<int> results(n , 1); 

    /*the idea is to do a greedy algorithm that keeps track of what numbers we have seen so far. for exampl, 4. 2*2 and 8: 2*2*2 however we have already 
     * seen 2*2 in the 4th position of our sequence thus by keeping track of what we have seen so far, we could reduce the time 
     * furthermore, we know that for each iteration, the next number in our sequence is always the smallest number that we have see so far*the our 3 multipliers -> 
     * min( 2*(previous_sequence) , 3*(previous_sequence) , 5*(previous_sequence) ). we first assume that our list only contains the trivial case which is 1
     * our next number in the sequence can be determined from min(2*1, 3*1, 5*1) which would be 2. thus result[i] where i=1 && i->n = 2. now we check to see what
     * which multiplier(2 or 3 or 5) we have taken and we increment its position pointer in our result array respectively. 
     */

    /*pointers that corresponds to which */ 
    unsigned int m_2 = 2;
    unsigned int m_3 = 3;
    unsigned int m_5 = 5; 
    
    /*pointers that corresponds to which */ 
    unsigned int p_2 = 0;
    unsigned int p_3 = 0 ;
    unsigned int p_5 = 0; 


    for(int i = 1; i < n; i++)
    {
        /*take the minimum of the previously generated sequence for each multiplier since we want maintain a gradually increasing order*/ 
        results[i] = std::min(std::min(results[p_2] * m_2 , results[p_3] * m_3)  , results[p_5] * m_5);

        /* check to see if which multiplier we took*/ 
            if( results[i] == results[p_2]*m_2)
             {
                //increment the pointer for the multiplier 
                p_2++;
             }
            if( results[i] == results[p_3]*m_3)
             {
                p_3++;
             }
            if( results[i] == results[p_5]*m_5 )
             {
                p_5++;
             }
    }
    /*the last position in the array will have the result since it is in an increasing order */
    return results.back(); 
}

int main()
{
    unsigned int n = 0;
    std::cout << "enter a positive number n :"; 
    std::cin >> n;
    std::cout << "result : " << multiples(n) << std::endl;

    




}
