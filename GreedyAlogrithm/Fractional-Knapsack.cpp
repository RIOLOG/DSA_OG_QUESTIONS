static bool comp(vector<int>a, vector<int>b) {
    double v1 = (double) a[0] / (double) a[1];
    double v2 = (double) b[0] / (double) b[1];
    
    return v1 > v2;
}

class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) 
    {
        vector<vector<int>>arr;
        int n = val.size();
        
        for (int i=0;i<n;i++)
        {
            arr.push_back({val[i], wt[i]});
        }
        
        sort(arr.begin(), arr.end(), comp);
        
        double ans = 0.0;
        int weight = 0;
        
        for (int i=0;i<arr.size();i++)
        {
            if (arr[i][1] + weight <= capacity)
            {
                ans += arr[i][0];
                weight += arr[i][1];
            }
            else
            {
                double dummyValue = double(arr[i][0]) / double(arr[i][1]);
                double val = dummyValue * (capacity - weight);
                ans += val;
                break;
            }
        }
        return ans;
    }
};