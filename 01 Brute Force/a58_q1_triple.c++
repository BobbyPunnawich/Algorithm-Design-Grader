#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string triple_sum(int q, vector<int> &v, int N)
{
    for (int i = 0; i < N; i++)
    {
        int left = 0;
        int right = N - 1;
        while (left < right)
        {
            int sum = v[i] + v[left] + v[right];
            if (sum == q)
            {
                return "YES";
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
    return "NO";
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < M; i++)
    {
        int q;
        cin >> q;
        cout << triple_sum(q, v, N) << endl;
    }
}