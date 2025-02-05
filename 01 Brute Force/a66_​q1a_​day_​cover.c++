#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    int days, students;
    cin >> days >> students;
    int minStudents = 0;
    vector<pair<int, vector<int>>> v;
    map<int, int> m;
    for (int i = 0; i < students; i++)
    {
        int k;
        cin >> k;
        vector<int> arr(k);
        for (int j = 0; j < k; j++)
        {
            cin >> arr[j];
        }
        v.push_back({k, arr});
    }
    sort(v.rbegin(), v.rend());
    for (int i = 0; i < v.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < v[i].first; j++)
        {
            if (count == 0 && m.find(v[i].second[j]) == m.end())
            {
                minStudents++;
                count++;
            }
            m[v[i].second[j]]++;
        }
    }
    cout << minStudents;
}