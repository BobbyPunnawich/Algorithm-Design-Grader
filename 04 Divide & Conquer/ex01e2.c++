#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int get_sum(vector<int> &S, int a, int b)
{
    return S[b] - S[a - 1];
}

int max_sum(int n, vector<int> &A, vector<int> &S, int start, int stop)
{
    // Trivial Case
    if (start == stop)
    {
        return A[start];
    }
    // Fint Middle Point (Divide)
    int m = (start + stop) / 2;

    // Find Max Left
    int max_left = max_sum(n, A, S, start, m);
    // Find Max Right
    int max_right = max_sum(n, A, S, m + 1, stop);
    // Find Max btw Max Left/Right
    int max_both = max(max_left, max_right);

    // Find Max Cross Left
    int max_cross_left = get_sum(S, m, m);
    for (int i = 0; i < m; i++)
    {
        max_cross_left = max(max_cross_left, get_sum(S, i, m));
    }

    // Find Max Cross Right
    int max_cross_right = get_sum(S, m + 1, m + 1);
    for (int i = m + 2; i <= stop; i++)
    {
        max_cross_right = max(max_cross_right, get_sum(S, m + 1, i));
    }
    int max_cross = max_cross_left + max_cross_right;

    return max(max_cross, max_both);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> S(N);
    cin >> A[0];
    S[0] = A[0];
    for (int i = 1; i < N; i++)
    {
        cin >> A[i];
        S[i] = S[i - 1] + A[i];
    }
    cout << max_sum(N, A, S, 0, N - 1);
}