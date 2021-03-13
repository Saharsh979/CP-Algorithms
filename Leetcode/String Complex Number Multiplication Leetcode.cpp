class Solution
{
public:
    int real(string str)
    {
        int i = 0;
        string result = "";
        while (str[i] != '+')
        {
            result.push_back(str[i]);
            i++;
        }
        return stoi(result);
    }

    int complex(string str)
    {
        int i = 0;
        string complex = "";
        while (str[i] != '+')
        {
            i++;
        }
        i++;
        while (str[i] != 'i')
        {
            complex.push_back(str[i]);
            i++;
        }
        return stoi(complex);
    }
    string complexNumberMultiply(string a, string b)
    {

        string res = "";
        int a1, a2, b1, b2;
        a1 = real(a);
        a2 = real(b);
        b1 = complex(a);
        b2 = complex(b);
        res = res + to_string(a1 * a2 - b1 * b2) + '+' + to_string(a1 * b2 + a2 * b1) + 'i';

        return res;
    }
};

//https://leetcode.com/problems/complex-number-multiplication/