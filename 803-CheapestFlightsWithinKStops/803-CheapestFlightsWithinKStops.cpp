// Last updated: 12/8/2025, 11:27:06 PM
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> grid(n);
        for (const vector<int>& flight : flights) 
            grid[flight[0]].push_back({flight[1], flight[2]});

        vector<int> minDist(n, INT_MAX);
        minDist[src] = 0;
        queue<int> q;
        vector<bool> inQ(n, false);
        q.push(src);
        inQ[src] = true;
        int stop = 0;
        while (!q.empty() && stop <= k) {
            int sz = q.size();
            vector<int> copy(minDist);
            while (sz--) {
                int cur = q.front();
                q.pop();
                inQ[cur] = false;
                for (auto& [nei, cost] : grid[cur]) {
                    if (minDist[nei] > copy[cur] + cost) {
                        minDist[nei] = copy[cur] + cost;
                        q.push(nei);
                        // if (!inQ[nei])
                        //     q.push(nei);
                        //     inQ[nei] = true;
                    }
                }
            }
            stop++;
        }
        return minDist[dst] == INT_MAX ? -1 : minDist[dst];
    }
};