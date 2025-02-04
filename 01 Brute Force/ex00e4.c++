#include <iostream>
#include <vector>

using namespace std;

void gen_barcode(int n, int ones, int zeroes, int len, vector<int> &sol)
{
    if (len < n)
    {
        if (zeroes > 0)
        {
            sol[len] = 0;
            gen_barcode(n, ones, zeroes - 1, len + 1, sol);
        }
        if (ones > 0)
        {
            sol[len] = 1;
            gen_barcode(n, ones - 1, zeroes, len + 1, sol);
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << sol[i];
        }
        cout << endl;
    }
}

int main()
{
    int ones, zeroes, n;
    cin >> ones >> n;
    zeroes = n - ones;
    vector<int> sol(n);
    gen_barcode(n, ones, zeroes, 0, sol);
}