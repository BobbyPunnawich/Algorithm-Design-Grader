#include <iostream>
#include <vector>

using namespace std;

bool triple_sum(int n, vector<int> &arr, int q)
{

    for (int i = 0; i < n; i++)
    {
        int left = 0;
        int right = n - 1;
        while (left < right)
        {
            int sum = arr[i] + arr[left] + arr[right];
            if (sum == q)
            {
                return true;
            }
            else if (sum < q)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < m; i++)
    {
        int q;
        cin >> q;
        if (triple_sum(n, arr, q))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}