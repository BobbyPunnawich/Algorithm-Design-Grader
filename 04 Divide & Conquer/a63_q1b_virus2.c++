#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int is_virus(vector<int> v, int start, int stop)
{
    if (stop - start == 1)
    {
        return v[start] + v[stop];
    }
    int mid = (start + stop) >> 1;
    int left = is_virus(v, start, mid);
    int right = is_virus(v, mid + 1, stop);
    if (right == -1 || left == -1)
    {
        return -1;
    }
    if (abs(right - left) > 1)
    {
        return -1;
    }
    return left + right;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int length = pow(2, k);
    vector<int> v(length);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < length; j++)
        {
            cin >> v[j];
        }
        if (is_virus(v, 0, length - 1) == -1)
        {
            cout << "no" << endl;
        }
        else
        {
            cout << "yes" << endl;
        }
    }
}