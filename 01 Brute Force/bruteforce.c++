#include <iostream>
#include <vector>

using namespace std;

void abc_permutation(int n, int a, int b, int c, int len, vector<string> &sol, vector<string> &ans)
{
    if (len < n)
    {
        if (a > 0)
        {
            sol[len] = "A";
            abc_permutation(n, a - 1, b, c, len + 1, sol, ans);
        }
        if (b > 0)
        {
            sol[len] = "B";
            abc_permutation(n, a, b - 1, c, len + 1, sol, ans);
        }
        if (c > 0)
        {
            sol[len] = "C";
            abc_permutation(n, a, b, c - 1, len + 1, sol, ans);
        }
    }
    else
    {
        string s = "";
        for (int i = 0; i < n; i++)
        {
            s += sol[i];
        }
        ans.push_back(s);
    }
}

int main()
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<string> sol(n);
    vector<string> ans;
    abc_permutation(n, a, b, c, 0, sol, ans);
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
}