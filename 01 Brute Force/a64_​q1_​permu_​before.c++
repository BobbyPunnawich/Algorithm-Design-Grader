#include <iostream>
#include <vector>
#include <map>

using namespace std;

void permutation_before(int n, int m, vector<int> &sol, vector<bool> &used, int len, map<int, int> &order)
{
    if (len < n)
    {
        for (int i = 0; i < n; i++)
        {
            if (!used[i])
            {
                if (order.find(i) == order.end() || used[order[i]])
                {
                    used[i] = true;
                    sol[len] = i;
                    permutation_before(n, m, sol, used, len + 1, order);
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
    map<int, int> order;
    vector<bool> used(n, false);
    vector<int> sol(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        order[b] = a;
    }
    permutation_before(n, m, sol, used, 0, order);
}