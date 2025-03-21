//Approach1:

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
       //merging an ARRAY:
        vector<int>temp;
        for (int i=0;i<nums1.size();i++)   temp.push_back(nums1[i]);
        for (int i=0;i<nums2.size();i++)   temp.push_back(nums2[i]);
        
        sort(temp.begin(), temp.end());
        int length = temp.size();
        
        if (length % 2 != 0)   return (temp[length / 2]);

        int mid1 = (length/2) - 1;
        int mid2 = (length/2);

        return (temp[mid1] + temp[mid2]) / 2.0;
        
 
    }
};



// Approach:2:
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int n1 = nums1.size() , n2 = nums2.size();
        int n3 = n1 + n2;
        int element1 = -1, element2 = -1;
        int index1 = n3/2 , index2 = index1 - 1;
        int c = 0;
        
        int i = 0 , j = 0;
        while(i < n1 and j < n2)
        {
            if (nums1[i] < nums2[j])
            {
                if (c== index1)   element1 = nums1[i];
                if (c== index2)   element2 = nums1[i];
                c += 1;
                i += 1;
            }
            else
            {
                if (c== index1)   element1 = nums2[j];
                if (c== index2)   element2 = nums2[j];
                c += 1;
                j += 1;
            }
        }
        
        while(i < n1)
        {
            if (c== index1)   element1 = nums1[i];
            if (c== index2)   element2 = nums1[i];
            c += 1;
            i += 1;
        }
        while(j < n2)
        {
            if (c== index1)   element1 = nums2[j];
            if (c== index2)   element2 = nums2[j];
            c += 1;
            j += 1;
        }
        
        if (n3 % 2 != 0)   return double(element1);
        return double(double(element1+element2)  / 2.0 );
        
    }
};