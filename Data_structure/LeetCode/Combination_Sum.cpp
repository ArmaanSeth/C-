#include<iostream>
#include<vector>
using namespace std;
class Solution 
    {
    public:
    vector<vector<int>> recursion(vector<int> candidates,int target, int counter,int pos)
        {
        vector<vector<int>> ans;
        
        int l=candidates.size();
        for(int i=pos;i<l;i++)
            {
            if(counter+candidates[i]==target)
                {
                vector<vector<int>> p_ans;
                vector<int> k;    
                k.push_back(candidates[i]);
                p_ans.push_back(k);
                ans.insert(ans.end(),p_ans.begin(),p_ans.end());
                }
            else if(counter+candidates[i]<target)
                {
                vector<vector<int>> p_ans;
                p_ans=recursion(candidates,target,counter+candidates[i],i);
                int len=p_ans.size();
                if(len==0)
                    {
                    continue;
                    }
                for(int j=0;j<len;j++)
                    {
                    p_ans[j].insert(p_ans[j].begin(),candidates[i]);
                    }
                 ans.insert(ans.end(),p_ans.begin(),p_ans.end());
                }
            }
        return ans;
        }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
        {
        return recursion(candidates,target,0,0);
        }
    };
int main()
    {
    system("cls");
    vector<int> l={4,2,8};
    vector<vector<int>> k;
    Solution obj;
    k=obj.combinationSum(l,8);
    for(int i=0;i<k.size();i++)
        {
        for(int j=0;j<k[i].size();j++)
            {
            cout<<k[i][j]<<" ";
            }
        cout<<endl;
        }
    return 0;
    }