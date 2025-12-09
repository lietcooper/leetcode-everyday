// Last updated: 12/8/2025, 11:28:09 PM
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](const vector<int>& v1, const vector<int>& v2) {
            return v1[1] < v2[1];
        });
        
        priority_queue<int> pq;
        int time = 0;
        for (auto& c : courses) {
            if (c[0] > c[1]) continue;
            if (time + c[0] <= c[1]) {
                pq.push(c[0]);
                time += c[0];
            } else if (!pq.empty() && pq.top() > c[0]) {
                time += c[0] - pq.top();
                pq.pop();
                pq.push(c[0]);
            }
        }
        return pq.size();
    }
};