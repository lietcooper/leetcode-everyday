// Last updated: 12/8/2025, 11:26:24 PM
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (int n : stones) pq.push(n);
        while (pq.size() > 1) {
            int s1 = pq.top(); pq.pop();
            int s2 = pq.top(); pq.pop();
            int s3 = abs(s1 - s2);
            if (s3 > 0) pq.push(s3);
        }
        
        if (pq.size() > 0) {
            return pq.top();
        } else {
            return 0;
        }
    }
};