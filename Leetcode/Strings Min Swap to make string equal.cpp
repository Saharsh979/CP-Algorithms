class Solution
{
public:
    int minimumSwap(string s1, string s2)
    {
        int countx = 0;
        int county = 0;
        int count = 0;

        for (int i = 0; i < s1.length(); i++)
        {
            if (s1[i] == 'x')
            {
                countx++;
            }
            if (s1[i] == 'y')
            {
                county++;
            }
            if (s2[i] == 'x')
            {
                countx++;
            }
            if(s2[i]=='y'){
                county++;
            }
        }
        cout<<countx<<" "<<county<<endl;
        if (countx % 2 != 0 && county % 2 != 0)
        {
            return -1;
        }
        else
        {
            int i = 0;
            while (i < s1.length())
            {
                if (s1[i] == s2[i])
                {
                    i++;
                }
                else
                {
                    bool flag1 = false;
                    bool flag2 = false;
                    int j = i + 1;
                    while (j < s1.length())
                    {
                        if (s1[j] == s1[i] && s2[j] == s2[i] && s1[j] != s2[j])
                        {
                            swap(s1[i], s2[j]);
                            count++;
                            flag1 = true;
                            break;
                        }
                        else
                        {
                            j++;
                        }
                    }
                    if (!flag1)
                    {
                        j = i + 1;
                        while (j < s1.length())
                        {
                            if (s1[j] != s2[j])
                            {
                                swap(s1[i], s2[i]);
                                swap(s1[i], s2[j]);
                                count += 2;
                                flag2 = true;
                                break;
                            }
                            else
                            {
                                j++;
                            }
                        }
                    }
                    i++;
                }
            }
        }
        return count;
    }
};

//https://leetcode.com/problems/minimum-swaps-to-make-strings-equal/