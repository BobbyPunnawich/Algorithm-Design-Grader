#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool similar_string(string &str1, string &str2, int start1, int stop1, int start2, int stop2)
{
    if (start1 == stop1)
    {
        return str1[start1] == str2[start2];
    }
    int mid1 = (start1 + stop1) / 2;
    int mid2 = (start2 + stop2) / 2;
    return similar_string(str1, str2, start1, mid1, start2, mid2) &&
}

int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    if (similar_string(str1, str2, 0, str1.length() - 1, 0, str2.length() - 1))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}