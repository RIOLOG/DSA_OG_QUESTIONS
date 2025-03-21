
class Solution {
  private:
    bool isCelebrity(int ind, vector<vector<int> >& mat)
    {
        int n = mat.size(), m = mat[0].size();
    
        for (int i=0;i< m;i++)
        {
            //cout<<mat[i][ind]<<" "<<i<<" "<<ind<<endl;
            if (mat[i][ind] != 1)   return false;
        }
        return true;
    }
  public:
    int celebrity(vector<vector<int> >& mat) 
    {
        int n = mat.size();
        int m = mat[0].size();
        
        for (int i=0;i<n;i++)
        {
            int notKnow = 0;
            for (int j=0;j<m;j++)
            {
                if (mat[i][j] == 1 and i != j)   notKnow += 1;
            }
            if (notKnow == 0)
            {
                //cout<<"notKnow "<<i<<endl;
                if (isCelebrity(i, mat))   return i;
            }
        }
        //cout<<"------------"<<endl;
        
        return -1;
    }
};