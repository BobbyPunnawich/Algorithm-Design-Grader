#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int blockNumber, towerNumber, monsterNumber, range;
    cin >> blockNumber >> monsterNumber >> towerNumber >> range;
    vector<int> towerPosition(towerNumber);
    vector<int> monsterPosition(monsterNumber);
    vector<int> monsterHealth(monsterNumber);
    for (int i = 0; i < monsterNumber; i++)
    {
        cin >> monsterPosition[i];
    }
    for (int i = 0; i < monsterNumber; i++)
    {
        cin >> monsterHealth[i];
    }
    for (int i = 0; i < towerNumber; i++)
    {
        cin >> towerPosition[i];
    }
    int damage = 0;
    for (int i = 0; i < towerNumber; i++)
    {
        for (int j = 0; j < monsterNumber; j++)
        {
            if (monsterHealth[j] != 0 && towerPosition[i] - range <= monsterPosition[j] && monsterPosition[j] <= towerPosition[i] + range)
            {
                monsterHealth[j]--;
                break;
            }
        }
    }
    for (int i = 0; i < monsterNumber; i++)
    {
        damage += monsterHealth[i];
    }
    cout << damage;
}