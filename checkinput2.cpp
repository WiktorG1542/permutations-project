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

        int first;
        buffer >> first;
        if (first<=0 || first>9) {
            return -1;
        }

        int v1, v2;

        for (int a=0; a<first; a++) {

            buffer >> v1 >> v2;
            
            if (v1==-1 && !(v2>0 && v2<6)) {
                return -1;
            }

            if (v1<=0 && v1!=-1) {
                return -1;
            }

            if (v1!=-1 && (!(v1>0 && v1<100) || !(v2>0 && v2<100))) {
                return -1;
            }

        }

    }
    return 0;
}
