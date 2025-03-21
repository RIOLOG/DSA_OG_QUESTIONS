class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        //BRUTE FORCE:
        // int n = nums.size();
        // for (int i=0;i<nums.size();i++)
        // {
        //     int count = 0;
        //     int num = nums[i];
        //     for (int j=0;j<nums.size();j++)
        //     {
        //         if (nums[j] == num)   count += 1;
        //     }
        //     if (count > n / 2)   return num;
        // }
        // return -1;
        
        
        
        //USING HASHMAP:
        // int n = nums.size();
        // unordered_map<int,int>mp;
        // for (auto x: nums)
        // {
        //     mp[x]++;
        //     if (mp[x] > n/2)   return x;
        // }
        // return 0;
        
        
        
        
        //Sorting:
//         sort(nums.begin(),nums.end());
//         int n = nums.size();
//         return nums[n/2];
        
        
        
        
        
        //MOORE VOOTING:
        int ans = 0, count = 1;
        
        for (int i=1;i<nums.size();i++)
        {
            if (nums[i] == nums[ans])    count += 1;
            else if (count == 0)
            {
                count = 1;
                ans = i;
            }
            else    count -=1 ;
        }
        
        return nums[ans];
    }
};