// Last updated: 12/8/2025, 11:28:46 PM
class Solution {
public:
    string frequencySort(string s) {
        map<char,int> freq;
        string rets ="";
        for(auto it: s)
        {
            freq[it]++;
        }
        vector<pair<char,int>> str(freq.begin(), freq.end());
        sort(str.begin(), str.end(),[](auto &a, auto &b)
        {
            return a.second>b.second;
        });
        for(auto &p : str)
        {
            rets.append(p.second, p.first);
        }
        return rets;
    }
};