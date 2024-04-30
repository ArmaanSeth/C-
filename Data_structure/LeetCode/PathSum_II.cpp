#include<iostream>
#include<vector>
using namespace std;
struct TreeNode 
    {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };
class Solution 
    {
    public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum, int curr_sum=0) 
        {
        vector<vector<int>> ans;
        if(root==NULL)
            {
            return ans;
            }
      /*  if(abs(curr_sum+root->val)>abs(targetSum))
            {
            return ans;
            }*/
        if(root->left==NULL && root->right==NULL)
            {
            curr_sum+=root->val;
            if(curr_sum!=targetSum)
                {
                return ans;
                }
            else
                {
                vector<int> k;
                k.push_back(root->val);
                ans.push_back(k);
                return ans;
                }
            }
        else
            {
            vector<vector<int>> m,n;
            curr_sum+=root->val;
            m=pathSum(root->left,targetSum,curr_sum);
            n=pathSum(root->right,targetSum,curr_sum);
            if(m.size()!=0)
                {
                for(int i=0;i<m.size();i++)
                    {
                    m[i].insert(m[i].begin(),root->val);
                    }
                ans.insert(ans.end(),m.begin(),m.end());
                }
            if(n.size()!=0)
                {
                for(int i=0;i<n.size();i++)
                    {
                    n[i].insert(n[i].begin(),root->val);
                    }
                ans.insert(ans.end(),n.begin(),n.end());
                }
            }
        return ans;
        }
    };
int main()
    {
    system("cls");
    TreeNode *head=new TreeNode,*l=new TreeNode;
    head->val=-2;
    head->right=NULL;
    l->val=-3;
    l->left=NULL;
    l->right=NULL;
    head->left=l;
    Solution obj;
    vector<vector<int>> ans=obj.pathSum(head,-5);
    for(int i=0;i<ans.size();i++)
        {
        for(int j=0;j<ans[i].size();i++)
            {
            cout<<ans[i][j]<<" ";
            }
        cout<<endl;
        }
    return 0;
    }
