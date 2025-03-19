class Solution {
public:
    int trap(vector<int>& nums) 
    {
        //Brute Force --> Check at every Index:
        int ans = 0 , n = nums.size();
        for (int i=1;i<n-1;i++)
        {
            int leftMax = nums[i];
            for (int j=0;j<i;j++)
            {
                leftMax = max(leftMax , nums[j]);
            }
            int rightMax = nums[i];
            for (int j=i+1;j<n;j++)
            {
                rightMax = max(rightMax , nums[j]);
            }
            
            ans += min (leftMax, rightMax) - nums[i];
        }
        return ans;
        
        
        
        
        
        
        //using Prefix and Suffix ArraY;
        int n = nums.size();
        vector<int>prefix(n, 0);
        prefix[0] = nums[0];
        
        for (int i=1;i<n;i++)         prefix[i] = max(prefix[i-1], nums[i]);
        
        vector<int>suffix(n, 0);
        suffix[n-1] = nums[n-1];
        
        for (int i=n-2;i>=0;i--)    suffix[i] = max(suffix[i+1], nums[i]);
        
        int ans = 0;
        for (int i=0;i<n;i++)     ans += min(suffix[i], prefix[i]) - nums[i];
        
        return ans;
    }
};



//Approch;3

#include<bits/stdc++.h>

using namespace std;
int trap(vector < int > & height) {
  int n = height.size();
  int left = 0, right = n - 1;
  int res = 0;
  int maxLeft = 0, maxRight = 0;
  while (left <= right) {
    if (height[left] <= height[right]) {
      if (height[left] >= maxLeft) {
        maxLeft = height[left];
      } else {
        res += maxLeft - height[left];
      }
      left++;
    } else {
      if (height[right] >= maxRight) {
        maxRight = height[right];
      } else {
        res += maxRight - height[right];
      }
      right--;
    }
  }
  return res;
}

int main() {
  vector < int > arr;
  arr = {0,1,0,2,1,0,1,3,2,1,2,1};
  cout << "The water that can be trapped is " << trap(arr) << endl;
}
Output: The water that can be trapped is 6

Time Complexity: O(N) because we are using 2 pointer approach.

Space Complexity: O(1) because we are not using anything extra.