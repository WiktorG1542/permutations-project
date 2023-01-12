#include<iostream>

using namespace std;

int factorial(int n) {
    int value=1;
    for (int a=1; a<=n; a++) {
        value *= a;
    }
    return value;
}