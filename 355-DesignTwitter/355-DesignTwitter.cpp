// Last updated: 12/8/2025, 11:29:09 PM
class Twitter {
private:
    int timeStamp;
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, list<pair<int, int>>> posts;
public:
    Twitter() {
        timeStamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        posts[userId].emplace_front(timeStamp++, tweetId);
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;
        // get posts from the user itself
        auto it = posts[userId].begin();
        for (int i = 0; i < 10 && i < posts[userId].size(); ++i) {
            pq.emplace(*it);
            it++;
        } 

        // get posts from followees
        for (int followee : following[userId]) {
            auto it = posts[followee].begin();
            for (int i = 0; i < 10 && i < posts[followee].size(); ++i) {
                pq.emplace(*it);
                it++;
            }
        }

        vector<int> res;
        for (int i = 0; i < 10 && !pq.empty(); ++i) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */