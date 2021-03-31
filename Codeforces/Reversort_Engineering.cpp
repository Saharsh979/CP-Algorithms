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

bool isSorted(vector<int> v1)
{
    for (int i = 0; i < v1.size(); i++)
    {
        if (v1[i] != i + 1)
        {
            return false;
        }
    }
    return true;
}

int rev(int n, vector<int> &v)
{
    int cost = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int min_val = v[i];
        int min_index = i;
        for (int k = i; k < n; k++)
        {
            if (v[k] < min_val)
            {
                min_val = v[k];
                min_index = k;
            }
        }
        cost += (min_index - i + 1);
        reverse(v.begin() + i, v.begin() + min_index + 1);
        if (isSorted(v))
        {
            cost += (n - i - 2);
            break;
        }
    }
    return cost;
}

int main()
{
    int t;
    cin >> t;
    for (int test = 1; test <= t; test++)
    {
        int n, c;
        cin >> n >> c;
        vector<int> vec;
        for (int i = 1; i <= n; i++)
        {
            vec.push_back(i);
        }
        bool flag = false;
        do
        {
            vector<int> v;
            for (int i = 0; i < n; i++)
            {
                v.push_back(vec[i]);
            }
            if (rev(n, v) == c)
            {
                cout << "Case #" << test << ": ";
                for (int i = 0; i < n; i++)
                {
                    cout << vec[i] << " ";
                }
                cout << "\n";
                flag = true;
                break;
            }
        } while (next_permutation(vec.begin(), vec.end()));

        if (flag == false)
        {
            cout << "Case #" << test << ": IMPOSSIBLE" << endl;
        }
    }

    return 0;
}