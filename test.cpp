#include <iostream>

using namespace std;

int SquareSum(int n, int& count_assign, int& count_compare) {
    count_assign = 0;
    count_compare = 0;

    int i = 1; ++count_assign;
    int sum = 0; ++count_assign;

    while(++count_compare && i <= n) {
        sum += i * i; ++count_assign;
        i++; ++count_assign;
    }
    return sum;
}

void f(int n, int& compare, int& assign) {
    
}

int main() {
    int n = 100;

    return 0;
}