#include <iostream>
#include <cmath>

using namespace std;

double sqr(double x)
{
    return x*x;
}

int main()
{
    cout << 5*3 << ' ' << 10 << endl;
    cout << "Hello" << endl;
    cout << sqr(sqr(1.5)) << endl;
    return 0;
}

