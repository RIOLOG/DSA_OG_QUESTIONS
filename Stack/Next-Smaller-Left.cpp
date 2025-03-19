vector<int> leftSmaller(int n, int nums[])
{
    vector<int>nsel(n, -1);
    stack<int>st;
    
    for (int i=0;i<n;i++)
    {
        if (st.empty())   st.push(nums[i]);
        else
        {
            while(!st.empty() and st.top() >= nums[i])   st.pop();
            if (!st.empty())   nsel[i] = st.top();
            st.push(nums[i]);
        }
    }
    
    return nsel;
}

