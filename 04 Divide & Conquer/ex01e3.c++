#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binary_search_near(int q, vector<int> &v, int start, int stop)
{
    if (start == stop)
    {
        if (start == 0 && q < v[start])
        {
            return -1;
        }
        else if (q >= v[start])
        {
            return v[start];
        }
        else
        {
            return v[start - 1];
        }
    }
    int m = (start + stop) / 2;
    if (q <= v[m])
    {
        return binary_search_near(q, v, start, m);
    }
    else
    {
        return binary_search_near(q, v, m + 1, stop);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < m; i++)
    {
        int q;
        cin >> q;
        cout << binary_search_near(q, v, 0, n - 1) << endl;
    }
}