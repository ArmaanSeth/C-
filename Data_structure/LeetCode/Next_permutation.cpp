#include<iostream>
#include<vector>
using namespace std;
class Solution 
    {
    public:
    void nextPermutation(vector<int>& nums) 
        {
        int i=nums.size()-1;
        while(i>0)
            {
            if(nums[i-1]>=nums[i])
                {
                i--;
                }
            else    
                {
                int k=nums.size()-1,n=nums[i-1];
                 
                vector<int> temp;
                while(nums[k]<=n)
                    {
                    temp.push_back(nums[k]);
                    nums.erase(nums.begin()+k);
                    k--;
                    }
                temp.push_back(n);
                temp.insert(temp.begin(),nums[k]);
                k--;
                while(k>=0 && k!=(i-1))
                    {
                    temp.push_back(nums[k]);
                    nums.erase(nums.begin()+k);
                    k--;
                    }
                nums.erase(nums.begin()+i);
                nums.insert(nums.begin()+i,temp.begin(),temp.end());
                nums.erase(nums.begin()+i-1);
                break;         
                }
            }
        if(i==0)
            {
            int j=nums.size()-1;
            while(i<=j)
                {
                int temp=nums[i];
                nums[i]=nums[j];
                nums[j]=temp;
                i++;
                j--;
                }
            }
        }
    };
int main()
    {
    system("cls");
    Solution obj;
    vector<int> k={1,1,5};
    obj.nextPermutation(k);
    for(int i=0;i<k.size();i++)
        {
        cout<<k[i]<<" ";
        }
    return 0;
    }