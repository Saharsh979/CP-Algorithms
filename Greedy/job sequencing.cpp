#include <bits/stdc++.h>
using namespace std;
struct job
{
    int id;
    int deadline;
    int profit;
};

bool comparejob(struct job j1, struct job j2)
{
    if (j1.profit > j2.profit)
    {
        return true;
    }
    return false;
}

int jobsequencing(int id[], in t deadline[], int profit[], int n)
{

    struct job j1;

    for (int i = 0; i < n; i++)
    {
        j1.id = id[i];
        j1.deadline = deadline[i];
        j1.profit = profit[i];
    }
    sort(j1, j1 + n, comparejob);

    int maxdead = 0;

    for (int i = 1; i < n; i++)
    {
        maxdead = max(maxdead, j1[i].deadline);
    }

    int slot[maxdead + 1];

    for (int i = 0; i < n; i++)
    {
        slot[i] = -1;
    }

    int count = 0;
    int profit = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = j1[i].deadline; j > 0; j--)
        {
            if (slot[j] == -1)
            {
                slot[j] = 1;
                count++;
                profit += j1[i].profit;
                break;
            }
        }
    }
    return make_pair(count, profit);
}