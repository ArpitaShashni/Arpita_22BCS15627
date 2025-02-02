class Solution {
public:
    bool isal(char &c){
        if(c>='0' && c<='9'){
            return true;
        }
        if(c>='A' && c<='Z'){
            c=c-'A'+'a';
            return true;
        }
        if(c>='a' && c<='z'){
            return true;
        }
        return false;
    }
    bool isPalindrome(string s) {
        if(s==""){
            return true;
        }
        int n = s.length();
        int i = 0;
        int j = n;
        while(i<n && j>=0)
        {
            if (isal(s[i]) == 0)
            {
                i++;
            }
            else if (isal(s[j]) == 0)
            {
                j--;
            }
            else if (s[i] == s[j])
            {
                ++i; 
                j--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};