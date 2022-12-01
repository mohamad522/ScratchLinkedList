#include <iostream>
using namespace std;
 
class Printer
{
    //les elements de la classe sont privee by default
    string name;
    int nbrpaper;
    public:
    Printer(string name, int nbr)
    {
        name=name;
        nbrpaper=nbr;
    }
    void print(string txt)
    {
        int nbrequis= txt.length()/4;
        if (nbrequis>nbrpaper)
            //throw "No enough paper";//no enough paper is a string so type=char const*
            throw 404;
        cout<<"Printing..."<<txt<<endl;
        nbrpaper-=nbrequis;//no enough paper is an int so type=int
    }

};

int main()
{
    Printer pri("Hadi's",40);
    //pour recevoir l'exception on met le code a tester dans un try catch block
    try  
    {
        pri.print("Hello World, Hello World, Hello World, Hello World");
        pri.print("Hello World, Hello World, Hello World, Hello World, Hello World, Hello World");
        pri.print("Hello World, Hello World, Hello World, Hello World, Hello World, Hello World");
    }
    //  then if you catch an exception of type "type" return the valeur de ce type
    catch(const char * txtx)
    {
        cout<< "Exception: "<<txtx<<endl;
    }
    catch(int ex)
    {
        cout<< "Exception: "<<ex<<endl;
    }
    // a default exception catcher No matter what the throwed type is.
    catch (...)
    {
       cout<<"Exception Happened!";
    }

    // the program will execute the catchers up -> Down and throw the error according to the type
    //if type not found it will throw the default catcher
    cout<<"FUCKKK!!"; //the code will be executed
    
}