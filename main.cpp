#include <iostream>
#include <cmath>

#include <QTime>

using namespace std;

double sqr(double x)
{
    return x*x;
}

int fib(int k)
{
    return k<3 ?   k :   fib(k-1) + fib(k-2);
}

int main()
{
    cout << 5*3 << ' ' << 10 << endl;
    cout << "Hello" << endl;
    cout << sqr(sqr(1.5)) << endl;
    QTime t;
    t.start();
    cout << fib(45) << endl;
    cout << "Time elapsed: " << t.elapsed() << " ms" << endl;
    return 0;
}

