// https://leetcode.com/problems/long-pressed-name/description/
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int n = name.size(), m = typed.size();

        int l = 0;
        char L = name[0];
        int lCount = 0;

        int r = 0;
        char R = typed[0];
        int rCount = 0;

        while (l < n && r < m) {
            while (l < n && name[l] == L)
                lCount++, l++;
            while (r < m && typed[r] == R)
                rCount++, r++;
            if (L != R)
                return false;
            if (lCount > rCount)
                return false;
            lCount = 0, rCount = 0;
            if (l < n)
                L = name[l];
            if (r < m)
                R = typed[r];
        }
        if (l < n || r < m) {
            return false;
        }
        return true;
    }
};
