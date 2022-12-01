
//Namespace are used to avoid name conflicts.

#include <iostream>
#include <cmath>
using namespace std;

namespace raw
{
    void print(double x)
    {
        cout<<"raw: "<<x<<endl;
    }
}
namespace square
{
    namespace inception
    {
        void print(double x)
        {
            cout<<"inception: "<<x<<endl;
        }
    } 
    
    void print(float x)
    {
        cout<<"square: "<<sqrt(x)<<endl;
    }
}

int main()
{
    //I can write using namespace raw;
    //then use it's functions and when i have to use the print fct of square 
    //square::print(number);

    //Autre exeption
    //using namespace raw
    //using namespace square
    //using namespace square::inception;
    //print(number)         
    //ca donne une ambiguite

    // on peut comme typedef changer le nom du namespace
    //example
    //namespace sqr = square;
    //sqr::print(23.3323);
    raw::print(23.222);
    square::inception::print(23.5568);
    square::print(64);
}