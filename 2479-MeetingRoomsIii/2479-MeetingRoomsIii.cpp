// Last updated: 12/8/2025, 11:25:47 PM
// class Solution {
// public:
//     int mostBooked(int n, vector<vector<int>>& meetings) {
//         // if (n >= meetings.size()) return 0;
//         // a map to record the meetings held for each rooms
//         unordered_map<int, int> freq;

//         // a heap for meeting rooms
//         // end time, room number
//         priority_queue<pair<unsigned long long, int>, vector<pair<unsigned long long, int>>, greater<pair<unsigned long long, int>>> pq;
//         pq.push({0, 0});
        
//         // sort the meetings by start time
//         sort(meetings.begin(), meetings.end(), [](const vector<int>& v1, const vector<int>& v2) {
//             return v1[0] < v2[0];
//         });

//         // initialize first n meetings
//         // for (int i = 0; i < meetings.size() && i < n; ++i) {
//         //     pq.push({meetings[i][1], i});
//         //     freq[i]++;
//         // }

//         // arrange the rest meetings
//         for (const auto meeting : meetings) {
//             // see how many rooms can be available before next meeting starts
//             queue<pair<unsigned long long, int>> cache;
//             while (!pq.empty() && pq.top().first <= meeting[0]) {
//                 cache.push({0, pq.top().second});
//                 pq.pop();
//             }

//             // add empty rooms back
//             while (!cache.empty()) {
//                 pq.push(cache.front());
//                 cache.pop();
//             }

//             if (pq.size() < n) {
//                 // if ealiest ending room is after this meeting, assign new room
//                if (pq.top().first > meeting[0]) {
//                     int room = pq.size();
//                     pq.push({meeting[1], room});
//                     freq[room]++;
//                } else {
//                 // if there is available rooms
//                     auto [end, room] = pq.top();
//                     pq.pop();
//                     pq.push({meeting[1], room});
//                     freq[room]++;
//                }

                
//             }
//             else {
//                 // process delay time
//                 auto [end, room] = pq.top();
//                 pq.pop();
//                 if (end <= meeting[0]) {
//                     pq.push({meeting[1], room});
//                 } else {
//                     pq.push({end + meeting[1] - meeting[0], room});
//                 }
//                 freq[room]++;
//             }
//         }

//         int ans = 0;
//         for (int i = 0; i < n; ++i) {
//             if (freq[i] > freq[ans]) {
//                 ans = i;
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> meetingCount(n, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> usedRooms;
        priority_queue<int, vector<int>, greater<int>> unusedRooms;
        for (int i = 0; i < n; i++) {
            unusedRooms.push(i);
        }
        sort(meetings.begin(), meetings.end());

        for (auto meeting : meetings) {
            int start = meeting[0], end = meeting[1];

            while (!usedRooms.empty() && usedRooms.top().first <= start) {
                int room = usedRooms.top().second;
                usedRooms.pop();
                unusedRooms.push(room);
            }
            if (!unusedRooms.empty()) {
                int room = unusedRooms.top();
                unusedRooms.pop();
                usedRooms.push({end, room});
                meetingCount[room]++;
            } else {
                auto [roomAvailabilityTime, room] = usedRooms.top();
                usedRooms.pop();
                usedRooms.push({roomAvailabilityTime + end - start, room});
                meetingCount[room]++;
            }
        }

        int maxMeetingCount = 0, maxMeetingCountRoom = 0;
        for (int i = 0; i < n; i++) {
            if (meetingCount[i] > maxMeetingCount) {
                maxMeetingCount = meetingCount[i];
                maxMeetingCountRoom = i;
            }
        }
        return maxMeetingCountRoom;
    }
};