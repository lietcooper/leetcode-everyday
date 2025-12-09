// Last updated: 12/8/2025, 11:26:46 PM
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // two pairs recording the fruit and its last position: pair<fruit, last_pos>
        pair<int, int> a(fruits[0], 0);
        pair<int, int> b(fruits[0], 0);

        int num = 1;
        // initialize two pairs
        int start= 0, end = 0;
        for (end; end < fruits.size(); end++) {
            if (fruits[end] != b.first) {
                a.second = end - 1;
                b.first = fruits[end];
                b.second = end;
                num = end - start + 1;
                break;
            }
        }
        // edge case: if all fruit is the same type: return the length
        if (end == fruits.size()) return fruits.size();

        // for the window < fruits.length();
        for (end; end < fruits.size(); end++) {
            int next = fruits[end];
            // if next fruit is a or b, update and cur_num++
            if (next == a.first || next == b.first) {
                // if next is a, update its last position
                if (next == a.first) {
                    a.second = end;
                }

                // if next is b, update its last position
                if (next == b.first) {
                    b.second = end;
                }
            } else {
                //decide which pair to update with new value
                pair<int, int>& c = a.second < b.second ? a : b;
                // set the start of the window to the leftmost position
                start = c.second + 1;
                // update the pair
                c = pair<int, int>(fruits[end], end);
                
            }
            
            int cur_num = end - start + 1;

            // if cur_num > num, update num
            if (cur_num > num) {
                num = cur_num;
            }
        }
        return num;
    }
};