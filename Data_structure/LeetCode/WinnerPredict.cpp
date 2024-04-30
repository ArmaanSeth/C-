#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool score(vector<int> nums,int s,int turn)
        {
        int temp1,temp2;
        bool a=false,b=false;
        if(nums.size()==0)
            {
            if(s>=0)
                return true;
            return false;
            }
        if(turn==0)
            {
            temp1=s+nums[0];
            temp2=s+nums[nums.size()-1];
            vector<int> nums1,nums2;
            nums1=nums;
            nums2=nums;
            nums1.erase(nums1.begin());
            nums2.erase(nums2.begin()+nums2.size()-1);
            a=score(nums1,temp1,1);
            if(a==false)
                b=score(nums2,temp2,1);
            if(a==true || b==true)
                {
                return true;
                }
            }
        else
            {
            temp1=s-nums[0];
            temp2=s-nums[nums.size()-1];
            vector<int> nums1,nums2;
            nums1=nums;
            nums2=nums;
            nums1.erase(nums1.begin());
            nums2.erase(nums2.begin()+nums2.size()-1);
            a=score(nums1,temp1,0);
            if(a==true)
                b=score(nums2,temp2,0);
            if(a==false or b==false)
                {
                return false;
                }
            else
                {
                return true;
                }
            }
        return false;
        }
    bool PredictTheWinner(vector<int>& nums) 
    {
        int s=0;
        return score(nums,s,0);
    }
};
int main()
    {
    system("cls");
    Solution obj;
    vector<int> nums={2,4,55,6,8};
    bool ans=obj.PredictTheWinner(nums);
    if(ans)
        cout<<"True";
    else
        cout<<"False";
    return 0;
    }