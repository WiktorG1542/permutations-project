#include<iostream>
#include<vector>
#include<cstdlib>
#include<algorithm>
#include<numeric>

using namespace std;

int number_of_inversions(vector<int> scrambled_vec, int n);
//returns the number of inversions in a certain permutation

int how_many_cycles(vector<int> scrambled_vec, int n);
//returns the total number of cycles, as well as writes them out

//int greatest_common_divisor(int a, int b);
//returns the greatest common divisor of two numbers, this is used to calculate the 
//number of times we need to repeat the permutation in order for the result to be the same as the input

void display_vector(vector<int> vector, int size);
//displays vector

int factorial(int n);
//returns factorial = n!

int main() {

    cout << "\\documentclass{article}" << endl << "\\usepackage{graphicx}" << endl;
    cout << "\\usepackage{hyperref}" << endl;
    cout << "\\usepackage{fixltx2e}" << endl;
    cout << "\\usepackage{tabularx}" << endl;
    cout << "\\begin{document}" << endl;
    cout << "\\title{Permutacje}" << endl;
    cout << "\\author{Wiktor Grzywacz}" << endl;
    cout << "\\maketitle" << endl;

    int number_of_chapters;
    cin >> number_of_chapters;

    while (number_of_chapters--) {

        srand((unsigned) time(NULL));
        int number_of_permutations, n;
        //cout << "Podaj liczbę losowych permutacji..." << endl;
        cin >> number_of_permutations;
        //cout << "Podaj wielkość zbioru..." << endl;
        cin >> n;
        cout << endl << endl << endl;

        if (number_of_permutations==-1) {
            cout << "\\section{Wszystkie permutacje dla n="<<n<<"}"<<endl;
        } else {
            cout << "\\section{randomowe permutacje dla n="<<n<<"}"<<endl;
        }

        //a fun statistic, interesting too see how it changes as you manipulate the inputs :3
        int total_number_of_cycles = 0;

        vector<int> spare;
        for (int a=0; a<n; a++) {
            spare.push_back(a+1);
        }
        if (number_of_permutations==-1) {

            do {
                cout << "\\subsection{\\texorpdfstring{$\\sigma$}{} = (";
                display_vector(spare, n);
                cout << ")}" << endl;
                //display_vector(spare, n);
                int how_many_inversions = number_of_inversions(spare, n);
                if (how_many_inversions%2==0) {
                    //even
                    cout << "\\begin{tabularx}{0.8\\textwidth} {" << endl; 
                    cout << "| >{\\raggedright\\arraybackslash}X" << endl; 
                    cout << "| >{\\centering\\arraybackslash}X" << endl;
                    cout << "| >{\\raggedleft\\arraybackslash}X | }" << endl;
                    cout << "\\hline" << endl;
                    cout << "inversions: & " << how_many_inversions << "\\\\" << endl;
                    cout << "\\hline" << endl;
                    cout << "is \\texorpdfstring{$\\sigma$}{} even: & yes \\\\" << endl;
                    cout << "\\hline" << endl;
                    cout << "\\end{tabularx}" << endl;
                } else {
                    cout << "\\begin{tabularx}{0.8\\textwidth} {" << endl; 
                    cout << "| >{\\raggedright\\arraybackslash}X" << endl; 
                    cout << "| >{\\centering\\arraybackslash}X" << endl;
                    cout << "| >{\\raggedleft\\arraybackslash}X | }" << endl;
                    cout << "\\hline" << endl;
                    cout << "inversions: & " << how_many_inversions << "\\\\" << endl;
                    cout << "\\hline" << endl;
                    cout << "is \\texorpdfstring{$\\sigma$}{} even: & no \\\\" << endl;
                    cout << "\\hline" << endl;
                    cout << "\\end{tabularx}" << endl;                    
                }
                //cout << "\\newline" << endl;
                //cout << "\\newline" << endl;
                //cout << "this permutation has " << number_of_inversions(spare, n) << " inversions." <<  endl;
                int number_of_cycles = how_many_cycles(spare, n);
                cout << number_of_cycles << " is the number of cycles in this permutation.""\\newline"<< endl;
                total_number_of_cycles += number_of_cycles;
            } while (next_permutation(spare.begin(), spare.end()));

        }

        for (int current_permutation_number=0; current_permutation_number<number_of_permutations; current_permutation_number++) {

            //cout << "\\section{"<< number_of_permutations << " losowo wygenerowanych permutacji dla n="<<n<<"}"<<endl;

            vector<int> vec;
            vector<int> scrambled_vec;

            for (int a=0; a<n; a++) {
                vec.push_back(a+1);
            }

            while (vec.size()>0) {
                int a = rand()%vec.size();
                scrambled_vec.push_back(vec[a]);
                vec.erase(vec.begin()+a);
            }

            cout << "\\subsection{\\texorpdfstring{$\\sigma$}{} = (";
            display_vector(scrambled_vec, n);
            cout << ")}" << endl;

            //display_vector(scrambled_vec, n);
            int how_many_inversions = number_of_inversions(scrambled_vec, n);
            if (how_many_inversions%2==0) {
                cout << "\\begin{tabularx}{0.8\\textwidth} {" << endl; 
                cout << "| >{\\raggedright\\arraybackslash}X" << endl; 
                cout << "| >{\\centering\\arraybackslash}X" << endl;
                cout << "| >{\\raggedleft\\arraybackslash}X | }" << endl;
                cout << "\\hline" << endl;
                cout << "inversions: & " << how_many_inversions << "\\\\" << endl;
                cout << "\\hline" << endl;
                cout << "is \\texorpdfstring{$\\sigma$}{} even: & yes \\\\" << endl;
                cout << "\\hline" << endl;
                cout << "\\end{tabularx}" << endl;
            } else {
                cout << "\\begin{tabularx}{0.8\\textwidth} {" << endl; 
                cout << "| >{\\raggedright\\arraybackslash}X" << endl; 
                cout << "| >{\\centering\\arraybackslash}X" << endl;
                cout << "| >{\\raggedleft\\arraybackslash}X | }" << endl;
                cout << "\\hline" << endl;
                cout << "inversions: & " << how_many_inversions << "\\\\" << endl;
                cout << "\\hline" << endl;
                cout << "is \\texorpdfstring{$\\sigma$}{} even: & no \\\\" << endl;
                cout << "\\hline" << endl;
                cout << "\\end{tabularx}" << endl;
            }
            //cout << "\\newline" << endl;
            //cout << "\\newline" << endl;
            //cout << endl << "this permutation has " << number_of_inversions(scrambled_vec, n) << " inversions." <<  endl;
            int number_of_cycles = how_many_cycles(scrambled_vec, n);
            cout << number_of_cycles << " is the number of cycles in this permutation." <<"\\newline"<<endl;
            total_number_of_cycles += number_of_cycles;

            cout << endl << endl; 

        }

        //here is that statistic i talked about earlier
        double average_cycles_per_permutation = (total_number_of_cycles*1.0)/(number_of_permutations*1.0);
        if (number_of_permutations==-1) {
            average_cycles_per_permutation = (total_number_of_cycles*1.0)/(factorial(n));
        }
        //cout << " \\newline" << endl;
        cout << "\\begin{center}" << endl;
        cout << "\\end{center}" << endl;
        cout << endl << "Fun fact: the average cycles per permutation for all calculated permutations was: " << average_cycles_per_permutation << endl;
    }

    cout << "\\end{document}" << endl;
    return 0;
}
