// Last updated: 12/8/2025, 11:27:56 PM
// class Solution {
// public:
//     vector<string> topKFrequent(vector<string>& words, int k) {
//         unordered_map<string, int> freq;
//         for (string s: words) {
//             freq[s]++;
//         }

//         auto cmp = [&](const string& s1, const string& s2) {
//             if (freq[s1] == freq[s2]) return s1 < s2;
//             return freq[s1] > freq[s2];
//         };
//         priority_queue<string, vector<string>, decltype(cmp)> pq(cmp);
//         for (const auto& [str, count] : freq) {
//             if (pq.size() < k) {
//                 pq.push(str);
//             } else {
//                 if (count > freq[pq.top()] || (count == freq[pq.top()] && pq.top() > str)) {
//                     pq.pop();
//                     pq.push(str);
//                 }
//             }
//         }
        
//         vector<string> ans;
//         while (!pq.empty()) {
//             ans.push_back(pq.top());
//             pq.pop();
//         }
//         reverse(ans.begin(), ans.end());
//         return ans;
//     }
// };

// class Solution {
// public:
//     vector<string> topKFrequent(vector<string>& words, int k) {
//         unordered_map<string, int> cnt;
//         vector<pair<int, string>> h;
//         vector<string> res;
//         for (string& word : words) {
//             cnt[word]++;
//         }
//         for (auto& p : cnt) {
//             h.push_back({-p.second, p.first});
//         }

//         make_heap(h.begin(), h.end(), greater<pair<int, string>>());
//         for (int i = 0; i < k; i++) {
//             pop_heap(h.begin(), h.end(), greater<pair<int, string>>());
//             res.push_back(h.back().second);
//             h.pop_back();
//         }
//         return res;
//     }
// };

class Solution {
public:
    int k;

    struct TrieNode {
        TrieNode* children[26];
        bool isWord;
        TrieNode() {
            isWord = false;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };

    void addWord(TrieNode& root, const string& word) {
        TrieNode* cur = &root;
        for (int i = 0; i < word.size(); i++) {
            int idx = word[i] - 'a';
            if (cur->children[idx] == nullptr) {
                cur->children[idx] = new TrieNode();
            }
            cur = cur->children[idx];
        }
        cur->isWord = true;
    }

    void getWords(TrieNode& root, const string& prefix, vector<string>& res) {
        if (k == 0) {
            return;
        }    
        if (root.isWord) {
            k--;
            res.push_back(prefix);
        }
        for (int i = 0; i < 26; i++) {
            if (root.children[i] != nullptr) {
                getWords(*root.children[i], prefix + (char)('a' + i), res);
            }
        }
    }

    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = int(words.size());
        this->k = k;

        map<string, int> cnt;
        for (string& word : words) {
            cnt[word]++;
        }
        vector<string> res;
        vector<TrieNode> bucket(n + 1, TrieNode());
        for (auto& p : cnt) {
            addWord(bucket[p.second], p.first);
        }
        for (int i = n; i > 0; i--) {
            getWords(bucket[i], "", res);
        }
        return res;
    }
};