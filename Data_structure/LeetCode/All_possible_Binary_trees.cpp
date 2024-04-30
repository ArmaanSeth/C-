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
    vector<TreeNode*> allPossibleFBT(int n) 
        {
        vector<TreeNode*> c_node_list,list1,list2;
        if(n==1)
            {
            TreeNode *current_node=new TreeNode;
            current_node->val=0;
            current_node->left=NULL;
            current_node->right=NULL;
            c_node_list.push_back(current_node);
            return c_node_list;
            }
        n=n-1;
        int i=1,j=n-1;
        while(j>0)
            {
            
            if(i==2 || j==2)
                {
                i++;
                j--;
                continue;
                }
            list1=allPossibleFBT(i);
            list2=allPossibleFBT(j);
            for(int k=0;k<list1.size();k++)
                {
                for(int l=0;l<list2.size();l++)
                    {
                    TreeNode *current_node=new TreeNode;
                    current_node->val=0;
                    current_node->left=NULL;
                    current_node->right=NULL;
                    current_node->left=list1[k];
                    current_node->right=list2[l];
                    c_node_list.push_back(current_node);
                    }
                }
            i++;
            j--;
            }
        return c_node_list;
        }
    };
int main()
    {
    system("cls");
    Solution obj;
    vector<TreeNode*> k=obj.allPossibleFBT(7);
    cout<<k.size();
    return 0;
    }