#include<iostream>
#include<vector>
#include<cstdlib>

using namespace std;

int number_of_inversions(vector<int> scrambled_vec, int n) {

    //returns the number of inversions in a certain permutation

    int how_many_inversions = 0;

    for (int a=0; a<n; a++) {
        for (int b=0; b<n; b++) {
            if (b>a && scrambled_vec[b]<scrambled_vec[a]) {
                how_many_inversions++;
            }
        }
    }

    return how_many_inversions;
}
