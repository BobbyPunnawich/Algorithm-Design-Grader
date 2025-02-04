#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    int count = 0;
    cin >> N;
    vector<int> v(N);
    cin >> v[0];
    for (int i = 1; i < N; i++)
    {
        cin >> v[i];
        for (int j = 0; j < i; j++)
        {
            if (v[i] < v[j])
            {
                count++;
            }
        }
    }
    cout << count;
}