// Assignment DAA LAB
// Question 4
// Saharsh Ananta Jaiswal
// 18CS8061

// ------------------ Interval Scheduling ----------------------

/*
e can solve this problem using the greedy Algorithm.
First lets look at hat greedy algorithm is:-
Greedy is an algorithmic paradigm that builds up a solution piece by piece, always choosing the next piece that offers the most obvious and immediate benefit. Greedy algorithms are used for optimization problems. An optimization problem can be solved using Greedy if the problem has the following property: At every step, we can make a choice that looks best at the moment, and we get the optimal solution of the complete problem. 


The greedy choice is to always pick the next activity whose finish time is least among the remaining activities and the start time is more than or equal to the finish time of previously selected activity. We can sort the activities according to their finishing time so that we always consider the next activity as minimum finishing time activity.

*/

// -------------------CODE --------------------

#include <bits/stdc++.h>
using namespace std;

void maxlectures(int s[], int f[], int n)
{
    int i, j;
    i = 0;
    cout << " " << i;
    for (j = 1; j < n; j++)
    {
        if (s[j] >= f[i])
        {
            cout << " " << j;
            i = j;
        }
    }
}
int main()
{
    int start[] = {1, 3, 0, 5, 8, 5};
    int finish[] = {2, 4, 6, 7, 9, 9};
    int n = sizeof(start) / sizeof(start[0]);
    maxlectures(start, finish, n);
    return 0;
}