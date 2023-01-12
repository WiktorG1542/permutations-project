#include<iostream>
#include<vector>
#include<cstdlib>
#include<algorithm>

using namespace std;

void display_vector(vector<int> vector, int size) {

    for (int a=0; a<size-1; a++) {
        cout << vector[a] << ", ";
    }
    cout << vector[size-1];

    return;

}
