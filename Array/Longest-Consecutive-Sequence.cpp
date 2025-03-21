Approach - 1: O(N log N).
class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        if (nums.size() == 0)   return 0;
        
        int ans = 1, count = 1;
        map<int, int>mp;
        sort(nums.begin(), nums.end());
        
        for (auto x: nums)   mp[x] += 1;
        
        int currElement = nums[0];
        for (int i=1;i<nums.size();i++)
        {
            if (mp.find(currElement + 1) != mp.end())
            {
                count += 1;
                ans = max(ans, count);
                currElement = currElement + 1;
            }
            else
            {
                count = 1;
                ans = max(ans, count);
                currElement = nums[i];
            }
        }
        
        return ans;
    }
};



Approach 2: 