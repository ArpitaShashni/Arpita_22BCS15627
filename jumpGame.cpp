class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int x=nums[0];
        for(int i=0;i<n;i++){
            if(i>x){
                return false;
            }
            x=max(x,nums[i]+i);
        }
        return true;
    }
};