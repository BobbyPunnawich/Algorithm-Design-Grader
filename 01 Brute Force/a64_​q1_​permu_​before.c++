#include <iostream>
#include <vector>
#include <map>

using namespace std;

void permu_before(int n, int m, int len, vector<int> &sol, map<int, int> &before, vector<bool> &used)
{
    if (len < n)
    {
        for (int i = 0; i < n; i++)
        {
            if (!used[i])
            {
                if (before.find(i) == before.end() || used[before[i]])
                {
                    used[i] = true;
                    sol[len] = i;
                    permu_before(n, m, len + 1, sol, before, used);
                    used[i] = false;
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << sol[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    map<int, int> before;
    for (int i = 0; i < m; i++)
    {
        int first, last;
        cin >> first >> last;
        before[last] = first;
    }
    vector<int> sol(n);
    vector<bool> used(n, false);
    permu_before(n, m, 0, sol, before, used);
}