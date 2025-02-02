class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m;
        int ans=0,left=0;
        for(int i=0;i<s.length();i++){
            char c=s[i];
            if(m.count(c) && m[c]>=left){
                left=m[c]+1;
            }
            m[c]=i;
            ans=max(ans,i-left+1);
        }
        return ans;
    }
};