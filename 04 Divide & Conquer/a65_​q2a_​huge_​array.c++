#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int huge_array(int q, vector<pair<int, int>> &v, int start, int stop)
{
    if (start == stop)
    {
        return v[start].first;
    }
    int m = (start + stop) >> 1;
    if (q <= v[m].second)
    {
        return huge_array(q, v, start, m);
    }
    else
    {
        return huge_array(q, v, m + 1, stop);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int N, Q;
    cin >> N >> Q;
    vector<pair<int, int>> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    for (int i = i; i < N; i++)
    {
        v[i].second += v[i - 1].second;
    }
    for (int i = 0; i < Q; i++)
    {
        int q;
        cin >> q;
        // ใช้ q ได้เลย เพราะ .second คือจำนวน ไม่ใช่ ตำแหน่ง
        cout << huge_array(q, v, 0, N - 1) << endl;
    }
}

// 4 4 4 4 4 7 7 7 7 7 7 7 8 8 8 9 9 9 9