class Solution {
public:
    int stoneGameVI(vector<int>& a, vector<int>& b) {
        int m = a.size();
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < m; ++i) {
            pq.emplace(a[i] + b[i], i);
        }

        bool turn = true;
        int ta = 0, tb = 0;
        while (!pq.empty()) {
            int index = pq.top().second;
            pq.pop();
            
            if (turn) {
                ta += a[index];
            } else {
                tb += b[index];
            }

            turn = !turn;    
        }
        
        if (ta > tb) return 1;
        else if (ta < tb) return -1;
        return 0;
    }
};

//https://leetcode.com/problems/stone-game-vi/