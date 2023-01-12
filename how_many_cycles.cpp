#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<numeric>

using namespace std;

//int greatest_common_divisor(int a, int b);

int how_many_cycles(vector<int> scrambled_vec, int n) {

    int how_many_cycles = 0;
    vector<bool> was_i_there(n, 0);

    int how_many_repeat = 1;
    //the number of times the permutation needs to be repeated to return the original order.
    //its the lowest common multiple of the lengths of all cycles, which is why we will 
    //calculate it using the greatest_common_divisor() function, since
    //LCM(a, b) = (a*b)/(GCD(a, b))

    /*
    
    \begin{center}
    \end{center}
    \begin{tabularx}{0.8\textwidth} { 
    | >{\raggedright\arraybackslash}X 
    | >{\centering\arraybackslash}X 
    | >{\raggedleft\arraybackslash}X | }
    \hline
    cycle & length \\
    \hline
    1 2 3 4 & 4 \\
    \hline
    5 6 7 & 3 \\
    \hline
    \end{tabularx}

    */


    cout << "\\begin{center}" << endl;
    cout << "\\end{center}" << endl;
    cout << "\\begin{tabularx}{0.8\\textwidth} {" << endl; 
    cout << "| >{\\raggedright\\arraybackslash}X" << endl; 
    cout << "| >{\\centering\\arraybackslash}X" << endl; 
    cout << "| >{\\raggedleft\\arraybackslash}X | }" << endl;
    cout << "\\hline" << endl;
    cout << "cycle & length \\\\" << endl;

    for (int a=0; a<n; a++) {
        if (was_i_there[a]==0) {

            int helper = a;
            //helper is the variable which cycles through the scrambled vector
            was_i_there[a]=1;
            //the boolean vector was_i_there[] is to prevent the program from typing out the same cycle multiple times
            int length = 1;

            cout << "\\hline" << endl;

            cout << helper+1 << " ";

            helper = scrambled_vec[a];
            helper--;

            cout << helper+1 << " ";

            while (helper!=a) {
                was_i_there[helper] = 1;
                helper = scrambled_vec[helper];
                helper--;
                cout << helper+1 << " ";
                length++;
            }

            cout << "& " << length << "\\\\" << endl;

            how_many_repeat = (how_many_repeat*length)/(gcd(how_many_repeat, length));

            how_many_cycles++;

        }
    }


    cout << "\\hline" << endl;
    cout << "\\end{tabularx}" << endl;
    cout << "\\begin{center}" << endl;
    cout << "\\end{center}" << endl;
    cout <<"This permutation needs to be repeated " << how_many_repeat << " times to return to the original order." <<"\\newline"<<endl;

    return how_many_cycles;

}
