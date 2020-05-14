class Solution {
public:
    bool isSubsequence(string s, string t) {
        int size_s = s.size();
        int size_t = t.size();
        int i=0;
        int j=0;
        while(i<size_s && j<size_t)
        {
            if(s[i]==t[j])
            {
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        if(i==size_s)
            return true;
        return false;
    }
};