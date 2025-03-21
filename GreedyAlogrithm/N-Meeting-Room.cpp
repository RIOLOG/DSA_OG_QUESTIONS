class Solution {
  private:
    bool static cmp(vector<int> a, vector<int> b)
    {
        return a[1] < b[1];
    }
  public:
    int maxMeetings(vector<int>& star, vector<int>& en) 
    {
        vector<vector<int>>nums;
        
        for (int i=0;i<star.size();i++)
        {
            nums.push_back({star[i], en[i]});
        }
        
        sort(nums.begin(), nums.end(), cmp);
        int count = 1, ind = 1;
        int start = nums[0][0], end = nums[0][1];

        while(ind < nums.size())
        {
            if (end < nums[ind][0])
            {
                end = nums[ind][1];
                count += 1;
            }
            ind += 1;
        }
        //cout<<count<<endl;

        return count;
    }
};