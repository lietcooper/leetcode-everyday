// Last updated: 12/8/2025, 11:28:31 PM
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        vector<string>ans(n);
        vector<pair<int,int>>s;

        for(int i=0;i<n;i++){
            s.push_back({score[i],i});
        }

        sort(s.begin(),s.end(),[](auto &a,auto &b){
            return a.first > b.first;
        });

        int i=0;
        for(auto& p: s){
            if(i==0) ans[p.second]=("Gold Medal");
            else if(i==1) ans[p.second]=("Silver Medal");
            else if(i==2) ans[p.second]=("Bronze Medal");
            else ans[p.second]=(to_string(i+1));

            i++;
        }

        return ans;
    }
};