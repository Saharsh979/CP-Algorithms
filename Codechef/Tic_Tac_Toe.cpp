#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define fbo find_by_order
#define ook order_of_key
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> Set;
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define sz(a) (int)a.size()
#define pb push_back
#define vmin *min_element
#define vmax *max_element
#define max_pq priority_queue<ll, vector<ll>>
#define min_pq priority_queue<ll, vector<ll>, greater<ll>>
#define all(x) x.begin(), x.end()
#define ub upper_bound
#define lb lower_bound
#define bin binary_search
#define revsort(v) sort(all(v), greater<int>())
#define min(a, b) min((int)a, (int)b)
#define max(a, b) max((int)a, (int)b)
#define min3(a, b, c) min(min(a, b), c)
#define max3(a, b, c) max(max(a, b), c)
#define ll long long int //int64_t
#define endl '\n'
#define uint unsigned long long int // uint64_t
#define ld long double
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define preci(x, y) fixed << setprecision(y) << x
#define mod 1000000007

bool check2(char a[4][4])
{
    if (a[1][1] == 'X' && a[1][2] == 'X' && a[1][3] == 'X')
        return true;
    if (a[2][1] == 'X' && a[2][2] == 'X' && a[2][3] == 'X')
        return true;
    if (a[3][1] == 'X' && a[3][2] == 'X' && a[3][3] == 'X')
        return true;
    if (a[1][1] == 'X' && a[2][1] == 'X' && a[3][1] == 'X')
        return true;
    if (a[1][2] == 'X' && a[2][2] == 'X' && a[3][2] == 'X')
        return true;
    if (a[1][3] == 'X' && a[2][3] == 'X' && a[3][3] == 'X')
        return true;
    if (a[1][1] == 'X' && a[2][2] == 'X' && a[3][3] == 'X')
        return true;
    if (a[1][3] == 'X' && a[2][2] == 'X' && a[3][1] == 'X')
        return true;
    return false;
}
bool check3(char a[4][4])
{
    if (a[1][1] == '0' && a[1][2] == '0' && a[1][3] == '0')
        return true;
    if (a[2][1] == '0' && a[2][2] == '0' && a[2][3] == '0')
        return true;
    if (a[3][1] == '0' && a[3][2] == '0' && a[3][3] == '0')
        return true;
    if (a[1][1] == '0' && a[2][1] == '0' && a[3][1] == '0')
        return true;
    if (a[1][2] == '0' && a[2][2] == '0' && a[3][2] == '0')
        return true;
    if (a[1][3] == '0' && a[2][3] == '0' && a[3][3] == '0')
        return true;
    if (a[1][1] == '0' && a[2][2] == '0' && a[3][3] == '0')
        return true;
    if (a[1][3] == '0' && a[2][2] == '0' && a[3][1] == '0')
        return true;
    return false;
}
char a[4][4];
int d1, d2;
int check(char c)
{
    int x = 0;
    for (int i = 1; i <= 3; i++)
    {
        if (a[i][1] == a[i][2] && a[i][2] == a[i][3] && a[i][1] == c)
        {
            x++;
        }
    }
    for (int i = 1; i <= 3; i++)
    {
        if (a[1][i] == a[2][i] && a[2][i] == a[3][i] && a[1][i] == c)
        {
            x++;
        }
    }
    if (a[1][1] == a[2][2] && a[2][2] == a[3][3] && a[1][1] == c)
    {
        x++;
    }
    if (a[1][3] == a[2][2] && a[2][2] == a[3][1] && a[1][3] == c)
    {
        x++;
    }
    return x;
}

void solve()
{

    d1 = 0;
    d2 = 0;
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            cin >> a[i][j];
            //cout << a[i][j] << " ";
            if (a[i][j] == 'X')
                d1++;
            if (a[i][j] == 'O')
                d2++;
        }
        //cout << endl;
    }
    if (d1 < d2 || d1 > d2 + 1)
    {

        cout << 3 << endl;
        return;
    }
    int w1 = check('X');
    int w2 = check('O');
    //cout << w1 << " " << w2 << " " << d1 << " " << d2 << endl;
    if ((w1 && w2) || (w1 > 2 || w2 > 2) || (w1 && d1 == d2) || (w2 && (d1 > d2)))
    {
        cout << 3 << endl;
        return;
    }
    if ((w1) || (w2) || (d1 + d2 == 9))
    {
        cout << 1 << endl;
        return;
    }
    cout << 2 << endl;
    return;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}