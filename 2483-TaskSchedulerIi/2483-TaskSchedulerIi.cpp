// Last updated: 12/8/2025, 11:25:46 PM
// class Solution {
// public:
//     long long taskSchedulerII(vector<int>& tasks, int space) {
//         unordered_map<int, long long> nextDay;
//         long long days = 0;
//         for (int i = 0; i < tasks.size(); ++i) {
//             if (days < nextDay[tasks[i]]) {
//                 days += nextDay[tasks[i]] - days;
//             }
//             days++;
//             nextDay[tasks[i]] = days + space;
//         }
//         return days;
//     }
// };

class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {

        unordered_map<int, int> mp; // element - index
        int n = tasks.size();
        long long day = 0;

        for (int i = 0; i < n; i++) {

            auto it = mp.find(tasks[i]);

            if (it == mp.end()) {
                // Do it
                mp[tasks[i]] = day++;
            } else {

                int wait = space - day + it->second + 1;
                if(wait > 0){
                    day += wait;
                }

                it->second = day++;
            }
        }

        return day;
    }
};