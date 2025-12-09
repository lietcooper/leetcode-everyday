// Last updated: 12/8/2025, 11:28:59 PM
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size()) return false;

        int map[26] = {0};
        
        for (int i = 0; i < ransomNote.length(); i++) {
            map[ransomNote[i] - 'a']++;
        } 

        for (int i = 0; i < magazine.length(); i++) {
            map[magazine[i] - 'a']--;
        }
        
        for (auto& c : ransomNote) {
            if (map[c - 'a'] > 0) return false;
        }
        return true;
    }
};