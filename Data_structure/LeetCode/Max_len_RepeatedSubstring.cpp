#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) 
    {
    int max=0;
    int l1=nums1.size(),l2=nums2.size();
    int matrix[l1+1][l2+1];
    for(int i=0;i<=l1;i++)
        {
        for(int j=0;j<=l2;j++)
            {
            matrix[i][j]=0;
            }
        }
    for(int i=(l1-1);i>=0;i--)
        {
        for(int j=(l2-1);j>=0;j--)
            {
            if(nums2[j]==nums1[i])
                {
                /*int m=0,n=0,c=0;
                m=i;
                n=j;
                while(m>=0 && n>=0)
                    {
                    if(nums1[m]!=nums2[n])
                        {
                        break;
                        }
                    m--;
                    n--;
                    c++;
                    }
                if(c>max)
                    {
                    max=c;
                    }*/
                matrix[i][j]=matrix[i+1][j+1]+1;
                if(matrix[i][j]>max)
                    {
                        max=matrix[i][j];
                    }
                }
            }
        }
    return max;
    }
}; 
int main()
    {
    system("cls");
    Solution obj;
    vector<int> a={1,0,0,0,1},b={1,0,0,1,1};
    int i=obj.findLength(a,b);
    cout<<"\nMax="<<i;
    return 0;
    }