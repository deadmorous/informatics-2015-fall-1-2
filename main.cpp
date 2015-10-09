#include <iostream>
#include <cmath>

using namespace std;

double sqr(double x)
{
    return x*x;
}

int fib(int k)
{
    return k==1? 1: k==2? 2: fib(k-1) + fib(k-2);
}

int main()
{
    cout << 5*3 << ' ' << 10 << endl;
    cout << "Hello" << endl;
    cout << sqr(sqr(1.5)) << endl;
    cout << fib(45) << endl;
    return 0;
}

