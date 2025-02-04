#include <iostream>
#include <vector>

using namespace std;

void consecutive_ones(int n, int k, int len, vector<int> &sol)
{
    if (len < n)
    {
        // gen all combinations
        sol[len] = 0;
        consecutive_ones(n, k, len + 1, sol);
        sol[len] = 1;
        consecutive_ones(n, k, len + 1, sol);
    }
    else
    {
        // filter only consecutive ones k numbers
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (sol[i] == 0)
            {
                count = 0;
            }
            if (sol[i] == 1)
            {
                count++;
            }
            if (count == k)
            {
                for (int j = 0; j < n; j++)
                {
                    cout << sol[j];
                }
                cout << endl;
                break;
            }
        }
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> sol(n);
    consecutive_ones(n, k, 0, sol);
}