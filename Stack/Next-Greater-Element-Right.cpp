// 1. NORMAL ARRAY

stack<int>st;
int n = nums2.size();
vector<int>nger(n, -1);

for (int i=n-1;i>=0;i--)
{
    if (st.empty() == true)   st.push(nums2[i]);
    else
    {
        while(!st.empty() and nums2[i] >= st.top())   st.pop();
        if (!st.empty())   nger[i] = st.top();
        st.push(nums2[i]);
    }
}

return ans;

//--------------------------------------------------------------

2. Cicular Array

#include<bits/stdc++.h>

using namespace std;
class Solution {
  public:
    vector < int > nextGreaterElements(vector < int > & nums) {
      int n = nums.size();
      vector < int > nge(n, -1);
      stack < int > st;
      for (int i = 2 * n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= nums[i % n]) {
          st.pop();
        }

        if (i < n) {
          if (!st.empty()) nge[i] = st.top();
        }
        st.push(nums[i % n]);
      }
      return nge;
    }
};