// Last updated: 12/8/2025, 11:26:12 PM
class Solution {
private:
    vector<int> minCityCount;
    vector<vector<int>> minDist;
    void floyd(int n, int distanceThreshold) {
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    minDist[i][j] = min(minDist[i][j], minDist[i][k] + minDist[k][j]);
                    if (k == n - 1 && minDist[i][j] <= distanceThreshold && i != j) {
                        minCityCount[i]++;
                    }
                }
            }
        }
    }

public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        minCityCount.resize(n, 0);
        minDist.resize(n, vector<int>(n, 10005));
        for (const vector<int>& edge : edges) {
            minDist[edge[0]][edge[1]] = edge[2];
            minDist[edge[1]][edge[0]] = edge[2];
        }

        floyd(n, distanceThreshold);
        
        int city = -1;
        int num = n;
        for (int i = 0; i < n; ++i) {
            if (minCityCount[i] <= num) {
                city = i;
                num = minCityCount[i];
            }
        }
        return city;
    }
};