#include <fstream>
#include<iostream>
#include <sstream>

using namespace std;

int main()
{
    std::ifstream file( "input.txt" );

    if ( file )
    {
        std::stringstream buffer;

        buffer << file.rdbuf();

        file.close();

        char test;
        for (int t=0; t<1000; t++) {
            buffer >> test;
            if (!(int(test)>=48 && int(test)<=57) || test=='-') {
                if (test!='-') {
                    return -1;
                }
            }
        }
    }
    return 0;
}