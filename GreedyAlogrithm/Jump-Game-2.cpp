class Solution {
public:
    int jump(vector<int>& nums) 
    {
        int jumps = 0, right = 0 , left = 0;
        while(right < nums.size()-1)
        {
            int fastest = 0;
            for (int i=left ;i<=right;i++)
            {
                fastest = max(fastest, i + nums[i]);
            }

            jumps += 1;
            left = right + 1;
            right = fastest;
        }
        return jumps;
    }
};