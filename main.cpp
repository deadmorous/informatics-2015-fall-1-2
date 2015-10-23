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

void fib2_(int k, int& ck, int& ck1)
{
    if (k <= 2)
    {
        ck = k;
        ck1 = k - 1;
    }
    else
    {
        // Вычислить с(k-2) и c(k-1)
        // (это можно сделать, вызвав функцию fib2_)
        // Сумма с(k-2) и c(k-1) - это c(k)
        fib2_(k-1, ck1, ck);
        ck += ck1;
    }
}

int fib2(int k)
{
    int ck, ck1;
    fib2_(k, ck, ck1);
    return ck;
}

int main()
{
//    cout << 5*3 << ' ' << 10 << endl;
//    cout << "Hello" << endl;
//    cout << sqr(sqr(1.5)) << endl;
    QTime t;
    t.start();
    cout << fib(45) << endl;
    cout << "Time elapsed: " << t.elapsed() << " ms" << endl;

    t.restart();
    cout << fib2(45) << endl;
    cout << "Time elapsed: " << t.elapsed() << " ms" << endl;

    return 0;
}
