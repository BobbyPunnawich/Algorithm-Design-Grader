#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    cin >> arr[0];
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        cin >> arr[i];
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[i])
            {
                count++;
            }
        }
    }
    cout << count;
}