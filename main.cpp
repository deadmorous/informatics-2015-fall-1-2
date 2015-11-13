#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    const int N = 10;
    int x[N] = {6, 3, 6, 8, 22, -7, 11, 9, 77, 3};
    // int x[N] = {6, 3, -7, 9, 3, 6, 8, 11, 22, 77};

    for (int i=0; i<N; i++)
        cout << x[i] << endl;

    cout << "=====" << endl;


    for (int ilast=N-1; ilast>1; ilast--)
        {
        int imax = 0;
        for (int i=1; i<=ilast; i++)
            if (x[i] > x[imax])
                imax = i;
        swap(x[imax], x[ilast]);
        }

//    cout << "Maximum element " << x[imax] << " found at index " << imax << endl;
    cout << "=====" << endl;
    for (int i=0; i<N; i++)
        cout << x[i] << endl;
}
