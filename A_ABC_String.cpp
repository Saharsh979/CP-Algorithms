#include <bits/stdc++.h>

using namespace std;
bool checkbalanced(string s)
{

    stack<char> s1;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            s1.push('(');
        }
        else
        {
            if (!s1.empty())
            {
                s1.pop();
                continue;
            }
            else
            {
                return false;
            }
        }
    }
    if (s1.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        char a = str[0];
        char b = str[str.length() - 1];
        int check = 0;
        int opening = 0;
        int closing = 0;
        int remaining = 0;
        string newstr = "";
        if (str.length() % 2 != 0)
        {
            cout << "NO" << endl;
            continue;
        }
        if (str[0] == str[str.length() - 1])
        {
            cout << "No" << endl;
        }
        else
        {
            for (int i = 0; i < str.length(); i++)
            {
                if (str[i] == a)
                {
                    opening++;
                }
                else if (str[i] == b)
                {
                    closing++;
                }
                else if (str[i] == 'B')
                {
                    remaining++;
                }
            }
            if (opening > closing)
            {
                check = 1;
            }
            else if (opening < closing)
            {
                check = 2;
            }
            if (check == 0 && remaining > 0)
            {
                cout << "NO" << endl;
                continue;
            }
            else
            {
                for (int i = 0; i < str.length(); i++)
                {
                    if (str[i] == a)
                    {
                        newstr.push_back('(');
                    }
                    else if (str[i] == b)
                    {
                        newstr.push_back(')');
                    }
                    else
                    {
                        if (check == 1)
                        {
                            newstr.push_back(')');
                        }
                        else
                        {
                            newstr.push_back('(');
                        }
                    }
                }
                //cout << newstr << endl;
                bool ans = checkbalanced(newstr);
                if (ans)
                {
                    cout << "YES" << endl;
                }
                else
                {
                    cout << "NO" << endl;
                }
            }
        }
    }

    return 0;
}