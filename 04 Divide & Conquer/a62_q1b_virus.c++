#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> reverse(const vector<int> &sample, int start, int stop)
{
    vector<int> reversed;
    for (int i = stop; i >= start; i--)
    {
        reversed.push_back(sample[i]);
    }
    return reversed;
}

bool is_virus(const vector<int> &sample, int start, int stop)
{
    if (stop - start == 1)
    {
        return sample[start] == 0 && sample[stop] == 1;
    }
    int mid = (start + stop) / 2;
    bool right_is_virus = is_virus(sample, mid + 1, stop);
    vector<int> reversed = reverse(sample, start, mid);
    bool left_is_virus = is_virus(sample, start, mid) || is_virus(reversed, 0, reversed.size() - 1);
    return left_is_virus && right_is_virus;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int length = pow(2, k);
    vector<int> sample(length);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < length; j++)
        {
            cin >> sample[j];
        }
        if (is_virus(sample, 0, length - 1))
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }
}