#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int binary_search(vector<int> &v, int k, int start, int stop)
{
    // Trivial Case
    if (start == stop)
    {
        if (start == 0 && v[start] != k)
        {
            return -1;
        }
        else if (k >= v[start])
        {
            return v[start];
        }
        else
        {
            return v[start - 1];
        }
    }
    else
    {
        // middle
        int m = (start + stop) >> 1;
        // left
        if (v[m] >= k)
        {
            return binary_search(v, k, start, m);
        }
        // right
        else
        {
            return binary_search(v, k, m + 1, stop);
        }
    }
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < M; i++)
    {
        int k;
        cin >> k;
        cout << binary_search(v, k, 0, N - 1) << endl;
    }
}