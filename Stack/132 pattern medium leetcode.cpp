class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        int dp[n + 1];
        int vis[n + 1];
        memset(vis, 0, sizeof(vis));
        bool win = false;
        bool flag = false;
        if (nums[0] == 0 && nums.size() == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
        vis[nums[0]] = 1;
        for (int i = 0; i < nums.size(); i++)
        {

            if (nums[i] == 0)
            {
                continue;
            }
            else
            {
                if (vis[i] == 1)
                {
                    int x = nums[i];
                    int j = i + 1;
                    while (x--)
                    {
                        vis[j] = 1;
                        if (j < n - 1)
                        {
                            j++;
                            continue;
                        }
                        else
                        {
                            if (x > 0)
                            {
                                win = true;
                                flag = true;
                                break;
                            }
                            else
                            {
                                flag = true;
                                break;
                            }
                        }
                    }
                    if (flag == false)
                    {
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }

        if (win || (vis[n - 1] && nums[n - 1] > 0))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};