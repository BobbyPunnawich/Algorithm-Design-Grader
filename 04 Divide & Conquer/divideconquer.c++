#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int is_virus(vector<int> &dna, int start, int stop)
{
    if (stop - start == 1)
    {
        return dna[start] + dna[stop];
    }
    int mid = (start + stop) / 2;
    int left = is_virus(dna, start, mid);
    int right = is_virus(dna, mid + 1, stop);
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
    int len = pow(2, k);
    vector<int> dna(len);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < len; j++)
        {
            cin >> dna[j];
        }
        if (is_virus(dna, 0, len - 1) == -1)
        {
            cout << "no" << endl;
        }
        else
        {
            cout << "yes" << endl;
        }
    }
}