#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int mod_expo(int X, int N, int K)
{
    if (N == 1)
    {
        return X % K;
    }
    if (N % 2 == 0)
    {
        // even case
        int tmp = mod_expo(X, N / 2, K);
        return (tmp * tmp) % K;
    }

    else
    {
        // odd case
        int tmp = mod_expo(X, N / 2, K);
        tmp = (tmp * tmp) % K;
        return (tmp * (X % K)) % K;
    }
}

int main()
{
    int X, N, K;
    cin >> X >> N >> K;
    cout << mod_expo(X, N, K);
}